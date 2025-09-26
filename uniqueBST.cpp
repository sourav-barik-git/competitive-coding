#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll nCr(int n,int r){
    if(r > n-r)
        r = n - r;
    ll ans = 1,j=1;
    for(int i=0;i<r;i++)
        ans =  ans * (n-i)/j++;
    return ans;
}

ll uniqueBST(int n){
  return nCr(2*n,n)/(n+1);  
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
	   cout<<uniqueBST(n)<<endl;
	}
}