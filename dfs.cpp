#include<iostream>
#include<vector>
using namespace std;

vector<int> a[10000];
int visited[10000]={0}; 

void dfs(int k)
{
    if(!visited[k])
    {
        visited[k]=1;

        for(int i=0; i< a[k].size() ; i++)
        {
            if(!visited[a[k][i]])
                dfs(a[k][i]);
        }

       /*
       for(auto it:a[k])
       {
           if(!visited[it])
            dfs(it);
       }
        */
    }
}

int main()
{
    //directed graph
    int n;
    cout<<"Enter no. of edges: ";
    cin>>n;
    while(n--)
    {
        int p,q;
        cin>>p>>q;
        a[p].push_back(q); // if u can go from p to q , you can,t go from q to p
                            // so, in adjaceny list of p we add q
    }
/*
    dfs(0); // let starting vertex be 0
    cout<<endl;
    for(int i=0;i<=8;i++)
        cout<<i<<":"<<visited[i]<<endl; //to check the state of i

    cout<<endl;
 
*/
    // can u go from l to m
    int l,m;
    cin>>l>>m;
    dfs(l);

    if(visited[m]==1)
        cout<<"yes path exist"<<endl;
    else 
        cout<<"No path doesn't exist"<<endl;
       
        return 0;
}

/*
1 5
2 7
0 1
3 4
1 4
*/
