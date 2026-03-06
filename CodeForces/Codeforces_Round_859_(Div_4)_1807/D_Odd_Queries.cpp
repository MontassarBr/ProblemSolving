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
		cin>>n>>b;
		vector <int>v;
		v.push_back(0);
		for (int j = 1; j <= n; j++)
		{
			cin>>o;
			v.push_back(o);
		}
		for (int j = 1; j <= n; j++)
		{
			v[j]+=v[j-1];			
		}

		for (int j = 0; j < b; j++)
		{
			cin>>a>>m>>d;
			ans=(v[a-1]+(v[n]-v[m])+((m-a)+1)*d)%2;
			if (ans)
			{
				cout<<"YES"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
			
			
		}
		
		
		
	}
	
	
return 0;
}