#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int t;
	cin>>t;
	string ans;
	int m;
	int f;
	vector <int>v(101);
	for(int i = 0 ;i<t;i++){
		ans="NO";
		cin>>n>>f;
		for (int j = 0; j < n; j++)
		{
			cin>>m;
			if (m==f)
			{
				ans="YES";
			}
		
		}
		cout<<ans<<endl;

	}
		
return 0;
}