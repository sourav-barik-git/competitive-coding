#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Graph
{
	map<T ,list<T> > l;

public:
	void addEdge(int x,int y)
	{
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void bfs(T src){
		map<T, int > visited;
		queue<T> q;
		q.push(src);
		visited[src] = true; 
		while(!q.empty()){
			T node = q.front();
			cout<<node<<" ";
			q.pop();

			for(T nbr : l[node])
			{
				if(!visited[nbr]){
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
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
	g.bfs(src);
	return 0;
}