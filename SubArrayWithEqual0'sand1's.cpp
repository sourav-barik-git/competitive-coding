#include <bits/stdc++.h>
using namespace std;
int maxLen(int arr[], int N)
{
    // Your code here
    map<int,int> m;
    for(int i=0;i<N;i++) 
        if(arr[i] == 0)
            arr[i] = -1;
    int cum_sum = 0;
    int max_len = 0;
    for(int curr=0;curr<N;curr++)
    {  
        cum_sum += arr[curr];
        if(cum_sum == 0)
        	max_len = curr + 1;
        else if(m.find(cum_sum) == m.end())
            m[cum_sum] = curr;
        else
            max_len = max(max_len,curr - m[cum_sum]); 
    }
    return max_len;
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

	cout<<maxLen(arr,n);
}