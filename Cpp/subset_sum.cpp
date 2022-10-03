#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool subset_sum(int arr[] ,int n , int sum)
{

if(n<0)
return false;

if(sum==0)
return true;

if(arr[n-1]<=sum)
{
    return (subset_sum( arr,n-1,sum-arr[n-1]) || (subset_sum(arr,n-1,sum)) );
}
else
return (subset_sum(arr,n-1,sum));

}

int main()
{

int arr[] = {2,3,7,8,10};
int sum = 110;

if(subset_sum(arr,5,sum))
cout<<"True";
else
cout<<"False";


return 0;

}