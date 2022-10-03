#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector <int> ar = {8,20,7,32,44,11,12,19,13,10};
    set<int> s;
    for(int i=0;i<ar.size();i++)
    s.insert(ar[i]);
    int count=0;
    int max=0;
    auto j = s.begin() ;
    auto k = ++s.begin() ;
   for (; j!=--s.end() ; j++, k++)
    {  
        if((*k - *j) == 1 )
        { count++; 
        if(count>max) 
        max=count;
        } 
        else
        {count=0;}
    }

    cout<<max+1;





    return 0;
}