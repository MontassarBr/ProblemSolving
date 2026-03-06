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
			cin>>n;
			vector <int>v;
			for (int i = 0; i < n; i++)
			{
				cin>>o;
				v.push_back(o);
			}
			m=0;
			for (int i = 1; i < n-1; i++)
			{
				if (v[i]>v[i+1] && v[i]>v[i-1])
				{
					cout<<"YES"<<endl;
					cout<<i<<' '<<i+1<<' '<<i+2<<endl;
					m=1;
					break;
				}
				
			}
			if (!m)
			{
				cout<<"NO"<<endl;
			}
			
			
	}
		
		
	
return 0;
}