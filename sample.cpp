#include<bits/stdc++.h>
using namespace std;
int power(int x,int n)
{
	if(n==0)return 1;
	int temp = power(x,n/2);
	if(n % 2 ==0)return temp*temp;
	else{
		if(n>0)return temp*temp*x;
		else return (temp*temp)/x;
	}	
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int x;cin>>x;
	int n;cin>>n;
	cout<<power(x,n)<<endl;
}