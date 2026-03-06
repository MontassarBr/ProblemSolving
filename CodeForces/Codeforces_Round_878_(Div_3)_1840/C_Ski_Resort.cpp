#include <bits/stdc++.h>
#include <numeric>
using namespace std;
int main() {
	int n;
	int t;
cin>>t;
	long long ans;
	int m;

	int b;
	int a;
	long long c;
	int d;
	int o;
while(t--){
		cin>>n>>a>>b;
		vector <int>v1;
		c=0;
		ans=0;
		for (int i = 0; i < n; i++)
		{
			cin>>o;
			if (o<=b)
			{
				c++;
			}
			else
			{
				if (c>=a)
				{
					ans+=(c-a+1)*(c-a+2)/2;
				}
				c=0;
			}
		}
		if (c>=a)
				{
					ans+=(c-a+1)*(c-a+2)/2;
				}
			cout<<ans<<endl;
			
		}

return 0;
}