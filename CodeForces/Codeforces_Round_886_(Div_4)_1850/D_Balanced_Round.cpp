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
	
	for(int i = 0 ;i<t;i++){
		cin>>n>>m;
		a=0;
		ans=0;
		vector<int> v;
		for (int j = 0; j < n; j++)
		{
			cin>>b;
			v.push_back(b);
		}
		sort(v.begin(),v.end());
		for (int j = 1; j < n; j++)
		{
			if (v[j]-v[j-1]<=m)
			{
				a++;
				ans=max(ans,a);
			}
			else
			{
				a=0;
			}
		}
		cout<<(n-ans)-1<<endl;
		
		
		
	}
	
	
return 0;
}