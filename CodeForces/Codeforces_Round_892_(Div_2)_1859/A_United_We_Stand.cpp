#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int t;
	cin>>t;
	int ans;
	int m;
	int f;
	vector<int>b;
	vector<int>c;
	vector<int>a;
	for(int i = 0 ;i<t;i++){
		a.clear();
		b.clear();
		c.clear();
		cin>>n;
		for (int j = 0; j < n; j++)
		{
			cin>>m;
			a.push_back(m);
		}
		sort(a.begin(),a.end());
		f=a[0];
		if (a[0]==a[n-1])
		{
			cout<<-1<<endl;
		}
		else
		{
			int p=0;
			while (f==a[p])
			{
				b.push_back(a[p]);
				p++;
			}
			while (p<n)
			{
				c.push_back(a[p]);
				p++;
			}
			cout<<b.size()<<' '<<c.size()<<endl;
			for(int e =0;e<b.size()-1;e++){
				cout<<b[e]<<' ';
			}
			cout<<b[b.size()-1]<<endl;
			for(int e =0;e<c.size()-1;e++){
				cout<<c[e]<<' ';
			}
			cout<<c[c.size()-1]<<endl;
		}
		
		
		
	}
	
	
return 0;
}