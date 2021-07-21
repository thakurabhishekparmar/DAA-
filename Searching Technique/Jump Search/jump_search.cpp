#include<bits/stdc++.h>
using namespace std;

int  jump_search(int arr[],int n,int *itr)
{
	
	int key,prev,step; 
	
	cin>>key;       							// element to search
	
	prev=0;
	step=sqrt(n);
	
						// Finding the block search
	while(arr[min(step,n)-1]<key)
	{
		(*itr)++;
		
		prev=step;
		step=step+sqrt(n);
			
		if(prev>=n)
			return -1;		
	}
	
							// Linear search in block 
	while(arr[prev]<key)
	{
		(*itr)++;
		prev++;
		
		if(prev==min(step,n))
			return -1;		
	}
	
	
	(*itr)++;
	if(arr[prev]==key)
		{
			return prev;
		}
	
	else
		return -1;
		
}
int main()
{
	
	int a;  		// No of queries
	cin>>a;
	
	while(a>0){
		
		int n;
		int itr=0;  	// no of comparisons 
		
		cin>>n;			// size of array
	
		
		int arr[n];
		
		// user input array
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		
		int x= jump_search(arr,n,&itr);					// function call
		
		if(x!= -1)
			cout<<"Present "<<itr<<endl;
		
		else{
			cout<<"Not Present "<<itr<<endl;
			break;
		}
			
	a--;
	} 
	return 0;
}
