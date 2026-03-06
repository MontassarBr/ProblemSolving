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
	vector<int> v;
	for(int i = 0 ;i<t;i++){
		cin>>n;
		v.clear();
		for (int j = 0; j < n; j++)
		{
			cin>>b;
			v.push_back(b);
		}
		if (n==2)
		{
			if (v[0]<=v[1])
			{
				cout<<min(v[0],v[1])*2<<endl;
			}
			else
			{
				cout<<v[0]+v[1]<<endl;
			}
						
		}
		else
		{
		
			cout<<min(v[0]+v[1],v[0]+min(v[0],v[1]))<<endl;

		}	
	}
	
	
return 0;
}