#include <iostream>

#include <algorithm>
#include <vector>


using namespace std;



class DSU
{
    int *parent;
    int *rank;
    
    
    public:
    
    DSU(int no)
    {
        
        parent = new int[no];
        rank = new int[no];
        
        for(int i = 0; i < no; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    
    
    int findSet(int i)
    {
        if(parent[i] == -1)
        {
            return i;
        }
        
        return parent[i] = findSet(parent[i]);
    }
    
    
    void unionSet(int x, int y)
    {
        
        
        int s1 = findSet(x);
        int s2 = findSet(y);
        
        if(s1!=s2)
        {
            if(rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] = rank[s2] + rank[s1];
            }
            
            else
            {
                parent[s2] = s1;
                rank[s1] = rank[s1] + rank[s2];
            }
        }
        
    }
};




class Graph 
{
    int Vertices;
    
    vector< vector<int> > edgeList;
    
    
    public:
    
    Graph(int V)
    {
        Vertices = V;
    }
    
    
    void addEdge(int a,int b, int weight)
    {
        edgeList.push_back({weight,a,b});
    }
    
    
    
    
    int kruskalAlgo()
    {
        sort(edgeList.begin(),edgeList.end());

        int answer = 0;

        
        DSU d(Vertices);

        for(auto edge: edgeList)
        {
            int myweight = edge[0];
            int firstElement = edge[1];
            int secondElement = edge[2];

            if(d.findSet(firstElement) != d.findSet(secondElement))
            {
                d.unionSet(d.findSet(firstElement),d.findSet(secondElement));
                answer = answer + myweight;
                
            }
            
            
            
            
        }
        
        
        return answer;
        
    }
    
    
    
    
};






int main()
{
    Graph G(4);
    G.addEdge(1,2,1);
    G.addEdge(2,3,2);
    G.addEdge(3,4,3);
    G.addEdge(2,4,3);
    G.addEdge(1,4,2);
    G.addEdge(1,3,2);
    
    cout << "Minimimum Spanning Tree Weight: " << G.kruskalAlgo();

    return 0;
}

