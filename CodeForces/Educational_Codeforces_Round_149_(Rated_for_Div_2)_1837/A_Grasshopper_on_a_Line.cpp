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
	vector<int>v;
	for(int i = 0 ;i<t;i++){
		cin>>n>>c;
		if (n%c!=0)
		{
			cout<<1<<endl;
			cout<<n<<endl;
		}
		else
		{
			cout<<2<<endl;
			cout<<c+1<<' '<<n-(c+1)<<endl;
			
		}
		
		
		
		
		
		
		
		
		
		
		
		
	}
	
	
return 0;
}