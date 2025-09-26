#include<bits/stdc++.h>
using namespace std;
void swap(int *x,int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
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

	stack<int > s;
	s.push(0);
	int count = 0;
	for(int low=0,high=n-1;low<high;low++,high--)
		swap(&arr[low],&arr[high]);
	for(int i = 1;i<n;i++)
	{
		while( !s.empty() and arr[i] >= arr[s.top()])
			s.pop();
		count+= s.empty()?i:(i - s.top() - 1);
		s.push(i);
	}
	cout<<count;

}