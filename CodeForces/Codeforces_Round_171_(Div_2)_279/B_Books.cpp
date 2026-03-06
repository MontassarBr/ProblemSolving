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
		m=0;
		int j=0;
		int s=0;
		for (int i = 0; i < n; i++)
		{
			while (j<n && s+v[j]<=a)
			{
				s+=v[j];
				j++;
			}
			m=max(m,(j-i));
			s-=v[i];
		}
		
		cout<<m<<endl;
		
		
	

	

		
		
		
		
		
	
return 0;
}