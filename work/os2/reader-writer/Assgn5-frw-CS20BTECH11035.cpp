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
#include<semaphore.h>
#include<stdio.h>
//g++ -pthread -o Assgn5-frw-CS20BTECH11035 Assgn5-frw-CS20BTECH11035.cpp
int nw,nr,kw,kr,ucs,urem;
clock_t waiting_timew=0;
clock_t waiting_timer=0;
clock_t worst_waiting_timew=0;
clock_t worst_waiting_timer=0;
std::default_random_engine generator;
int read_count=0;
sem_t rw_mutex{1},mutex{1},order{1};
void writer(int id)
{ 
time_t request,entry,exit;
clock_t start,end;
tm *reqEnterTime;
tm *actEnterTime;
tm *exitTime;
std::exponential_distribution<double> distribution1 (1/(double)ucs);
std::exponential_distribution<double> distribution2 (1/(double)urem);
  for(int j=0;j<kw;j++)
  {std::ofstream file1;
file1.open("FairRW-log.txt",std::ios::app);
    request = time(0);
    start=clock();
    reqEnterTime = localtime(&request);
    file1<<j+1<<"th CS request by writer thread "<<id<<" at "<< reqEnterTime->tm_hour << ":"<<reqEnterTime->tm_min <<":"<<reqEnterTime->tm_sec <<"\n";
   
   sem_wait(&order);
    sem_wait(&rw_mutex);
     sem_post(&order);
    entry = time(0);
    end=clock();
    waiting_timew+=end-start;
    if((end-start)>worst_waiting_timew)
    {
        worst_waiting_timew=end-start;
    }
    actEnterTime = localtime(&entry);
    file1<<j+1<<"th CS entry by writer thread "<<id <<" at "<< actEnterTime->tm_hour << ":"<<actEnterTime->tm_min <<":"<<actEnterTime->tm_sec << "\n";
    
    double randCStime= distribution1(generator);
    sleep(randCStime);
    /* writing */ 

   exit = time(0);
   exitTime = localtime(&exit);
    file1<<j+1<<"th CS exit by writer thread "<<id<<" at "<< exitTime->tm_hour << ":"<<exitTime->tm_min <<":"<<exitTime->tm_sec <<"\n";
    sem_post(&rw_mutex);
   
    double randRemtime = distribution2(generator);
 
    sleep(randRemtime);
    file1.close(); 
  }
}


void reader(int id)
{ sem_t lock1,lock2;
time_t request,entry,exit;
clock_t start,end;
tm *reqEnterTime;
tm *actEnterTime;
tm *exitTime;
std::exponential_distribution<double> distribution1 (1/(double)ucs);
std::exponential_distribution<double> distribution2 (1/(double)urem);
  for(int i=0;i<kr;i++)
  {std::ofstream file1;
file1.open("FairRW-log.txt",std::ios::app);
    request = time(0);
    start=clock();
    reqEnterTime = localtime(&request);
    file1<<i+1<<"th CS request by reader thread "<<id<<" at "<< reqEnterTime->tm_hour << ":"<<reqEnterTime->tm_min <<":"<<reqEnterTime->tm_sec <<"\n";
   
      sem_wait(&order);
    sem_wait(&mutex);         
  
    read_count++;     
    if (read_count == 1) 
      {sem_wait(&rw_mutex);  }   
    
    sem_post(&order);
    sem_post(&mutex);
    end=clock();
    waiting_timer+=end-start;
    if(end-start>worst_waiting_timer)
    {
        worst_waiting_timer=end-start;
    }

     
    entry = time(0);  
    actEnterTime = localtime(&entry);
    file1<<i+1<<"th CS entry by reader thread "<<id <<" at "<< actEnterTime->tm_hour << ":"<<actEnterTime->tm_min <<":"<<actEnterTime->tm_sec << "\n";
  
    double randCStime = distribution1(generator);
    sleep(randCStime);
    /* reading */ 


    sem_wait(&mutex);       
  
    read_count--;         
    if (read_count == 0)  
       { sem_post(&rw_mutex); }  
    
    
   exit = time(0);
   exitTime = localtime(&exit);
    file1<<i+1<<"th CS exit by reader thread "<<id<<" at "<< exitTime->tm_hour << ":"<<exitTime->tm_min <<":"<<exitTime->tm_sec <<"\n";
  
    sem_post(&mutex);
    double randRemtime= distribution2(generator);
    sleep(randRemtime);
    file1.close(); 
  }
  
}

int main()
{
    std::ifstream file;
    file.open("inp-params.txt");
    
        file>>nw;
        file>>nr;
        file>>kw;
        file>>kr;
        file>>ucs;
        file>>urem;
        
    
    file.close();
    //std::cout<<"nw="<<nw<<" nr="<<nr<<" kw="<<kw<<" kr="<<kr<<" ucs="<<ucs<<" urem="<<urem<<"\n";
    std::ofstream file2;
file2.open("FairRW-log.txt");
file2.close();
 read_count=0;
 std::vector<std::thread> threadsw;
  for (int i=1; i<=nw; ++i) 
  {
      threadsw.push_back(std::thread(writer,i));
      }
    std::vector<std::thread> threadsr;
  for (int i=1; i<=nr; ++i) 
  {
      threadsr.push_back(std::thread(reader,i));
      }
      
  for (auto& th : threadsw) {
      th.join();
      }
  for (auto& th : threadsr) {
      th.join();
      }
std::ofstream file3;
file3.open("Average_time.txt");
file3.close();
std::ofstream file4;
file4.open("Average_time.txt",std::ios::app);
file4<<"average waiting time of writers ="<<(double)waiting_timew*1000/(double)(CLOCKS_PER_SEC*nw*kw)<<std::endl;
file4<<"average waiting time of readers ="<<(double)waiting_timer*1000/(double)(CLOCKS_PER_SEC*nr*kr)<<std::endl;
file4<<"worst waiting time of writers ="<<(float)worst_waiting_timew*1000/(CLOCKS_PER_SEC)<<std::endl;
file4<<"worst waiting time of readers ="<<(float)worst_waiting_timer*1000/(CLOCKS_PER_SEC)<<std::endl;
file4.close();

return 0;
} 