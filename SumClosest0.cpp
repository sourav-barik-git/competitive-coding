#include<bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;cin>>n;

	vector<int> v;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	int l_index = 0;
	int r_index = n-1;
	int a = v[l_index],b = v[r_index];

	while(l_index < r_index){
		int sum = b + a;
		if(sum==0)break;
		else if(sum > 0)
			b = v[--r_index];
		else
			a = v[++l_index];
	}
	cout<<a<<" "<<b<<endl;
}