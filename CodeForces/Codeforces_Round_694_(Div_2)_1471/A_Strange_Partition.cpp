#include <bits/stdc++.h>
#include <numeric>
using namespace std;
int main() {
	long long n;
	int t;
cin>>t;
	long long ans;
	int m;
	long long d;
	int b;
	int a;
	long long o;
	while(t--){
			cin>>n>>a;
			vector <int>v;
			b=0;
			ans=0;
			d=0;
			for (int i = 0; i < n; i++)
			{
				cin>>o;
				v.push_back(o);
				if (o%a!=0)
				{
					b++;
				}
				ans+=o/a;
				d+=o;
			}
			if (d%a==0)
			{
				d=d/a;
			}
			else
			{
				d=(d/a)+1;
			}
			cout<<d<<' '<<ans+b<<endl;
			
			
	}
		
		
	
return 0;
}