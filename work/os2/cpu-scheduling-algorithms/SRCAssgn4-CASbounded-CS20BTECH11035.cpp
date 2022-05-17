#include <iostream>
#include <fstream>
#include<string.h>
#include <pthread.h>
#include<math.h>
#include<time.h>
#include<unistd.h>
#include <ctime>
#include<random>
#include<chrono>
#include<thread>
//g++ -pthread -o SRCAssgn4-CASbounded-CS20BTECH11035 SRCAssgn4-CASbounded-CS20BTECH11035.cpp
int n,k,lam1,lam2;
int i=0;
clock_t waiting_time=0;
clock_t worst_waiting_time=0;
time_t st;
int j=0;
std::default_random_engine generator;
int *waiting;
int lock=0;
int lock1=0;
int lock2=0;
int lock3=0;

int compare_and_swap2(int *value, int expected, int new_value)
 {
int temp = *value;
if(temp==1){return 1;}
if (*value == expected)
{*value = new_value;}
return temp;
}

int compare_and_swap(int *value, int expected, int new_value)
 {
if(lock2==1){return 1;}
int temp = *value;
if(temp==1){
    return 1;}
if (*value == expected)
{*value = new_value;}

return temp;
}

void entry_sec(int id)
{ int key=1;
  while (waiting[id]==1 && key == 1)
  {
key = compare_and_swap(&lock,0,1);
  }
  waiting[id]=0;
}
void exit_sec(int id)
{
while(compare_and_swap2(&lock2,0,1)!=0){
  ;}

  int j = (id + 1) % n;
while ((j != id) && waiting[j]==0)
{
  j = (j + 1) % n;
}
//std::cout<<"id="<<id<<"j="<<j<<std::endl;
if (j == id)
{lock = 0;
lock2=0;}
else{lock2=0;
waiting[j] = 0;}
    
}



void testCS(int id)
{
   
    waiting[id]=0;

time_t request,entry,exit;
clock_t start,end;
tm *reqEnterTime;
tm *actEnterTime;
tm *exitTime;
std::exponential_distribution<double> distribution1 (1/(double)lam1);
std::exponential_distribution<double> distribution2 (1/(double)lam2);

  for(int i=0;i<k;i++)
  {std::ofstream file1;
file1.open("CS20BTECH11035_logCASbounded.txt",std::ios::app);
    request=time(0);
    start=clock();
    reqEnterTime = localtime(&request);
    waiting[id]=1;
   
    file1<<i+1<<"th process CS request at "<< reqEnterTime->tm_hour << ":"<<reqEnterTime->tm_min << " by thread "<<id<<"\n";
    
   //while(compare_and_swap2(&lock3,0,1)!=0){;}
    entry_sec(id);
    entry=time(0);
    end=clock();
    waiting_time+=end-start;
    
    if(end-start>worst_waiting_time)
    {
        worst_waiting_time=end-start;
    }
    j++;
    
    actEnterTime = localtime(&entry);
    file1<<i+1<<"th process CS entry at "<< actEnterTime->tm_hour << ":"<<actEnterTime->tm_min <<" by thread "<<id<< "\n";
    
    double t1 = distribution1(generator);
    sleep(t1);
    /* critical section */ 
      //lock3=0;
    exit_sec(id);
    exit=time(0);
    exitTime = localtime(&exit);
    file1<<i+1<<"th process CS exit at "<< exitTime->tm_hour << ":"<<exitTime->tm_min <<" by thread "<<id<<"\n";
   
  
    double t2 = distribution2(generator);
    sleep(t2);
  
    /* remainder section */ 
     file1.close();
  }
 
}

int main()
{
    std::ifstream file;
    file.open("inp-params.txt");
    
        file>>n;
        file>>k;
        file>>lam1;
        file>>lam2;
        
    
    file.close();
    std::cout<<"n="<<n<<" k="<<k<<" lam1="<<lam1<<" lam2="<<lam2<<"\n";
    std::ofstream file2;
file2.open("CS20BTECH11035_logCASbounded.txt");
file2.close();
waiting=(int*)malloc(n*sizeof(int));
    pthread_t thread_list[n];
   std::vector<std::thread> threads;
  for (int i=0; i<n; ++i) {threads.push_back(std::thread(testCS,i));}
  for (auto& th : threads) th.join();

//std::cout<<"j="<<j<<std::endl;
std::cout<<"avg waiting_time="<<(double)waiting_time/(double)(CLOCKS_PER_SEC*n*k)<<std::endl;
std::cout<<"worst waiting time= "<<(float)worst_waiting_time/(CLOCKS_PER_SEC)<<std::endl;
    return 0;
} 