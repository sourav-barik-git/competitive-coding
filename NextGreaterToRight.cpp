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
	for(int i=0;i<n;i++)
		cin>>arr[i];
	stack<int> s;
	int result[n];
	s.push(0);
	for(int i=1;i<n;i++)
	{
		if(!s.empty()){
			int curr = s.top();
			s.pop();
			while(arr[i] > arr[curr] ){
				result[curr] = arr[i];
				if(s.empty())
					break;
				curr = s.top();
				s.pop();
			}
			if(arr[i] < arr[curr])
				s.push(curr);
		}
		s.push(i);
	}
	while(!s.empty()){
		result[s.top()] = -1;
		s.pop();
	}

	for(int i = 0;i<n;i++)
		cout<<result[i]<<" ";
}