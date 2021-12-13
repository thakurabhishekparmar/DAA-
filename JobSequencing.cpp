#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b)      // fro sorting according to profit in increasing order
{
    return a.first > b.first;
}

int main()
{
    vector<pair<int,int>> jobs;                 // pair of end time and start time
    int n;
    cout<<"Enter the no. of jobs:\n";
    cin>>n;
    int p,d;                                    // profit and deadline
    cout<<"Enter the profit and deadline of jobs:\n";
    for(int i=0;i<n;i++)
    {
        cin>>p>>d;
        jobs.push_back({p,d}); 
    }

    sort(jobs.begin(),jobs.end(),compare);  

    int maxEndtime=0;
    for(int i=0;i<n;i++)
    {
        if(jobs[i].second>maxEndtime)
        {
            maxEndtime=jobs[i].second;
        }
    }

    int fill[maxEndtime];                   // 
    int count=0;
    int profit=0;

    for(int i=0;i<maxEndtime;i++)
    {
        fill[i]=-1;
    }

    for(int i=0;i<n;i++)
    {
        int j=jobs[i].second-1;
        while(j>=0 && fill[j] != -1)
        {
            j--;
        }

        if(j>=0 && fill[j]==-1)
        {
            fill[j]=i;
            count++;
            profit+=jobs[i].first;
        }
    }
    cout<<"No. of jobs can be done : "<<count<<"\n";
    cout<<"Max Profit : "<<profit<<endl;
    return 0;
}


/* Test Example
5
100 2
19 1
27 2
25 1
15 3
*/