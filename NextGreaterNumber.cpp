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
	int index = -1,curr = -1;
	int num = -1 ;
	for(int i= n-1;i>0;i--)
	{
		if(arr[i] > arr[i-1]){
			index = i-1;
			num = arr[index];
			curr = i;
			break;
		}
	}
	int min = 9999;
	int k= 0 ;
	for(int i=index + 1; i<n ; i++){
		if(arr[i] > num and arr[i] < min){
			k = i;
			min = arr[k];
		}
	}
	swap(&arr[index],&arr[k]);
	for (int low = curr , high = n - 1; low < high; low++, high--){
      swap(&arr[low], &arr[high]);
   }
	for(int i = 0;i<n;i++)
		cout<<arr[i]<<" ";
}