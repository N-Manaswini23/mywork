#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int* Insertionsort(int *array,int N)
{ int comparisions=0;
    for(int i=0;i<N-1;i++)
    {
        int j=i;
        int temp=array[i+1];
        comparisions=comparisions+1;
        while(j>=0&&array[j]>temp)
        {
           array[j+1]=array[j];
           j=j-1;
           if(j>=0)
           {
           comparisions=comparisions+1;
           }
        }
        array[j+1]=temp;
    }
    printf("number of comparisions=%d\n",comparisions);
    return array;
}
void printarr(int *array,int N)
{
    for(int i=0;i<N;i++)
    {
        printf("%d  ",array[i]);
    }
    printf("\n");
}
void generate_increasingorder(int N,int a,int r)
{
    int *arr=(int*)malloc(N*sizeof(int));
    for(int i=0;i<N;i++)
    {
        int j=(int)pow(r,i);
        arr[i]=a*j;
    }
    printf("before insertion sort\n");
    printarr(arr,N);
    printf("after insertion sort\n");
    arr=Insertionsort(arr,N);
    printarr(arr,N);
    //return arr;
}

void generate_decreasingorder(int N,int a,int r)
{
    int *arr=(int*)malloc(N*sizeof(int));
    for(int i=0;i<N;i++)
    {
        int j=(int)pow(r,N-i-1);
        arr[i]=a*j;
    }
    printf("before insertion sort\n");
    printarr(arr,N);
    printf("after insertion sort\n");
    arr=Insertionsort(arr,N);
    printarr(arr,N);
    //return arr;
}

void generate_randomorder(int N,int a,int r)
{   srand(0);
    int *arr=(int*)malloc(N*sizeof(int));
    for(int i=0;i<N;i++)
    {
        arr[i]=-1;
    }
    for(int i=0;i<N;i++)
    {
        /*if(i%2==0)
        {int j=(int)pow(r,i+1);
        arr[i]=a*j;}
        else{int j=(int)pow(r,i-1);
        arr[i]=a*j;}*/
        int j=rand()%N;
        while(arr[j]!=-1)
        {
            j=rand()%N;
        }
        int k=(int)pow(r,i);
        arr[j]=a*k;
    }
    printf("before insertion sort\n");
    printarr(arr,N);
    printf("after insertion sort\n");
    arr=Insertionsort(arr,N);
    printarr(arr,N);
    //return arr;
}
int main()
{
    int N,a,r;
    printf("Enter N(number of terms)\n");
    scanf("%d",&N);
    printf("Enter a(scale factor)\n");
    scanf("%d",&a);
    printf("Enter r(common ratio)\n");
    scanf("%d",&r);
    //int *arr=(int*)malloc(N*sizeof(int));
    printf("INCREASING ORDER\n");
    generate_increasingorder(N,a,r);
    printf("\n");
    printf("DECREASING ORDER\n");
    generate_decreasingorder(N,a,r);
    printf("\n");
    printf("RANDOM ORDER\n");
    generate_randomorder(N,a,r);
    printf("\n");
    return 0;
}