#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int,int>> activity;  // pair of end time and start time
    int n,st,et;
    cout<<"Enter the no. of activities:\n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>st>>et;
        activity.push_back({et,st});
    }
    
    sort(activity.begin(),activity.end()); // sort according starting time in ascending order 

    int cnt;  // no. of activity run in a uniprocessor
    int pcnt=0; // no. uniprocessor required to complete all activities
    int current_end;

    vector<bool> comp(n,false); // for track of activities that are completed
    int completed=0;    //activities that are completed

    cout<<"total no. of activities: "<<n<<endl;
    while(completed!=n)
    {
        pcnt++;
        current_end=-1;
        cnt=0;
        cout<<"\nProcessor no: "<<pcnt<<endl;
        for(int i=0;i<n;i++)
        {
            if(!comp[i] && activity[i].second > current_end)
            {
                cnt++;
                current_end=activity[i].first;
                comp[i]=true;
                completed++;
                cout<<activity[i].second<<"\t"<<activity[i].first<<endl;
            }
        }
        cout<<"No. of activity completed: "<<cnt<<endl;
    }
    cout<<"\nNo. of uniprocessor required to complete all the activities : "<<pcnt<<endl;

    return 0;
}
/*
7
0 6
1 2
3 4
5 7
5 9
8 9
7 9
*/
