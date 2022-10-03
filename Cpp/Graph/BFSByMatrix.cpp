#include<bits/stdc++.h>
using namespace std;
#define forall(i,a,b) for(int i=a;i<b;i++)

void BFS(int &startEle,int &n,vector<vector<int>> adjm){
    bool visited[n+1];

    forall(i,0,n+1){
        visited[i]=0;
    }
    queue<int> q;
    q.push(startEle);
    cout<<startEle<<" ";
    visited[startEle]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        forall(j,1,n+1){
            if(visited[j]==0 && adjm[u][j]==1){
                q.push(j);cout<<j<<" ";visited[j]=1;
            }
        }
    }


}
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>>adjm(n+1,vector<int>(n+1,0));
// 6 6
// 1 2
// 1 3
// 2 4
// 3 4
// 4 5
// 4 6
// 1
    forall(i,0,m){
        int x,y;
        cin>>x>>y;
        adjm[x][y]=1;
        adjm[y][x]=1;
    }
    int startEle;
    cin>>startEle;
    BFS(startEle,n,adjm);
    // forall(i,1,n+1){
    //     forall(j,1,n+1){
    //         cout<<adjm[i][j];
    //     }
    //     cout<<endl;
    // }
    return 0;

}

