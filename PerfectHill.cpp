#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];

	int LIS[n],LDS[n];
	
	int maxLen = 1,currLen;

	LDS[n-1] = 1;
	LIS[0] = 1;
	for(int i=1;i<n;i++){
		currLen = 1;
		for(int j=i-1;j>=0;j--){
			if(arr[j] < arr[i])
				currLen = max(currLen,LIS[j] + 1);
		}
		LIS[i] = currLen;
	}
	for(int i=n-2;i>=0;i--){
		currLen = 1;
		for(int j=i+1;j<n;j++){
			if(arr[j] < arr[i])
				currLen = max(currLen,LDS[j] + 1);
		}
		LDS[i] = currLen;
	}
	for(int i=0;i<n;i++)
		maxLen = max(maxLen,min(LIS[i],LDS[i]) * 2 - 1);

	cout<<maxLen<<endl;
}