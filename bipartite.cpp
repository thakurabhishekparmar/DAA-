#include<bits/stdc++.h>
using namespace std;

bool bipartiteDfs(int node , vector<int> G[] , int color[])         // checking for adjacency nodes
{
    if(color[node]==-1)
    {
        color[node]=1;
    }

    for(auto it: G[node])
    {   
        if(color[it]== -1)
        { 
            color[it]=1-color[node];
            if(!bipartiteDfs(it,G,color));
            {
                return false;
            }
        }
        else if(color[it]== color[node])
        {
            return false;   
        }
        return true;
    }
}

bool checkBipartite(vector<int> G[],int n)      // for bipartite
{
    int color[n];
    memset(color,-1,sizeof color);

    for(int i=0;i<n;i++)
    {
        if(color[i]==-1)
        {
            if(!bipartiteDfs(i,G,color))
            {
                return false;
            }
        }
    }
}

int main(void)
{
    int nodes,edges;
    
    cout<<"Enter the no. of nodes";
    cin>>nodes;
    
    cout<<"Enter the no. of edges";
    cin>>edges;

    vector<int> G[nodes+1];
    int s,d;

    for(int i=1;i<=edges;i++)
    {
        cin>>s>>d;
        G[s].push_back(d);
        G[d].push_back(s);
    }
    
    if(checkBipartite(G,nodes))
        cout<<"Yes"<<endl;
    
    else
        cout<<"No"<<endl;
    
    return 0;
}