#include<bits/stdc++.h>
using namespace std;

int searchSortedRotatedArray(int arr[],int start, int end, int key)
{
	if(start > end)
		return -1;
	int middle = (start + end )/2;
	if(key == arr[middle])
		return middle;
	if(arr[start] <= arr[middle])
		return (arr[start] >= key && arr[middle] <= key)?searchSortedRotatedArray(arr,start,middle-1,key):searchSortedRotatedArray(arr,middle+1,end,key);
	return (arr[middle] <= key && arr[end] >= key)?searchSortedRotatedArray(arr,middle+1,end,key):searchSortedRotatedArray(arr,start,middle-1,key);
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

	int key;cin>>key;
	int index = searchSortedRotatedArray(arr,0,n-1,key);

	if(index == -1)
		cout<<"Key not found"<<endl;
	else
		cout<<"Key found at "<<index;

}