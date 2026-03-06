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
	vector<int>s;
	for(int i = 0 ;i<t;i++){
		cin>>n>>a>>b;
		if (a==b && a==n)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			if (n-(a+b)>=2)
			{
				cout<<"YES"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
			
			
		}
		
	}
	
	
return 0;
}