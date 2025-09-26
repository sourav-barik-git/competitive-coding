#include <bits/stdc++.h>
#define ll long long
using namespace std;
int dp[101][101];

int optimalGame(ll arr[],int i,int j){
	if(i > j) return 0;
	if(i == j+1) return max(arr[i],arr[j]);

	if(dp[i][j] != -1) return dp[i][j];

	int ans1 = arr[i] + min(optimalGame(arr,i+2,j),optimalGame(arr,i+1,j-1));
	int ans2 = arr[j] + min(optimalGame(arr,i+1,j-1),optimalGame(arr,i,j-2));
	return dp[i][j] = max(ans2,ans1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t;cin>>t;
	while(t--){
	   int n;cin>>n;
	   long long arr[n];
	   memset(dp,-1,sizeof(dp));
	   for(int i=0;i<n;i++) cin>>arr[i];
	   cout<<optimalGame(arr,0,n-1)<<endl;
	}
}