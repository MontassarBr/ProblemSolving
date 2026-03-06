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
		ans=0;
		for (int j = 0; j < n; j++)
		{
			cin>>m;
			s.push_back(m);
		}
		for (int j = 1; j < n; j++)
		{
			if ((s[j]%2==0 && s[j-1]%2==0)||(s[j]%2==1 && s[j-1]%2==1))
			{
				ans++;
			}
			
		}
		cout<<ans<<endl;
	}
	
return 0;
}