#include <bits/stdc++.h>
using namespace std;


int LPS(string s){
	int n = s.length();
	int dp[n][n];
	for(int i=0;i<n;i++) dp[i][i] = 1;

	int j;
	for(int k=1;k<n;k++){
		for(int i=0;i < n - k + 1;i++){
			j = k + i;
			if(k == 1 and s[i] == s[j]) dp[i][j] = 2;
			else if(s[i] == s[j]) dp[i][j] = 2 + dp[i+1][j-1];
			else
				dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
		}
	}
	return dp[0][n-1];

}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t;cin>>t;
	while(t--){
		string s;cin>>s;
		cout<<LPS(s)<<endl;
	}
}