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
	int o;
	while(t--){
		vector <int>v;
		cin>>n>>a;
		m=7;
		b=0;
		for (int i = 0; i <n; i++)
		{
			cin>>o;
			v.push_back(o);
			if (o%a==0)
			{
				m=0;
			}
			if (o%2==0 && b<2)
			{
				b++;
			}
				
		
			m=min(m,a-(o%a));
		}
		if ((a==4 && m>1) || (b==2 && a==4))
		{
			cout<<2-b<<endl;
		}
		else
		{
			cout<<m<<endl;
		}
		
		
	

	
	}
		
		
		
		
		
	
return 0;
}