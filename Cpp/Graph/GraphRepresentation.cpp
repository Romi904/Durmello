#include <bits/stdc++.h>
using namespace std;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
typedef long double ld;
#define forall(i, a, b) for (ll i = a; i < b; i++)
#define en "\n"
#define deb(x) cout << #x << " " << x << "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define eb emplace_back
#define bg begin()
#define ed end()
#define sz size()
#define vi vector<int>
#define yes cout<<"YES"<<en;
#define no cout<<"NO"<<en;
#define print(x) cout<<x<<en;
#define ff first
#define ss second
#define PI 3.141592653589793238462

vi adj[100];
void solve()
{
    int n,m;cin>>n>>m;
    vector<vector<int>> adjm(n+1,vector<int>(n+1,0));
    forall(i,0,m){
        int x,y;cin>>x>>y;
        adjm[x][y]=1;
        adjm[y][x]=1;
    }
    forall(i,1,n+1){
        forall(j,1,n+1){
            cout<<adjm[i][j];
        }
        cout<<en;
    }
    cout<<en;
    if(adjm[3][7]==1){
        print("There is Edge between 3 and 7");
    }
    cin>>n>>m;
    forall(i,0,m){
        int x,y;cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    forall(i,1,n+1){
        cout<<i<<" -> ";
        forall(j,0,adj[i].size()){
            cout<<adj[i][j]<<" ";
        }
        cout<<en;
    }
}

int main()
{
    fastio();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
