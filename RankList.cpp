#include<bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;cin>>n;
	int count_arr[n+1] = {0};
	string name;
	int num;

	for(int i=0;i<n;i++)
	{
		cin>>name>>num;
		count_arr[num]++;
	}
	int badness = 0;
	int ix = 1;
	int rank = 1;

	while(ix <= n)
	{
		while(count_arr[ix] > 0){
			badness += abs(rank - ix);
			count_arr[ix] -= 1;
			rank++;
		}
		ix++;
	}
	cout<<badness;
	return 0;
}