#include <bits/stdc++.h>
using namespace std;

void setBit(int i,int &n){
	int mask = 1<<i;
	n = (n | mask);
}
void clearBit(int i,int &n)
{
	int mask = 1<<i;
	n = n^mask;
}
void clearLastiBits(int i,int &n){
	int mask = (~0) << i;
	n = n&mask;
}
void clearRangeOfBits(int i,int j,int &n){
	int mask = ((~0) << (j+1)) | (~((~0)<<(i)));
	n = n & mask;
}
void transform(int i,int j,int &n,int M)
{
	clearRangeOfBits(i,j,n);
	n = (M<<i) | n;
}
void decimalToBinary(int n)
{
	if(n > 0){
		int lastBit = n & 1;
		decimalToBinary(n>>1);
		cout<<lastBit;
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;cin>>n;
	// setBit(1,n);
	// cout<<n<<endl;
	// clearBit(1,n);
	// cout<<n<<endl;
	// clearLastiBits(3,n);
	// cout<<n;
	// clearRangeOfBits(1,3,n);
	// cout<<n<<endl;
	// transform(2,6,n,21);
	// cout<<n;	
	decimalToBinary(n);	
}