#include<bits/stdc++.h>
using namespace std;

void linear_search(int arr[],int n)
{
	int key,found,count;
			cin>>key;			// searching element
		
		found =0;
		count=0;
			for(int i=0;i<n;i++)
				{
					count++;
					if(key==arr[i])
						{
							found=1;
							break;
						}
				}
		
			if(found==1)
			{
				cout<<"Present "<<count<<endl;
			}
			
			else
				cout<<"Not present "<<count<<endl;
			
}

int main()
{
	int a;
	cin>>a;
	
	while(a>0)
	{
	
		int n;					// size of array
		cin>> n;
		
		int arr[n];				// array 
		for(int i=0;i<n;i++)
			{
				cin>>arr[i];
			}
		
		
		
	linear_search(arr,n);			// function call
	
	a--;
	}
	
	return 0;
}
