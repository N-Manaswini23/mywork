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
//g++ -pthread -o SRCAssgn4-CAS-CS20BTECH11035 SRCAssgn4-CAS-CS20BTECH11035.cpp
int n,k,lam1,lam2;
int pro=0;
clock_t waiting_time=0;
clock_t worst_waiting_time=0;
time_t st;
tm *exitTime;
std::default_random_engine generator;

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
while(compare_and_swap2(&lock2,0,1)!=0){sleep(1);
  ;}


int temp = *value;
if(temp==1){lock2=0;
    return 1;}
if (*value == expected)
{*value = new_value;}
lock2=0;
return temp;
}

void entry_sec()
{ 
   while (compare_and_swap(&lock,0,1)!=0) 
    { 
      ;
      }
}
void exit_sec()
{
while(compare_and_swap2(&lock2,0,1)!=0){
  ;}
  lock=0;
  lock2=0;
  st=time(0);
  exitTime = localtime(&st);
  
  
    
}



void testCS(int id)
{ 

    time_t request,entry,exit;
clock_t start,end;
tm *reqEnterTime;
tm *actEnterTime;
std::exponential_distribution<double> distribution1 (1/(double)lam1);
std::exponential_distribution<double> distribution2 (1/(double)lam2);
  for(int i=0;i<k;i++)
  {std::ofstream file1;
file1.open("CS20BTECH11035_logCAS.txt",std::ios::app);
    request = time(0);
    start=clock();
    reqEnterTime = localtime(&request);
   //while(compare_and_swap2(&lock3,0,1)!=0){;}
    file1<<i+1<<"th process CS request at "<< reqEnterTime->tm_hour << ":"<<reqEnterTime->tm_min << " by thread "<<id<<"\n";
    
    entry_sec();
    entry = time(0);
    end=clock();
    waiting_time+=end-start;
    if(end-start>worst_waiting_time)
    {
        worst_waiting_time=end-start;
    }
    actEnterTime = localtime(&entry);
    file1<<i+1<<"th process CS entry at "<< actEnterTime->tm_hour << ":"<<actEnterTime->tm_min <<" by thread "<<id<< "\n";
   
    double t1 = distribution1(generator);
    sleep(t1);
    /* critical section */ 

    exit_sec();
    file1<<i+1<<"th process CS exit at "<< exitTime->tm_hour << ":"<<exitTime->tm_min << " by thread "<<id<<"\n";
    
    double t2 = distribution2(generator);
    //lock3=0;
    sleep(t2);
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
    //std::cout<<"n="<<n<<" k="<<k<<" lam1="<<lam1<<" lam2="<<lam2<<"\n";
    std::ofstream file2;
file2.open("CS20BTECH11035_logCAS.txt");
file2.close();
    std::vector<std::thread> threads;
  for (int i=1; i<=n; ++i) 
  {
      threads.push_back(std::thread(testCS,i));
      }
  for (auto& th : threads) {
      th.join();
      }
std::cout<<"avg waiting_time="<<(float)waiting_time/(CLOCKS_PER_SEC*n*k)<<std::endl;
std::cout<<"worst waiting time= "<<(float)worst_waiting_time/(CLOCKS_PER_SEC)<<std::endl;
    return 0;
} 