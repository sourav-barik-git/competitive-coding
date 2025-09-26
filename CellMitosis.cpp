#include <bits/stdc++.h>
using namespace std;
int dp[1000];

long long solveCellProblem(int n,int x,int y,int z)
{
	int temp;
	for(int i=2;i<=n;i++){
		if(i&1)
			temp = dp[(i+1)/2] + x + z;
		else
			temp = dp[i/2] + x;
		dp[i] = min(temp,dp[i-1] + y);
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
	   int n,x,y,z;
	   cin>>n>>x>>y>>z;
	   memset(dp,0,sizeof(dp));
	   cout<<solveCellProblem(n,x,y,z)<<endl;
	}
}