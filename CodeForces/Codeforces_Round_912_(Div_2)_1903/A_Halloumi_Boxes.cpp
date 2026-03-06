#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int t;
	int r;
	int o;
	vector<int>p(100);
	cin>>t;
	for(int i = 0 ;i<t;i++){
		cin>>n>>r;
		p.clear();
		for (int j = 0; j < n; j++)
		{
			cin>>o;
			p.push_back(o);
		}
		if (n==1)
		{
			cout<<"YES"<<endl;
		}
		else if (r==1 && n!=1)
		{
			if (is_sorted(p.begin(),p.end()))
			{
				cout<<"YES"<<endl;	
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}
		else
		{
			cout<<"YES"<<endl;
		}
	
		
		
	}
	
return 0;
}