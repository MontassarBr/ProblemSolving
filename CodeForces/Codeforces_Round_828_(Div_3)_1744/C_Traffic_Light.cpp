#include <bits/stdc++.h>
#include <numeric>
using namespace std;
int main() {
	int n;
	int t;
cin>>t;
	int ans;
	int m;
	string s;
	int b;
	int a;
	char c;
	int d;
	int o;

while(t--){
		cin>>n>>c;
		cin>>s;
		s=s+s;
		int j;
		int p;
		ans=0;
		if(c=='g'){
			cout<<0<<endl;
		}
		else
		{
			for (int i = (n*2)-1; i >-1 ; i--)
			{
				if (s[i]=='g')
				{
					j=i;
				}
				if (s[i]==c && i<n)
				{
					ans=max(ans,j-i);
				}
			}
			cout<<ans<<endl;
		}
		
		
		}

return 0;
}