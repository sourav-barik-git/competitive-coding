#include <bits/stdc++.h>
using namespace std;

#define N 11
int board[N][N];
bool flag = false;

void printSolution(int size){
	cout<<"[";
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			if(board[i][j])
				cout<<j+1<<" ";
	cout<<"] ";
}

int isSafe(int size,int row,int col){
	for(int i=row;i>=0;i--)
		if(board[i][col])
			return 0;

	for(int i=row,j=col;i>=0 and j>=0 ; i--,j--)
		if(board[i][j])
			return 0;

	for(int i=row,j=col;i>=0 and j<size;i--,j++)
		if(board[i][j])
			return 0;

	return 1;
}


int Nqueens(int size,int row){
	if(size == 1){
		cout<<"[1 ]";
		flag = true;
		return 0;
	}
	if(row >= size){
		printSolution(size);
		flag = true;
	}

	for(int index=0;index<size;index++){
		if(isSafe(size,row,index)){
			board[row][index] = 1;
			if(Nqueens(size,row+1))
				return 1;
			board[row][index] = 0;
		}
	}
	return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t;cin>>t;
	while(t--){
		int size;cin>>size;
		memset(board,0,sizeof(board));
		Nqueens(size,0);
		if(!flag) cout<<-1;
		flag = false;
		cout<<endl;
	}
}