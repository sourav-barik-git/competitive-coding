#include <bits/stdc++.h>
using namespace std;


int NthStairProblem(int n,int max_steps){
	int dp[n+1];
	dp[0] = dp[1] = 1;
	for(int i=2;i<=n;i++){
		dp[i] = 0;
		for(int j=1;j<=max_steps and j<=i;j++)
			dp[i] += dp[i-j];
	}
	return dp[n];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t;cin>>t;
	while(t--){
		int nstair,max_steps;
		cin>>nstair>>max_steps;
		cout<<NthStairProblem(nstair,max_steps)<<endl;
	}
}