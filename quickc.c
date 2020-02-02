#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 1024*512
long int A[n],i;


//Function for initializing the array with random values 
void initialize(){        
    for(i=0;i<n;i++){
        A[i]=rand()%10;        
    }
}


//Swapping of elements during parititon 
void swap(long int *x,long int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}


//Partition method finds out the actual position of pivot element
int partition(long int A[],int l,int h)
{
    int pivot=A[l];
    int i=l,j=h;
    do
    {
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);
        if(i<j)swap(&A[i],&A[j]);
    }while(i<j);
    swap(&A[l],&A[j]);
return j;
}

//Main method to calculate the Left and Right Partition seperately
void QuickSort(long int A[], int l, int h) 
{ 
  int stack[h - l + 1]; 

  int top = -1; 

  stack[++top] = l; 
  stack[++top] = h; 

  while (top >= 0) { 
    h = stack[top--]; 
    l = stack[top--]; 

    int p = partition(A, l, h); 

    if (p - 1 > l) { 
      stack[++top] = l; 
      stack[++top] = p - 1; 
    } 

    if (p + 1 < h) { 
      stack[++top] = p + 1; 
      stack[++top] = h; 
    } 
  } 
}

//Function to print the final Result 
void printArr(long int A[], int N) 
{ 
  int i; 
  for (i = 0; i < N; ++i) 
    printf("%d ", A[i]); 
} 


int main()
{
    /*Initialize the clock*/
    clock_t t;
    srand(time(0));
    initialize();
    t = clock();
    //Function Call 
    QuickSort(A,0,n);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("took %f seconds to execute \n", time_taken);
    printArr(A,n);	         
    return 0;
}