#include<bits/stdc++.h>
using namespace std;

void path(vector<int>& parent , int a)
{
    if(parent[a] == -1)
    {
        cout<<a;
        return;
    }
    cout<<a<<" ";
    //printf("%d",a);
    path(parent,parent[a]);
}

int main(void)
{
    int nodes,edges;
    cin>>nodes>>edges;

    vector<vector<pair<int,int>>> g(nodes+1);                    // Adjacency list 
    set<pair<int,int>> s;                              // for storing (dist,vertex)
    vector<int> dist(nodes+1,INT8_MAX);
    vector<int> parent(nodes+1,-1);

    cout<<"Enter Source , Destination with Weight\n";

    while(edges--)
    {
        int s,d,wt;
        cin>>s>>d>>wt;
        g[s].push_back({d,wt});
        g[d].push_back({s,wt});
    }

    cout<<"Enter the starting node: ";
    int src;
    cin>>src;                       // input source
    
    dist[src]=0;

    // insert source into set as {weight,vertex} pair
    s.insert({0,src});                          
    
    while(!s.empty())
    {
        auto x=*(s.begin());                    // gets the lowest vertex weight from set (vertex=x.second)
        s.erase(x);                         // remove from set
        
        for(auto i:g[x.second])             // pair<int,int> = g[vertex];
        {
            if(dist[i.first] > dist[x.second]+i.second)
            {   //relax
                s.erase({dist[i.first],i.first});
                dist[i.first]=dist[x.second]+i.second;
                s.insert({dist[i.first],i.first});
                parent[i.first]=x.second;
            }
        }
    }

    // print the path and shortest distance as set
    for(int j=1;j<nodes+1 ;j++)
    {
        path(parent,j);
        cout<<":"<<dist[j]<<endl;
    }


    return 0;
}
/*
1 2 7
1 3 5
1 4 4
2 4 1
2 3 2
3 4 4
*/