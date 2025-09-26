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
    	int n;cin>>n;
    	int arr[n];
    	for(int i=0;i<n;i++) cin>>arr[i];
    	sort(arr,arr+n);
    	string num1 = "",num2 = "";
    	for(int i=0;i<n;i=i+2)
        {
            str=to_string(arr[i]);
            num1 += str;
        }
        for(int i=1;i<n;i=i+2)
        {
            str=to_string(arr[i]);
            num2 += str;
        }
    	cout<<stoi(num1)<<" "<<stoi(num2)<<endl;
    }
    return 0;
}