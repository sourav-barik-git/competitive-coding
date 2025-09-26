#include<bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;cin>>n;
	int arr[n] ;
	for(int i=0;i<n;i++)
		cin>>arr[i];

	int l_index = 0;
	int r_index = n-1;
	while(l_index < r_index)
	{
		while(arr[l_index]==0 && l_index<r_index)
			l_index++;
		while(arr[r_index]==1 && l_index<r_index)
			r_index--;
		arr[l_index]= 0;
		arr[r_index] = 1;
	}
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}