#include <iostream>     
#include <atomic>         
#include <thread>       
#include <vector>       
#include <sstream> 
#include <fstream>
#include<string.h>
#include <pthread.h>
#include<math.h>
#include<time.h>
#include<unistd.h>
#include <ctime>
#include<random>
#include<chrono>
std::atomic_flag lock_ts= ATOMIC_FLAG_INIT;
std::stringstream stream;
std::atomic_flag lock = ATOMIC_FLAG_INIT;



int n,k,lam1,lam2;
int pro=0;
bool lock2=0;
clock_t waiting_time=0;
clock_t worst_waiting_time=0;
bool lock1=0;
bool lock3=0;
time_t st;
std::default_random_engine generator;

//bool lock;
 
 void entry_sec(){
while (lock_ts.test_and_set()){;}
}
void exit_sec()
{
  lock_ts.clear();
}
void testCS(int id)
{ time_t request,entry,exit;
clock_t start,end;
tm *reqEnterTime;
tm *actEnterTime;
tm *exitTime;
std::exponential_distribution<double> distribution1 (1/(double)lam1);
std::exponential_distribution<double> distribution2 (1/(double)lam2);

  for(int i=0;i<k;i++)
  {std::ofstream file1;
file1.open("CS20BTECH11035_logTAS.txt",std::ios::app);
    request = time(0);
    start=clock();
    reqEnterTime = localtime(&request);
    while (lock.test_and_set()){;}
    file1<<i+1<<"th process CS request at "<< reqEnterTime->tm_hour << ":"<<reqEnterTime->tm_min <<" by thread "<<id<<"\n";
   
   lock.clear();
    entry_sec();
  

    /* do nothing */ 
    entry = time(0);
    end=clock();
    waiting_time+=end-start;
    if(end-start>worst_waiting_time)
    {
        worst_waiting_time=end-start;
    }
    actEnterTime = localtime(&entry);
    while (lock.test_and_set()){;}
    file1<<i+1<<"th process CS entry at "<< actEnterTime->tm_hour << ":"<<actEnterTime->tm_min << " by thread "<<id<< "\n";
    lock.clear();
   
    double t1 = distribution1(generator);
    sleep(t1);
    /*critical section*/
    exit_sec();
    exit= time(0);
    exitTime= localtime(&exit);
    while (lock.test_and_set()){;}
    file1<<i+1<<"th process CS exit at "<< exitTime->tm_hour << ":"<<exitTime->tm_min << " by thread "<<id<<"\n";
    lock.clear();
   
    pro++;
    double t2 = distribution2(generator);
  
    sleep(t2);
   file1.close();
    /* remainder section */ 
  }
 
}


int main ()
{



   std::ifstream file;
    file.open("inp-params.txt");
    //while(file&&i<n)
    
        file>>n;
        file>>k;
        file>>lam1;
        file>>lam2;
        
    
    file.close();
    std::cout<<"n="<<n<<" k="<<k<<" lam1="<<lam1<<" lam2="<<lam2<<"\n";
    std::ofstream file2;
file2.open("CS20BTECH11035_logTAS.txt");
file2.close();
    pthread_t thread_list[n];
//threads creation

    std::vector<std::thread> threads;
  for (int i=1; i<=n; ++i) {threads.push_back(std::thread(testCS,i));}
  for (auto& th : threads) th.join();
std::cout<<"pro="<<pro<<std::endl;
std::cout<<"waiting_time="<<(float)waiting_time/(CLOCKS_PER_SEC*pro)<<std::endl;
std::cout<<"worst waiting time= "<<(float)worst_waiting_time/(CLOCKS_PER_SEC)<<std::endl;
    return 0;
}