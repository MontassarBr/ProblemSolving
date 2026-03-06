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
	int c;
	vector<int>s;
	for(int i = 0 ;i<t;i++){
		cin>>n;
		s.clear();
		c=0;
		b=0;
		ans=-1;
		for (int j = 0; j < n; j++)
		{
			cin>>m;
			s.push_back(m);
		}
		sort(s.begin(),s.end());
		reverse(s.begin(),s.end());
	
		
	
		if (s[0]==s[n-1])
		{
			cout<<"NO"<<endl;
		}
		else
		{
			while (s[0]==s[1])
		{
			b=s[0];
			s[0]=s[n-1];
			s[n-1]=b;
		}
			cout<<"YES"<<endl;
			for(int j=0;j<n-1;j++){
				cout<<s[j]<<' ';
			}
			cout<<s[n-1]<<endl;
		}
	}
	
return 0;
}