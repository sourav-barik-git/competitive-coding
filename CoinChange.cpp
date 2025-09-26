#include <bits/stdc++.h>
using namespace std;

int coinChange(int coins[],int n,int amt){
	int dp[n+1][amt+1];
	for(int i=0;i<=amt;i++) dp[0][i] = 0;
	for(int i=0;i<=n;i++) dp[i][0] = 1;

	for(int i=1;i<=n;i++)
		for(int j=1;j<=amt;j++)
			dp[i][j] = (j < coins[i-1])?(dp[i-1][j]):(dp[i-1][j] + dp[i][j-coins[i-1]]);

	return dp[n][amt];
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
		int coins[n];
		for(int i=0;i<n;i++) cin>>coins[i];
		int amount;cin>>amount;
		cout<<coinChange(coins,n,amount)<<endl;
	}
}