#include<bits/stdc++.h>
using namespace std;

// Function for finding parent
int findParent(int u,vector<int>& parent){         
    if( parent[u] < 0)
        return u;
    
    parent[u] = findParent(parent[u] , parent);
    return parent[u];
    
}

bool unionByWeight(int u , int v , vector<int>& parent){
    int pu=findParent(u,parent);
    int pv=findParent(v,parent);

    if(pu == pv){
        cout<<"Cycle detected"<<endl;
        return false;
    }

    if(parent[pu] < parent[pv]){
        parent[pu]+=parent[pv];
        parent[pv]=pu;
    }

    else{
        parent[pv]+=parent[pu];
        parent[pu]=pv;
    }
    return true;
}

void print(vector<int> p,int n)
{
    for(int i=0;i<n;i++)
        cout<<p[i]<<" ";

    cout<<endl;
}

int main(){
    int n;           // the no. of vertices
    cin>>n;
    vector<int> parent(n,-1);
    print(parent,n);

    int e;          // no.of edges
    cin>>e;

    int s,d;        // source, destination
    for(int i=0;i<e;i++){
        cin>>s>>d;
        unionByWeight(s,d,parent);      // function call
        print(parent,n);
    }

    cout<<"Parent is: ";
    int min=0;
    for(int i=0;i<n;i++)
    {
        if(parent[i]<min)
            min=i;
    }
    cout<<min<<endl
    ;
    return 0;
}
