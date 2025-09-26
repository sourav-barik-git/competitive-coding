#include<bits/stdc++.h>
using namespace std;

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
	int X;cin>>X;
	map<int,int> hash;
	int sum = 0,diff = 0,low= -1,high=-1;
	for(int i=0;i<n;i++)
	{
		sum += arr[i];
		hash[sum] = i;
		diff = sum - X;
		if(hash.count(diff) > 0){
			low = hash[diff] + 1;
			high = i;
			cout<<"Found!"<<endl;
			break;
		}
	}
	if(low == -1 and high == -1)
	{
		cout<<"No such subarray"<<endl;
		exit(0);
	}
	for(int i =low;i<=high;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	
}