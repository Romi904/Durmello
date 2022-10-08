
#include <iostream>
using namespace std;


void insertMax(int A[],int n)
{
    int i=n;
    int temp = A[n];
    
    while(i>1 && temp>A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;
        
    }
    A[i]=temp;
}
void insertMin(int A[],int n)
{
    int i=n;
    int temp = A[n];
    
    while(i>1 && temp<A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;
        
    }
    A[i]=temp;
}

int Delete(int A[],int n)
{
    int x,i,j,val,temp;
    
    val = A[1];
    x=A[n];
    A[1]=A[n];
    i=1;
    j=2*i;
    
    while(j<n-1)
    {
        if(A[j]<A[j+1])
        {
            j=j+1;
        }
        
        if(A[i]<A[j])
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i=j;
            j=2*j;
        }
        else
        {
            break;
        }
    }
    return val;
}

void Heapify(int A[], int n){
    // # of leaf elements: (n+1)/2, index of last leaf element's parent = (n/2)-1
    for (int i=(n/2)-1; i>=0; i--){
 
        int j = 2 * i + 1;  // Left child for current i
 
        while(j < n-1){
            // Compare left and right children of current i
            if (A[j] < A[j+1]){
                j = j+1;
            }
 
            // Compare parent and largest child
            if (A[i] < A[j]){
              //  swap(A, i, j);
                i = j;
                j = 2 * i + 1;
            } else {
                break;
            }
        }
    }
}
 

int main()
{
    int A[7]={0,10,20,30,25,40,35};
    
    for(int i=2;i<=7;i++)
    {
        insertMax(A, i);
    }
    for(int i=1;i<=7;i++)
    {
        cout<< A[i]<<" ";
    }
    return 0;
}
