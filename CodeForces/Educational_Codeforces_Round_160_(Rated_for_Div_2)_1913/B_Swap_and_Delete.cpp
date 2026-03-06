#include <bits/stdc++.h>
#include <numeric>
using namespace std;
int main() {
	long long n;
	int t;
cin>>t;
	long long ans;
	int m;
	long long d;
	int b;
	int a;
	long long o;
	while(t--){
		string s;
		cin>>s;
		a=0;
		b=0;
		for (char c:s)
		{
			if (c=='0')
			{
				a++;
			}
			else
			{
				b++;
			}
		}
		ans=0;
		m=0;
		for (int i = 0 ;i<s.length();i++)
		{
			if (s[i]=='0')
			{
				b--;
				if (b<0)
				{
					ans=s.length()-i;
					m=1;
					break;
				}
				
			}
			else
			{
				a--;
				if(a<0)
				{
					ans=s.length()-i;
					m=1;
					break;
				}
				
			}
		}
		if (m && !ans)
		{
			cout<<1<<endl;
		}
		else
		{
			cout<<ans<<endl;
		}
		
		
	

	
	}
		
		
		
		
		
	
return 0;
}