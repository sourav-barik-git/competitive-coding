#include<bits/stdc++.h>
using namespace std;

int findMid(int arr[],int start,int end)
{
	if(start >= end)
		return -1;
	int mid = (start + end)/2;
	if(arr[mid] >= arr[mid+1] and arr[mid]>= arr[mid-1])
		return mid;
	if(arr[mid] >= arr[mid-1] and arr[mid] <= arr[mid+1])
		return findMid(arr,mid+1,end);
	return findMid(arr,start,mid-1);
	
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	int missing = findMid(arr,0,n-1);
	cout<<missing;

}