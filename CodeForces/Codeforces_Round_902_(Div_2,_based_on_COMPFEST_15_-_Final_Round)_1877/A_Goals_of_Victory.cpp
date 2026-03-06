#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int t;
	cin>>t;
	int ans;
	int m;
	int f;
	vector <int>v(101);
	for(int i = 0 ;i<t;i++){
		ans=0;
		cin>>n;
		for (int j = 0; j < n-1; j++)
		{
			cin>>m;
			ans+=m;
		
		}
		cout<<-ans<<endl;

	}
		
return 0;
}