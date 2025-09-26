#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;cin>>n;
	int arr[n];
	int maxSum = 0,currSum=0,end=-1,start=-1;
	
	for(int i=0;i<n;i++) {
		cin>>arr[i];
		currSum += arr[i];
		if(currSum < 0)
			currSum = 0;
		else if(currSum > maxSum){
				maxSum = currSum;
				end = i;
		}
	}
	currSum = 0;
	for(int i = end;i >=0 ; i--){
		currSum += arr[i];
		if(currSum == maxSum){
			start = i;
			break;
		}
	}
	cout<<"Maximum sub array sum is :"<<maxSum<<" with index "<<start<<","<<end<<endl;

}