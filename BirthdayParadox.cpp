#include<bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	float p;cin>>p;
	if(p==1.0)
	{
		cout<<366<<endl;
		return 0;
	}
	int people = 0;
	float num = 365,den=365;
	float x = 1.0;
	while(x > 1-p)
	{
		x = (x*num)/den;
		num--;
		people++;
	}
	cout<<people<<endl;
	return 0;
}