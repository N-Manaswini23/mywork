#include <iostream>
#include <fstream>
#include<string.h>
#include<math.h>
//g++ -o Assgn3-EDF-CS20BTECH11035 Assgn3-EDF-CS20BTECH11035.cpp
class Process
{
   public:
   char Pi[100];
   int t;
   int p;
   int k;
   int num_times_executed;
   int waiting_time;
};

typedef class Process process;
//returns toatl number of processes including repititions
int total_process(process *P,int n)
{ int num_process=0;
    for(int i=0;i<n;i++)
    {
        num_process+=P[i].k;
    }
    return num_process;
}
//returns array of class process which contain process in non-decreasing order of period.
process* priority(process* P,int i,int n)
{ 
    int period=P[i].p;
    int execute_time=P[i].t;
    int num_times=P[i].k;
    char pid[100];
    strcpy(pid,P[i].Pi);
    int j=i-1;
    if(i==0)
    {   P[0].num_times_executed=0;
        P[0].waiting_time=0;
        return P;
    }
    else 
    {
    while(period<P[j].p&&j>=0)
    {
      P[j+1]=P[j];
        j--;
    }
    }
    P[j+1].p=period;
    P[j+1].t=execute_time;
    P[j+1].k=num_times;
    strcpy(P[j+1].Pi,pid);
    P[j+1].num_times_executed=0;
    P[j+1].waiting_time=0;
    return P;
}
//returns 0 if all processes completed execution including repititions
//else returns -1
int checkcomplete(Process *P,int n)
{
   for(int i=0;i<n;i++)
   {
       if(P[i].num_times_executed!=P[i].k)
       {
           return -1;
       }
   }
   return 0;
}
//returns priority of next process to be executed. 
int nextprocess(process* P,int t,int n)
{
    int next=0;
    while(P[next].k==P[next].num_times_executed&&next<n)
    {
        next++;
    }
    while(P[next].p*(P[next].num_times_executed)>t&&next<n)
    {
      next++;
    }
    if(next!=n)
    {
     for(int i=0;i<n;i++)
    { 

         if(P[i].k>P[i].num_times_executed)
    {
      if(P[i].p*(P[i].num_times_executed)<=t&&P[next].p*(P[next].num_times_executed+1)>P[i].p*(P[i].num_times_executed+1))
      {
        next=i;
      }
    }
    }
    if(P[next].p*(P[next].num_times_executed)<=t&&P[next].k>P[next].num_times_executed)
    {
      return next;
    }
    }
    next=0;
     while(P[next].k==P[next].num_times_executed&&next<n)
    {
        next++;
    }
    if(next!=n)
    {
    for(int i=0;i<n;i++)
    { 

         if(P[i].k>P[i].num_times_executed)
    {
        if(P[i].p*(P[i].num_times_executed)>t&&P[next].p*(P[next].num_times_executed)>P[i].p*(P[i].num_times_executed))
        {
              next=i;
        }
    }
    }
      if(P[next].p*(P[next].num_times_executed)>t&&P[next].k>P[next].num_times_executed)
    {
      return next;
    }
    }
    return -1;
}

//This schedules EDF. This returns time at which process with given priority completed execution.
//Preemptions are also scheduled in this function
int edfscheduling(Process *P,int priority,int time_from,int time_to,int status,int n,int waiting_time_accept)
{ std::ofstream file1;
  file1.open("EDF-Log.txt",std::ios::app);
  std::string s;
  static int deadline_miss=0;
  int resume_time=time_from;
  int t=time_to-time_from;
  int time=time_from;
  int stats=0;
  int i=0;
  if(status==-1)
  {status=0;
      for(int y=0;y<n;y++)
      {//writes to file RMS-Log.txt about entry of all processes.
      file1<<"Process"<<P[y].Pi<<" Processing time="<<P[y].t<<" deadline="<<P[y].p<<" period="<<P[y].p<<" joined the system at time 0\n";
      }
      
  }
  
  if(waiting_time_accept==1)//updates waiting time if it is not updated
  {P[priority].waiting_time+=time_from- P[priority].p*(P[priority].num_times_executed);}
  
    {
      int prempt=priority;
   for(int j=0;j<n;j++)
       {//checks if any process preempts before this process starts.
           if(P[j].p*(P[j].num_times_executed+1)<P[prempt].p*(P[prempt].num_times_executed+1)&&P[j].k>P[j].num_times_executed&&P[j].p*(P[j].num_times_executed)<=time_from)
           {
              prempt=j;
           }
       }
  if(prempt!=priority)
  {
    resume_time=edfscheduling(P,prempt,time_from,time_from+P[prempt].t,1,n,1);
    time=edfscheduling(P,priority,resume_time,resume_time+t,1,n,0);
    P[priority].num_times_executed--;
  }
  else if(prempt==priority&& P[priority].k>P[priority].num_times_executed)
  { time=time_to;
 s=" started executing at t=";
      s=P[priority].Pi+s+std::to_string(time_from);
      file1<<s<<std::endl;//writes to file when execution started.
 for(i=time_from+1;i<time_to;i++)
    {
       for(int j=0;j<n;j++)
       {//preemptions
           if(P[j].p*(P[j].num_times_executed+1)<P[prempt].p*(P[prempt].num_times_executed+1)&&P[j].k>P[j].num_times_executed&&P[j].k>P[j].num_times_executed&&P[j].p*(P[j].num_times_executed)<=i)
           {
               prempt=j;
               stats=1;
           }
       }
       if(stats==1)
      {
        break;
      }
    }
    stats=0;
    if(prempt!=priority)
    {
        s=" preempted by process ";
        s=P[priority].Pi+s+P[prempt].Pi+" at t="+std::to_string(i)+". Remaining time="+std::to_string(time_to-i);
        file1<<s<<std::endl;//write to file when preempted
        resume_time=edfscheduling(P,prempt,i,i+P[prempt].t,1,n,1);
        P[priority].waiting_time+=resume_time-i;
       time=edfscheduling(P,priority,resume_time,resume_time+t-i+time_from,1,n,0);
       P[priority].num_times_executed--;
       stats=1;
    }
    
  }
    }
    P[priority].num_times_executed++;
    if(stats==0)
    { 
    s=" finished executing at t=";
    s=P[priority].Pi+s+std::to_string(time);
    file1<<s<<std::endl;//writes to file when process finishes
    if(time>P[priority].p*(P[priority].num_times_executed))
    {
        deadline_miss++;
    }
    }
    if(status==0&&checkcomplete(P,n)==-1)
    {//assigns next process to execute
        int x=nextprocess(P,time,n);
    if(P[x].k>P[x].num_times_executed)
     {
       if(P[x].p*(P[x].num_times_executed)<=time)
       {   
           time=edfscheduling(P,x,time,time+P[x].t,0,n,1);
       }
       else
       { //if next process takes time to start, cpu idle time starts
           s="CPU idle until ";
           s=s+std::to_string(P[x].p*(P[x].num_times_executed)-1);
           file1<<s<<std::endl;
           time=edfscheduling(P,x,P[x].p*(P[x].num_times_executed),P[x].p*(P[x].num_times_executed)+P[x].t,0,n,1);
           }
       }
    }
   file1.close();
   if(checkcomplete(P,n)==0)
   { //updates file EDF-Stats.txt
std::ofstream file2;
file2.open("EDF-Stats.txt");
file2<<"Total number of processes: "<<total_process(P,n)<<std::endl;
file2<<"number of processes successful: "<<total_process(P,n)-deadline_miss<<std::endl;
file2<<"number of processes failed: "<<deadline_miss<<std::endl;
double avg_waiting_time=0;
for(int y=0;y<n;y++)
{   avg_waiting_time+=(double)P[y].waiting_time/(double)P[y].k;
    file2<<"average waiting time for "<<P[y].Pi<<" is "<<(double)P[y].waiting_time/(double)P[y].k<<std::endl;
}
avg_waiting_time=avg_waiting_time/(double)n;
file2<<"average waiting time is "<<avg_waiting_time<<std::endl;

file2.close();
   }
  return time;
}




int main()
{
    std::ifstream file;
    file.open("inp-params.txt");
    int n;
    file>>n;
    process *P=(process*)std::malloc(n*sizeof(process));
    int i=0;
    char x[100];
    while(file&&i<n)
    { 
        file>>x;
        strcpy(P[i].Pi,x);
        file>>P[i].t;
        file>>P[i].p;
        file>>P[i].k;
        P=priority(P,i,n);
        i++;
    }
    file.close();
    std::ofstream file4;
    file4.open("EDF-Log.txt");
    
    file4.close();
    

    int time=0;
    time=edfscheduling(P,0,0,P[0].t,-1,n,1);
    


    return 0;
}