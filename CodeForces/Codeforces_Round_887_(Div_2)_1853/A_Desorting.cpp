#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int t;
	cin>>t;
	int ans;
	int m;
	int f;
	int b;
	int c;
	int a;
	vector<int>v;
	for(int i = 0 ;i<t;i++){
		cin>>n;
		v.clear();
		for (int j = 0; j < n; j++)
		{
			cin>>b;
			v.push_back(b);
		}
		if (!is_sorted(v.begin(),v.end()))
		{
			cout<<0<<endl;
		}
		else
		{
			m=INT_MAX;
			for (int j = 1; j < n; j++)
			{
				m=min((v[j]-v[j-1]),m);
			}
			cout<<(m/2)+1<<endl;
		}
		
		
		
		
		
		
	}
	
	
return 0;
}