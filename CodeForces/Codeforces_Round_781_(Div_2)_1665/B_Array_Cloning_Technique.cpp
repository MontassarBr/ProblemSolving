#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	int t;
cin>>t;
	int ans;
	int m;
	int d;
	int b;
	int a;
	int o;

	for(int i = 0 ;i<t;i++){
		cin>>n;
		vector<int>v;
		for(int   j =0 ; j<n;j++){
			cin>>o;
			v.push_back(o);
		}
		sort(v.begin(),v.end());
		m=1;
		ans=1;
		for (int j = 1; j <n; j++)
		{
			if (v[j]==v[j-1])
			{
				m++;
				ans=max(ans,m);
			}
			else
			{
				m=1;
			}
		}
	int c=0;
	int r=0;
	a=ans;
		while (c<n-a)
		{
			c+=ans;
			ans*=2;
			r+=1;
		}
		cout<<(n-a)+r<<endl;
		}
		
	
return 0;
}