#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1,pair<int, int> p2)
{
	return p1.second < p2.second;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;cin>>n;
	vector<pair<int,int> >  v;
	int c,r;
	for(int i=0;i<n;i++)
	{	
		cin>>c>>r;
		v.push_back(make_pair(c-r,c+r));
	}
	sort(v.begin(),v.end(),compare);

	int end = v[0].second;
	int ans = 0;
	for(int i=1;i<n;i++)
	{
		if(v[i].first > end)
			end = v[i].second;
		else
			ans++;
	}
	cout<<ans;
	return 0;
}