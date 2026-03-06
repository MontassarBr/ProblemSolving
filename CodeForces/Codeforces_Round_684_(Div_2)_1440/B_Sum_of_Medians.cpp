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
			for (int i = 0; i < n*a; i++)
			{
				cin>>o;
				v.push_back(o);
			}
			m=(n/2)+n%2;
			ans=0;
			if (n%2!=0)
			{
			b=0;
			for (int i = (n*a)-(m); i >-1; i-=m)
			{
				ans+=v[i];
				b++;
				if (b==a)
				{
					break;
				}
			}
			}
			else{
			b=0;
			for (int i = (n*a)-(m+1); i > -1; i-=(m+1))
			{
				ans+=v[i];
				b++;
				if (b==a)
				{
					break;
				}
				
			}
			}
			cout<<ans<<endl;
			
	}
		
		
	
return 0;
}