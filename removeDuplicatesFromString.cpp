#include <bits/stdc++.h>
using namespace std;

void removeDuplicates(char c[])
{
	int l =  strlen(c);
	int prev = 0;
	for(int curr = 1; curr < l; curr++)
		if(c[prev] != c[curr])
			c[++prev] = c[curr];
	c[prev+1] = '\0';
	cout<<c;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	char c[1000];
	cin.getline(c,1000);
	removeDuplicates(c);
	return 0;
}
