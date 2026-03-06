#include <bits/stdc++.h>
#include <numeric>
using namespace std;
int main() {
	long long n;
	int t;

	long long ans;
	int m;
	long long d;
	int b;
	int a;
	int o;

		vector <int>v;
		cin>>n;
		for (int i = 0; i <n; i++)
		{
			cin>>o;
			v.push_back(o);
		}
		cin>>a;
		sort(v.begin(),v.end());
		for (int i = 0; i < a; i++)
		{
			cin>>o>>b;
			cout<<upper_bound(v.begin(),v.end(),b)-lower_bound(v.begin(),v.end(),o)<<endl;
			
			
		}
		
		
		
	

	

		
		
		
		
		
	
return 0;
}