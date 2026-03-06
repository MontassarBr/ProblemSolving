#include <bits/stdc++.h>

using namespace std;

int main() {
	int r=0;
	int n;
	pair<int,int> m;
	int t;
	cin>>n;
	vector<pair<int,int>>v;
	for(int i =0 ;i<n;i++){
		cin>>m.first;
		v.push_back(m);
	}
	for(int i =0 ;i<n;i++){
		cin>>v[i].second;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (((v[i].first-v[j].first)*(v[i].first-v[j].first))+((v[i].second-v[j].second)*(v[i].second-v[j].second))>r)
			{
				r=(v[i].first-v[j].first)*(v[i].first-v[j].first)+(v[i].second-v[j].second)*(v[i].second-v[j].second);
			}
		}
	}
	
	cout<<r;
	
	return 0;
}