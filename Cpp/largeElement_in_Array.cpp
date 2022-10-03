#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the range : "<<endl;
    cin>>n;
    int a[n];
   
    cout<<"enter the value : "<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

     int large=a[0];



    cout<<"the output : "<<endl;
    for(int i=0;i<n;i++){
        if(large<a[i]){
            large=a[i];
        }
    }
    cout<<"large : "<<large;


}