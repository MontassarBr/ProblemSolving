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
		cin>>n>>a;
		for (int i = 0; i <n; i++)
		{
			cin>>o;
			v.push_back(o);
		}
		for (int i = 0; i < a; i++)
		{
			cin>>o;
			if (binary_search(v.begin(),v.end(),o))
			{
				cout<<"YES"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
			
			
		}
		
		
		
	

	

		
		
		
		
		
	
return 0;
}