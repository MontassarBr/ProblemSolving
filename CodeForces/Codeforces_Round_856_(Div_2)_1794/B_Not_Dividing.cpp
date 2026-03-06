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
		int c=2;
		for (int j = 0; j < n; j++)
		{
			if (v[j]==1)
			{
				v[j]++;
			}
			
		}
		
		for (int j = 1; j < n; j++)
		{
			if (v[j]%v[j-1]==0)
			{
				v[j]++;
			}
				
				
			}
	
		for (int j = 0; j < n-1; j++)
		{
		cout<<v[j]<<' ';
		}
		cout<<v[n-1]<<endl;
		
	}
	
	
return 0;
}