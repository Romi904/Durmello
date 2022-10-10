#include <iostream>
using namespace std;

class Array
{
public:
    int *A;
    int size;
    int length;
    
 
};
void display(class Array arr)
{
    for(int i=0;i<arr.length;i++)
    {
        cout << arr.A[i];
    }
}
int get(class Array arr , int index)
{
   if(index >= 0 && index < arr.length)
     return arr.A[index];
    
    return -1;
}
int set(class Array &arr , int index ,int x)
{
   if(index >= 0 && index < arr.length)
     return arr.A[index]=x;
    
    return -1;
}
int max(class Array &arr)
{
    int max=0;
    arr.A[0] = max;
    for (int i=1 ; i<arr.length;i++)
    { if(arr.A[i+1]>max)
        {
            arr.A[i+1]= max;
            return max;
        }
    }
    return max;
}


int min(class Array &arr)
{
    int min=0;
    arr.A[0] = min;
    for (int i=1 ; i<arr.length;i++)
    { if(arr.A[i+1]<min)
        {
            arr.A[i+1]= min;
            return min;
        }
    }
    return min;
}

int sum(class Array arr)
{
    int total=0;
    for(int i=0;i<arr.length;i++)
    {
        total += arr.A[i];
        
    }
    return total;
}
int avg(class Array arr)
{
    int total=0;
    for(int i=0;i<arr.length;i++)
    {
        total += arr.A[i];
        
    }
    return total/arr.length;
}

void reverse(class Array arr)
{
    int *B;
    
    B = new int[arr.size];
    for (int i=arr.length-1, int j=0 ; i>=0 , j<arr.length;n i--,j++)
       {
          arr.A[i]=B[j];
       }
}

int main()
{
    Array arr;
    arr.size=10;
    arr.length=5;
    arr.A = new int[10];
    arr.A[0]=2;
    arr.A[1]=3;
    arr.A[2]=4;
    arr.A[3]=5;
    arr.A[4]=6;
    
    cout << set(arr,0,3)<<endl;
    display(arr);

    
    return 0;
}


