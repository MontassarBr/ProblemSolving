#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int t;
	cin>>t;
	int ans;
	int m;
	int f;
	int b;
	int c;
	int a;
	for(int i = 0 ;i<t;i++){
		cin>>n;
		a=0;
		for (int j = 0; j < n; j++)
		{
			cin>>b;
			a+=b;
		}
		if (a%2==0)
		{
			cout<<"YES"<<endl;
		}
		else
		{
					cout<<"NO"<<endl;
		}
		
		
		
		
		
		
	}
	
	
return 0;
}