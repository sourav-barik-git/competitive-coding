#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> v1,pair<int,int> v2)
{
	return v1.second < v2.second;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;cin>>n;
	vector<pair<int ,int> > v;
	int s,e;

	for(int i=0;i<n;i++){
		cin>>s>>e;
		v.push_back(make_pair(s,e));
	}
	

	sort(v.begin(),v.end(),compare);

	
	int res = 1;
	int fin = v[0].second;

	for(int i=1;i<n;i++){
		if(v[i].first >= fin){
			fin = v[i].second;
			res++;
		}
	}
	cout<<res;
	return 0;

	
}
