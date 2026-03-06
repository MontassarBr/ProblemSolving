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
		cin>>s;
		a=0;
		b=0;
		for(int i=1 ; i<s.length() ; i++){
			if (s[i]=='b' && s[i-1]=='a')
			{
				a+=1;
			}
			else if (s[i]=='a' && s[i-1]=='b')
			{
				b+=1;
			}
		}
		if (a>b)
		{
			cout<<'b'<<s.substr(1)<<endl;
		}
		else if (b>a)
		{
			cout<<s.substr(0,s.length()-1)<<'b'<<endl;
		}
		else
		{
			cout<<s<<endl;
		}
		
		
	}
		
		
		
		
	
return 0;
}