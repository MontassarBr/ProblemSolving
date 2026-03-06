#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int t;
	int r;
	int o;
	int p;
	vector<int>v(50);
	cin>>t;
	for(int i = 0 ;i<t;i++){
		cin>>n>>r;
		v.clear();
		p=0;
		v.push_back(0);
		for (int j = 0; j < n; j++)
		{
			cin>>o;
			v.push_back(o);
		}

			for (int j = 1; j < n+1; j++)
		{
			if(v[j]-v[j-1]>p){
				p=v[j]-v[j-1];
			}
		}
		
		cout<<max(p,(r-v[v.size()-1])*2)<<endl;
		
		
		
		
	
		
		
	}
	
return 0;
}