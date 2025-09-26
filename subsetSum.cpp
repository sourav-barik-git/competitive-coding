#include <bits/stdc++.h>
using namespace std;

int subsetSum(int arr[],int n,int sum){
	int dp[n][sum+1];
	string ans;
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++){
		for(int j=0;j<sum+1;j++){
			if((i==0 and j != arr[i]) or (j==0 and arr[i]!=0))
				dp[i][j] = 0;
			else if(j < arr[i])
				dp[i][j] = dp[i-1][j];
			else if(arr[i] == j or dp[i-1][j-arr[i]] or dp[i-1][j])
				dp[i][j] = 1;
		}
	}
	return dp[n-1][sum];
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
		int arr[n],sum = 0;
		for(int i=0;i<n;i++){
			 cin>>arr[i];
			 sum += arr[i];
		}
		if(sum & 1){
			 cout<<"NO"<<endl;
			 continue;
		}
		sum /= 2;
		if(subsetSum(arr,n,sum))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}