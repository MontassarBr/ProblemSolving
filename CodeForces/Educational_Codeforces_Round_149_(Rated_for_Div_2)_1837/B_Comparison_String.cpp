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
	
	for(int i = 0 ;i<t;i++){
		cin>>n;
		a=1;
		ans=1;
		string s;
		cin>>s;
		for (int j = 1; j < n; j++)
		{
			if (s[j]==s[j-1])
			{
				a++;
				ans=max(ans,a);
			}
			else
			{
				a=1;
			}
		}
		cout<<ans+1<<endl;
		
		
		
	}
	
	
return 0;
}