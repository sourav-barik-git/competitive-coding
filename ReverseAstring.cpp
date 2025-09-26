#include<bits/stdc++.h>
using namespace std;
void swap(char *x,char *y)
{
	char temp = *x;
	*x = *y;
	*y = temp;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	string s;
	getline(cin,s);
	int l = s.length();
	char arr[l];
	strcpy(arr,s.c_str());

	int low = 0 , high = l - 1;
	for(int low = 0 , high = l - 1;low<high ; low++ , high--)
		swap(&arr[low],&arr[high]);
	for(int i=0;i<l;i++)
		cout<<arr[i]<<" ";	
}