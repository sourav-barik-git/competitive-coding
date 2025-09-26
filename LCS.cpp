#include <bits/stdc++.h>
using namespace std;
int dp[500][500];
int lcs(string s1,string s2){
    int m = s1.length();
    int n = s2.length();
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
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
    	int n,m;
    	cin>>n>>m;
    	string s1,s2;
    	cin>>s1>>s2;
        memset(dp,0,sizeof(dp));
    	cout<<lcs(s1,s2)<<endl;
    }
}