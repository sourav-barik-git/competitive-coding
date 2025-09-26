#include <bits/stdc++.h>
using namespace std;

string nonOverLappingString(string s){
	int n = s.length();
	int dp[n][n];
	int max_val = -1,start_ix=0;
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(i==0 and s[i] == s[j]) dp[i][j] = 1;
			else if(s[i] == s[j] and j>i)
				dp[i][j] = 1 + dp[i-1][j-1];
			if(max_val < dp[i][j]){
				max_val = dp[i][j];
				start_ix = i - max_val + 1;
			}
		}
	}
	if(max_val == -1) return -1;
	return s.substr(start_ix,max_val);
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
		string s;cin>>s;
		cout<<nonOverLappingString(s)<<endl;
	}
}