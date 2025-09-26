#include<bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;cin>>n;
	int arr[n];
	int total = 0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		total += arr[i];
	}

	int transfers = 0;

	if(total % n != 0){
		cout<<-1<<endl;
		exit(0);
	}
	int load =  total/n;
	int net = 0;
	for(int i=0;i<n;i++)
	{
		net += (arr[i] - load);
		transfers = max(abs(net),transfers);
	}
	cout<<transfers;
	return 0;
}