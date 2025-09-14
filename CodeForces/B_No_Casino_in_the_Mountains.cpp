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
		vector <int>v;
		cin>>n>>a;
		for (int i = 0; i < n; i++)
		{
			cin>>o;
			v.push_back(o);
		}
		ans=0;
		int j=0;
		for (int i = 0; i < n; i++)
		{
			if (v[i]==0)
			{
				j++;
				if (j==a)
				{
					ans++;
					j=0;
					i++;
				}
			}
			else
			{
				j=0;
			}
		}
		cout<<ans<<endl;
		
		
	}
		
		
	

	

		
		
		
		
		
	
return 0;
}
