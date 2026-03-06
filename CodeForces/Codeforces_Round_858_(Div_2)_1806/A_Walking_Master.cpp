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
	int a;
	vector<int>v;
	for(int i = 0 ;i<t;i++){
		cin>>a>>b>>c>>d;
		ans=0;
		if(d<b || c-a>d-b){
			cout<<-1<<endl;
		}
		else
		{
			while (b!=d)
			{
				b++;
				a++;
				ans++;
			}
			ans+=abs(a-c);
			cout<<ans<<endl;
		}
		
		
		
	}
	
return 0;
}