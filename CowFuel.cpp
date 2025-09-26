#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1,pair<int, int> p2)
{
	return p1.first > p2.first;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;cin>>n;
	int arr[n];
	int D,F;cin>>D>>F;
	priority_queue<int> pq;
	vector<pair<int, int> > v;

	int d,f;

	for(int i=0;i<n;i++)
	{
		cin>>d>>f;
		v.push_back(make_pair(d,f));

	}
	//sort(v.begin(),v.end(),compare);

	int ans = 0;
	int prev = 0;
	int i = 0;

	while(i < n)
	{
		if(F >= (v[i].first - prev))
		{
			F -= (v[i].first - prev);
			pq.push(v[i].second);
			prev =  v[i].first;
		}
		else{
			if(pq.empty()){
				cout<<"Error in input!";
				return 0;
			}
			F = pq.top();
			pq.pop();
			ans += 1;
			continue;
		}
		i++;
	}
	if(F >= (D-prev)){
		cout<<ans;
		return 0;
	}
	while(F < (D-prev)){
		if(pq.empty())
		{
			cout<<"Error";
			return 0;
		}
		F = pq.top();
		pq.pop();
		ans++;
	}
	cout<<ans;
	return 0;
}