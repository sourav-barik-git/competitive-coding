#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	stack < int > s;
	s.push(0);
	cout<<"0"<<" ";
	int count = 0;
	for(int i=1;i<n;i++)
	{
		while(!s.empty() and a[i] >= a[s.top()])
			s.pop();	
		count = s.empty()?i:(i-s.top()-1);
		s.push(i);
		cout<<count<<" ";
	}
}