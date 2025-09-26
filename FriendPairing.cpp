#include <bits/stdc++.h>
using namespace std;
long long dp[100];

int friendPairing(int N)
{
    dp[0] = 1;
	dp[1] = 1;
	for(int i=2;i<=N;i++){
		dp[i] = dp[i-1] + (i-1)*dp[i-2];
		cout<<dp[i]<<endl;
	}

	return dp[N];
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
	   memset(dp,0,sizeof(dp));
	   cout<<friendPairing(n)<<endl;
	}
}