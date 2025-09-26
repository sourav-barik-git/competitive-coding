#include <bits/stdc++.h>
using namespace std;


bool wordBreak(unordered_map<string,bool> hash,string s){
	int n = s.length();
	bool dp[n][n];
	memset(dp,false,sizeof(dp));
	if(hash[s.substr(0,n)]) return 1;

	for(int i=0;i<n;i++) dp[i][i] = hash[s.substr(i,1)];

	for(int k=1;k<n;k++){
		for(int i=0;i<n-k+1;i++){
			int j = i + k;
			bool ans = false;
			bool entire = hash[s.substr(i,j-i+1)];
			for(int l=i;l<=j;l++)
				ans = ans or (dp[i][l] and dp[l+1][j]);
			dp[i][j] = ans + entire;
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
		int n;cin>>n;
		unordered_map<string,bool> hash;
		for(int i=0;i<n;i++){
			string str;cin>>str;
			hash[str] = true;
		}
		string s;cin>>s;
		cout<<wordBreak(hash,s)<<endl;
	}
}