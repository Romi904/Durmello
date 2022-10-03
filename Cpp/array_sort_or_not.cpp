#include<iostream>
using namespace std;

int main(){
    int n,f=0;

    cout<<"Enter the range"<<endl;
    cin>>n;
    
    int arr[n];
    
    cout<<"Enter the value : "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                f++;
                break;
            }

        }
    }
    
    if(f==1){
        cout<<"Array is not sorted : "<<endl;
    }
     else{
         cout<<"Array is sorted : "<<endl;
       }
    
    
    cout<<"Output : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
}