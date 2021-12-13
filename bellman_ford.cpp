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
    int n,e;            // nodes and edges
    cin>>n>>e;
    vector<vector<int>> edges;
    vector<int> parent(n+1,-1);
    vector<int> dist(n+1,1e9);

    while(e--)
    {
        int s,d,w;
        cin>>s>>d>>w;

        edges.push_back({s,d,w});
        edges.push_back({d,s,w});
    }

    int src;
    cin>>src;

    dist[src]=0;


    bool negative_cycle;    // to detect -ive cycle

    // iterate for n-1 to relax all nodes

    for(int i=1;i<n;i++)
    {
        negative_cycle=false;

        for(auto i: edges)
        {
            int s,d,w;
            s=i[0];
            d=i[1];
            w=i[2];

            if(dist[d] > dist[s]+w)
            {
                dist[d]=dist[s]+w;
                parent[d]=s;
                negative_cycle=true;
            }
        }
        
    }

    if(negative_cycle)
        cout<<"Negative cycle present"<<endl;
    else 
    {
        for(int i=1;i<=n;i++)
        {
            path(parent,i);
            cout<<" : "<<dist[i]<<endl;
        }
    }

    return 0;
}
/*
5 6
1 2 4
2 3 2
3 1 1
2 5 4
3 4 4
4 5 4
1
*/