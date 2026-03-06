#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	int t;
cin>>t;
	int ans;
	int m;
	int d;
	int b;
	int a;
	int o;

	for(int i = 0 ;i<t;i++){
		cin>>n;
		vector <int>v;
		for (int j = 0; j < n; j++)
		{
			cin>>o;
			v.push_back(o);
		}
		int c=INT_MIN;
		if (n==1)
		{
			cout<<0<<endl;
			continue;
		}
		
		for (int j = 0; j < n-1; j++)
		{
			c=max(c,v[j]-v[j+1]);
		}
		
		
		for (int j = 0; j < n-1; j++)
		{
			c=max(c,v[n-1]-v[j]);
		}
			for (int j = 1; j < n; j++)
		{
			c=max(c,v[j]-v[0]);
		}
		
		cout<<c<<endl;
		
	}
	
	
return 0;
}