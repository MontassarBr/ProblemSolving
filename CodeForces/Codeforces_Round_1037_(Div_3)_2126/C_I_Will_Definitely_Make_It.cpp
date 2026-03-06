#include <bits/stdc++.h>
#include <numeric>
using namespace std;
int main() {
	int n;
	int t;
cin>>t;
	string ans;
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
		ans="YES";
		int j=0;
		int c=v[a-1];
		sort(v.begin(),v.end());
		for (int i = n-1; i>-1; i--)
		{
			if (v[i]==c)
			{
				a=i;
				break;
			}
				
		}
		c=v[a];
		for (int i = a+1; i < n; i++)
		{
			if (v[i]==c)
			{
			
			}
			else if (j+abs(v[i]-c)>c)
			{
				ans="NO";
				break;
			}
			else
			{
				j+=abs(v[i]-c);
				c=v[i];
			}
			
		}
		cout<<ans<<endl;
		
		
	}

return 0;
}