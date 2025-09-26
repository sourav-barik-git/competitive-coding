#include <bits/stdc++.h>
using namespace std;

class Heap{
	vector<int> v;
	bool minHeap;
public:
	Heap(int default_size=10,bool type=true)
	{
		v.reserve(default_size);
		v.push_back(-1);
		minHeap = type;
	}
	bool compare(int p,int c){
		if(minHeap)
			return p > c;
		else
			return p < c;
	}
	void push(int ele)
	{
		v.push_back(ele);
		int idx = v.size() -1;
		int parent = idx / 2;
		while(idx > 1 and compare(v[parent],v[idx]))
		{
			swap(v[parent],v[idx]);
			idx = parent;
			parent = parent/2;
		}
	}
	void heapify(int idx)
	{
		int min_idx = idx;
		int last = v.size() - 1;
		int left = idx * 2;
		int right = left + 1;

		if(left <= last and compare(v[idx],v[left]))
			min_idx = left;
		else if(right <= last and compare(v[idx],v[right]))
			min_idx = right;

		if(idx != min_idx){
			swap(v[idx],v[min_idx]);
			heapify(min_idx);
		}

	}
	int top()
	{
		return v[1];
	}
	bool empty()
	{
		return v.size() == 1;
	}
	void pop()
	{
		int last = v.size() - 1;
		swap(v[1],v[last]);
		v.pop_back();
		heapify(1);
	}
	void show()
	{
		if(v.size() != 1)
			for(auto i = v.begin()+1 ; i!= v.end(); i++)
				cout<<*i<<" ";
		else
			cout<<"empty";
	}
};


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	Heap h(12);
	h.push(10);
	h.push(2);
	h.push(5);
	h.push(20);
	h.push(11);
	while(!h.empty())
	{
		cout<<h.top()<<" ";
		h.pop();
	}
	h.show();
}