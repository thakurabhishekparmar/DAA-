#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int main(){
    int n;           // the no. of vertices
    cin>>n;

    int e;          // no.of edges
    cin>>e;

    vector<vector<int>> adj(n);
    vector<int> indeg(n,0);

    int s,d;        // source, destination
    for(int i=0;i<e;i++){
        cin>>s>>d;
        adj[s].push_back(d);
        indeg[d]++;
    }

    queue<int> pq;

    for(int i=0;i<n;i++)
    {
        if(indeg[i]==0)
        {
            pq.push(i);
        }
    }

    while(!pq.empty())
    {
        cnt++;
        int x=pq.front();
        pq.pop();
        cout<<x<<" -> ";

        for(auto it: adj[x])
        {
            indeg[it]--;
            if(indeg[it]==0)
                pq.push(it);
        }

    }

    if(pq.empty())
        cout<<"cycle detected"<<endl;
    return 0;
}