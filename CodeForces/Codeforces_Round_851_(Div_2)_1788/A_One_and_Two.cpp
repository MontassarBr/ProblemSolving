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
			if (m==2)
			{
				c++;
			}
			
		}
		for (int j = 0; j < n; j++)
		{
			if (s[j]==2)
			{
				b++;
			}
			if (c%2==0 && b==c/2)
			{
				ans=j+1;
				break;
			}
			
		}
		
		cout<<ans<<endl;
	
		
		
	}
	
return 0;
}