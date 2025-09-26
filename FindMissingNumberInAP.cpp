#include<bits/stdc++.h>
using namespace std;

int findMissing(int arr[],int start,int end,int diff)
{
	if(start >= end)
		return INT_MAX;
	int middle = (start + end)/2;
	if(middle > 0 and (arr[middle] - arr[middle-1]) != diff)
		return arr[middle-1] + diff;
	if(arr[middle+1] - arr[middle] != diff)
		return arr[middle] + diff;
	if(arr[middle] == arr[0] + diff*(middle))
		return findMissing(arr,middle+1,end,diff);
	return findMissing(arr,start,middle-1,diff);
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

	int diff;cin>>diff;

	int missing = findMissing(arr,0,n-1,diff);
	cout<<missing;

}