#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	int t;
cin>>t;
	long long ans;
	int m;
	int d;
	int b;
	int a;
	vector<int> v;
	for(int i = 0 ;i<t;i++){
		cin>>a>>b>>n;
		ans=0;
		for (int j = 0; j < n; j++)
		{
			cin>>m;
			ans+=min(a-1,m);
		}
		cout<<ans+b<<endl;
		
		
	}
	
	
return 0;
}