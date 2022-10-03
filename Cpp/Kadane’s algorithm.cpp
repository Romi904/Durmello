#include<bits/stdc++.h>
using namespace std;
int largest_sum_subarray(vector<int> arr)
{
    int max_sum=INT_MIN;
    int sum=0;
    for(auto x: arr)
    {
        if(sum<0)
        {
            sum=0;
        }
        sum=sum+x;
        if(sum>max_sum)
        {
            max_sum=sum;
        }
    }
    return max_sum;
}
int main()
{
    int size,value;
    cout<<"please enter array size:-";
    cin>>size;
    vector<int> arr;
    cout<<"please enter the values"<<endl;
    for(int i=0; i<size; i++)
    {
        cin>>value;
        arr.push_back(value);
    }
    cout<<largest_sum_subarray(arr);

}
