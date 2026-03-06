#include <bits/stdc++.h>
#include <numeric>
using namespace std;
int main() {
	int n;
	int t;
t=1;
	long long ans;
	int m;
	string s;
	int b;
	int a;
	char c;
	int d;
	int o;

while(t--){
		cin>>n>>a;
		ans=0;
		vector<int>v;
		for (int i = 0; i < n; i++)
		{
			cin>>o;
			v.push_back(o);
		}
		sort(v.begin(),v.end());
		b=0;
		int i=n-1;
		while (1)
		{
			if (v[i]>a)
			{
				n--;
			}
			else 
			{
				n-=(a/v[i])+1;
				
			}
			if(n<0){
					break;
			}
			i--;
			ans+=1;
		}
		
		cout<<ans<<endl;
		
		}

return 0;
}