#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include<math.h>
int num_nearest =0;
int num_points_by_num_threads=0;
double** nearest=NULL;
double** points=NULL;
double* source_point=NULL;

 //gcc -pthread -o Assgn1Src-CS20BTECH11035 Assgn1Src-CS20BTECH11035.c -lm
//function to find distance between one point and source point
 double find_distance(double* destination_point)
 {  
     double x=pow(source_point[0]-destination_point[0],2);
     double y=pow(source_point[1]-destination_point[1],2);
     double distance=pow(x+y,0.5);
     return distance;
 }
//finds nearest points in a subset  of points
void find_nearest(int start,int end)
{   int z=num_nearest;
   double smallest_distance=find_distance(points[start]);
   for(int i=start;i<=end;i++)
   {
       if(find_distance(points[i])<smallest_distance)
       { smallest_distance=find_distance(points[i]);
          nearest[z][0]=points[i][0];
          nearest[z][1]=points[i][1];
          num_nearest=z+1;
       }

       else if(find_distance(points[i])==smallest_distance)
       { 
          nearest[num_nearest][0]=points[i][0];
          nearest[num_nearest][1]=points[i][1];
          num_nearest++;
       }
   }
   
}
//finds nearest point in list of points shortlisted by threads
void nearest_point()
{
    int z=0;
    double** nearest2=(double**)malloc(sizeof(nearest));
   double smallest_distance=find_distance(nearest[0]);
   for(int i=0;i<num_nearest;i++)
   {
      nearest2[i]=(double*)malloc(2*sizeof(double));
       if(find_distance(nearest[i])<smallest_distance)
       { smallest_distance=find_distance(nearest[i]);
          nearest2[0][0]=nearest[i][0];
          nearest2[0][1]=nearest[i][1];
          z=1;
       }

       else if(find_distance(nearest[i])==smallest_distance)
       { 
          nearest2[z][0]=nearest[i][0];
          nearest2[z][1]=nearest[i][1];
          z++;
       }
   }
   num_nearest=z;
   for(int i=0;i<num_nearest;i++)
   {
       for(int j=0;j<2;j++)
       {
           nearest[i][j]=nearest2[i][j];
       }
   }
}
//prints nearest points
void print_nearest()
{  printf("nearest points\n");
    for(int i=0;i<num_nearest;i++)
    {
       printf("(%lf,%lf)  ",nearest[i][0],nearest[i][1]);
    }
    printf("\n");
}
//multithreads are implemented in below function
void* multithread(void* arg)
{   static int index=0;
    int a=num_points_by_num_threads;
    int start=index*a;
    int end=start+a-1;
    index++;
    find_nearest(start,end);
    
}

int main()
 {   
     source_point=(double*)malloc(2*sizeof(double));
     int num_threads,num_points;
     //input source point
     printf("Enter source point in the format a,b  ,Ex:1,1\n");
     scanf( "%lf,%lf", &source_point[0], &source_point[1]);
     //input number of threads
     printf("Enter number of threads\n");
     scanf("%d",&num_threads) ;
     //input number of points
     printf("Enter number of points\n");
     scanf("%d",&num_points);

     num_points_by_num_threads=num_points/num_threads;

    
     points=(double**)malloc(num_points*2*sizeof(double));
     nearest=(double**)malloc(num_points*2*sizeof(double));

     printf("Enter points in the format a,b  ,Ex:1,1\n");
  //input points
     for(int i=0;i<num_points;i++)
     { 
         points[i]=(double*)malloc(2*sizeof(double));
       nearest[i]=(double*)malloc(2*sizeof(double));
        printf("Enter point %d ",i+1);
        scanf("%lf,%lf",&points[i][0],&points[i][1]);
     }
     
    clock_t start,end;
    start=clock();
     pthread_t thread_list[num_threads];
//threads creation
     for (int i=0;i<num_threads;i++)
     {
        pthread_create(&thread_list[i],NULL,multithread,(void*)NULL);
     }
     for (int i =0;i<num_threads;i++)
     {
      pthread_join(thread_list[i], NULL);
     }
     nearest_point();
     end=clock();
    double time_taken=(double)(end-start)*pow(10,6)/CLOCKS_PER_SEC;
    printf("Time taken=%lf microseconds\n",time_taken);
     print_nearest();
     
     
     return 0;
 }