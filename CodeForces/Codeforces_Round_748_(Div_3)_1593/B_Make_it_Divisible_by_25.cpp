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
	while(t--){
		string s;
		int s1=0;
		int s2=0;
		ans=0;
		cin>>s;
		for (int i=s.length()-1;i>-1;i--)
		{
			if ((s1 && (s[i]=='0' || s[i]=='5'))||(s2 && (s[i]=='7' || s[i]=='2')))
			{
				break;
			}
			else if (s[i]=='0' && !s1)
			{
				s1=1;
			}
			else if (s[i]=='5' && !s2)
			{
				s2=1;
			}
			ans++;
		}
		
		cout<<ans-1<<endl;
	}
		
		
		
		
	
return 0;
}