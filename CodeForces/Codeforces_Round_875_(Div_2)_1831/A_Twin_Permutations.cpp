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
		cin>>n;
		v.clear();
		a=0;
		for (int j = 0; j < n; j++)
		{
			cin>>b;
			v.push_back(b);
		}
		for(int e=0;e<n-1;e++){
			cout<<(n+1)-v[e]<<' ';
		}
		cout<<(n+1)-v[n-1]<<endl;

	}
	
	
return 0;
}