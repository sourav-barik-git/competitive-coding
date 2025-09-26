#include <bits/stdc++.h>
#define pb push_back
using namespace std;

template<typename T>

class Graph{
	map<T, list<T> > m;
public:
	void addEdge(int x,int y){
		m[x].pb(y);
		m[y].pb(x);
	}
	void dfs_helper(T src,map<T,bool > &visited){
		cout<<src<<" ";
		visited[src] = true;
		for(T nbr : m[src]){
			if(!visited[nbr]){
				dfs_helper(nbr,visited);
			}
		}
	}
	void dfs(int src){
		map<T,bool > visited;
		//Make every node unvisited first
		for(auto i:m){
			T node = i.first;
			visited[node] = false;
		}
		dfs_helper(src,visited);

	}
};


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	Graph<int> g;
	int n;cin>>n;
	int a ,b;
	while(n--){
		cin>>a>>b;
		g.addEdge(a,b);
	}
	int src;cin>>src;
	g.dfs(src);
	return 0;

	
}