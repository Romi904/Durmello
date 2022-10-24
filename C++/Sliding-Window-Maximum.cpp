/*
GFG Question: Maximum of all subarrays of size k (Sliding Window Maximum)
Question Link: https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
*/

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector <int> ans ;
        deque<int> dq ;
        
        for(int i=0 ; i<n ; i++){
        if(!dq.empty() && dq.front() == i-k) dq.pop_front() ;
        
        while(!dq.empty() && arr[dq.back()] < arr[i]) dq.pop_back() ;
        
        dq.push_back(i) ;
        
        if(i >= k-1) ans.push_back(arr[dq.front()]) ;
        }
        return ans ;
    }
};
