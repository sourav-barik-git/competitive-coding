#include <bits/stdc++.h>
using namespace std;


typedef pair<int, pair<int,int> > customPair;

vector<int> mergeKSortedArrays(vector<vector<int> > v)
{
	vector<int> result;
	priority_queue<customPair ,vector<customPair>, greater<customPair> > pq;
	for(int i=0;i<v.size();i++)
		pq.push({v[i][0],{i,0}});

	while(!pq.empty())
	{
		customPair curr = pq.top();
		pq.pop();
		int x = curr.second.first;
		int y = curr.second.second;
		result.push_back(curr.first);
		if( y + 1 < v[x].size())
			pq.push({v[x][y+1],{x,y+1}});
	}
	return result;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int k;cin>>k;
	vector<vector<int> > v = {{1,2,4,5},
							{1,9,13,19},
							{3,7,14,18,23}};

	vector<int> res = mergeKSortedArrays(v);
	for(auto x:res)
		cout<<x<<" ";
	return 0;
}
