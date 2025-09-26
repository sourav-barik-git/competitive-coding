#include <bits/stdc++.h>
using namespace std;

int maxSubArrayWithSumZero(int arr[],int n)
{
	unordered_map<int,int> m;
	int prefix_sum = 0;
	int len = 0;
	for(int i=0;i<n;i++){
		prefix_sum += arr[i];
		if(arr[i]==0 and len == 0) len = 1;
		if(prefix_sum == 0) len = i + 1;
		if(m.find(prefix_sum) != m.end()) len = max(len,i-m[prefix_sum]);
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
	int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans  = maxSubArrayWithSumZero(arr,n);
	cout<<ans;
}