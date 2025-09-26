#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;cin>>n;
	int m;cin>>m;
	int arr[n][m];

	int maxSize = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
			if(arr[i][j] != 0 and i>0 and j>0)
				arr[i][j] = min(arr[i][j-1],min(arr[i-1][j-1],arr[i-1][j])) + 1;
			maxSize = max(maxSize,arr[i][j]);
		}
	cout<<maxSize;
}