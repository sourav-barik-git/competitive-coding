#include <bits/stdc++.h>
using namespace std;
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
		int ED[n+1][m+1];

		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++){
				if(i==0)
					ED[i][j] = j;
				else if(j==0)
					ED[i][j] = i;
				else if(s1[i-1] == s2[j-1])
					ED[i][j] = ED[i-1][j-1];
				else
					ED[i][j] = 1 + min(min(ED[i][j-1],ED[i-1][j]),ED[i-1][j-1]);
			}
			
		cout<<ED[n][m]<<endl;
	}
	return 0;
}