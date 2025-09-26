 #include <bits/stdc++.h>
using namespace std;

int maxSubArrayWithSumX(int arr[],int n,int k)
{
	unordered_map<int,int> m;
	int prefix_sum = 0;
	int len = 0;
	for(int i=0;i<n;i++){
		prefix_sum += arr[i];
		if(arr[i]==k and len == 0) len = 1;
		if(prefix_sum == k) len = i + 1;
		if(m.find(prefix_sum - k) != m.end()) len = max(len,i-m[prefix_sum - k]);
		else{
			m[prefix_sum] = i;
		}
	}
	return len;
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
		int k;cin>>k;
		int arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		int ans  = maxSubArrayWithSumX(arr,n,k);
		cout<<ans<<endl;
	}
}