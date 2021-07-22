#include<bits/stdc++.h>
using namespace std;

void binary_search(int arr[],int n)
{
	int key,mid,low,high,found;
	
	int count=0;				//no of comparisons
		
		cin>>key;  				// searching element 
		
		low=0;
		high=n-1;
		found=0;
		
		while(low<=high)
		{
		
			mid=low+(high-low)/2;
			count++;
			if(key==arr[mid])
				{
					found=1;
					break;
				}
			else if(key>arr[mid])
				{
					low=mid+1;
					//count++;
				}
			else
				{	
					high=mid-1;
					count++;
				}
		}
		
		if(found==1)
			{
				cout<<"Present "<<count<<endl;
			}
		else
			{
				cout<<"Not Present "<<count<<endl;
			}
}


int  main()
{
	int a;   						
	cin>>a;
	
	
		while(a>0){					// No of queries
	
			int n;      		
			cin>>n;					// ask user Size of array
	
			int arr[n];				// array elements
			for(int i=0;i<n;i++)
			{
				cin>>arr[i];
			}
			
			binary_search(arr,n); 					//  function call
		a--;
		}
	return 0;
	
}
