#include<bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;cin>>n;
	int d;cin>>d;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		int x;cin>>x;
		v.push_back(x);
	}
	reverse(v.begin(),v.begin()+d);
	reverse(v.begin()+d,v.end());
	reverse(v.begin(),v.end());
	for(auto i:v)
		cout<<i<<" ";
	cout<<endl;
	
}