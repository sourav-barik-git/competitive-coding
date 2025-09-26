#include <bits/stdc++.h>
using namespace std;


int minimumCostToMake2StringsIdentical(string x,string y,int s,int p){
	int m = x.length(),n=y.length();
	int dp[m+1][n+1];
	for(int i=0;i<=n;i++) dp[0][i] = p*i;
	for(int i=0;i<=m;i++) dp[i][0] = s*i;

	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
		{
			if(x[i-1] == y[j-1]) dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = min(s + dp[i-1][j] , p + dp[i][j-1]);
		}
	}
	return dp[m][n];		
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t;cin>>t;
	while(t--){
		int s;int p;
		cin>>s>>p;
		string s1,s2;
		cin>>s1>>s2;
		cout<<minimumCostToMake2StringsIdentical(s1,s2,s,p)<<endl;
	}
}