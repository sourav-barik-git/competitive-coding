#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[],int n)
{
	int min_idx;
	for(int i=0;i<n-1;i++)
	{
		min_idx = i;
		for(int j=i;j<=n-1;j++)
			if(arr[j] < arr[min_idx])
				min_idx = j;
		swap(arr[i],arr[min_idx]);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	selection_sort(arr,n);
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}