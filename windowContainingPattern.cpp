#include <bits/stdc++.h>
using namespace std;

string find_window(string pat,string s){
	int SL = s.length(),PL = pat.length();
	if(PL > SL) return "None";

	int ctr = 0,window_len,min_len=INT_MAX,start_ix=-1,start=0;
	
	int FP[256] = {0},FS[256] = {0};

	for(int i=0;i<PL;i++) FP[pat[i]]++;

	for(int i=0;i<SL;i++){
		char ch = s[i];
		FS[ch]++;

		if(FS[ch] <= FP[ch] and FP[ch] != 0) ctr++;

		//found a window
		if(ctr == PL){
			//make it shrink to become the minimum
			char temp = s[start];
			while(FP[temp]==0 or FS[temp] > FP[temp]){
				FS[temp]--;
				start++;
				temp = s[start];
			}
			window_len = i - start + 1;
			if(window_len < min_len){
				min_len = window_len;
				start_ix = start;
			}
		}
	}
	if(start_ix == -1) return "None";
	string ans = s.substr(start_ix,min_len);
	return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t;cin>>t;
	while(t--){
	   string s,p;
	   cin>>s>>p;
	   cout<<find_window(p,s)<<endl;
	}
}