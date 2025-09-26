#include <bits/stdc++.h>
#define ll long long
using namespace std;

int longestConsequtiveSubsequence(int arr[],int n){
	unordered_set<int> mp;
	int ans = 0,ctr;
	for(int i=0;i<n;i++)
		mp.insert(arr[i]);
	for(int i=0;i<n;i++){
		if(mp.find(arr[i] - 1) == mp.end())
		{
			ctr = 0;
			int x = arr[i];
			while(mp.find(x) != mp.end()){
				ctr++;
				x++;
			}
			ans = max(ans,ctr);
		}
	}
	return ans;
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
	   int arr[n];
	   for(int i=0;i<n;i++) cin>>arr[i];
	   cout<<longestConsequtiveSubsequence(arr,n)<<endl;
	}
}