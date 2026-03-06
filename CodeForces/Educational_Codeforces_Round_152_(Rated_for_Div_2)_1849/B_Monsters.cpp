#include <bits/stdc++.h>
#include <numeric>
using namespace std;
int main() {
	int n;
	int t;
cin>>t;
	long long ans;
	int m;
	long long d;
	int b;
	int a;
	int o;
while(t--){
		priority_queue<pair<int,int>>p;
		cin>>n>>a;
		ans=0;
		vector<int>v;
		pair<int,int>pp;
		for (int i = 0; i < n; i++)
		{
			cin>>o;
			o=o%a;
			if (o==0)
			{
				o=a;
			}
			pp.first=o;

			pp.second=(n-(i+1));
			p.push(pp);	
		}
		while (!p.empty())
		{
			pp=p.top();
			p.pop();
			pp.first-=a;
			if (pp.first>0)
			{
				p.push(pp);
			}
			else
			{
				v.push_back(n-pp.second);
			}
		}
		for (int i = 0; i < n-1; i++)
		{
			cout<<v[i]<<' ';
		}
		cout<<v[n-1]<<endl;
		
	}

return 0;
}