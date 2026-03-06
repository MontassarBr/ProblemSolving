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
		int te=0;
		for(int   j =0 ; j<n;j++){
			if (v[j]<j)
			{
				te=1;
			}
			
		}
		if (te)
		{
			cout<<-1<<endl;
		}
		else
		{
			
		
		
		
		int test =0;
		for(int   j =0 ; j<n-1;j++){
			if (v[j]==v[j+1])
			{
				test=1;
				break;
			}
			
		}
		
		if (is_sorted(v.begin(),v.end()) && !test)
		{
			cout<<0<<endl;
		}
		else
		{
			ans=0;
			for (int j = n-1; j >0 ; j--)
			{	if (ans==-1)
				{
					break;
				}
				while (v[j]<=v[j-1])
				{
					v[j-1]/=2;
					ans++;
					if (v[j]==0)
					{
						ans=-1;
						break;
					}
					
				}
			
				
			}
			cout<<ans<<endl;
		}
		
	}
		}
		
	
return 0;
}