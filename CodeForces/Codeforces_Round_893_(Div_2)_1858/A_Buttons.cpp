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
		cin>>a>>b>>c;
		if (a>b)
		{
			cout<<"First"<<endl;
		}
		else if (a<b)
		{
			cout<<"Second"<<endl;
		}
		else
		{
			if (c%2!=0)
			{
				cout<<"First"<<endl;
			}
			else
			{
				cout<<"Second"<<endl;
			}
			
		}
		
		
		
		
		
	}
	
	
return 0;
}