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
	vector<int> v;
	for(int i = 0 ;i<t;i++){
		cin>>n;
		d=0;
		a=0;
		v.clear();
		for (int j = 0; j < n; j++)
		{
			cin>>b;
			v.push_back(b);
		}
		for (int j = 1; j < n; j++)
		{
			if (v[j]<v[j-1])
			{
				a=v[j-1];
				d=v[j];
				break;
			}
		}
		if(!d){
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
			cout<<2<<endl;
			cout<<a<<' '<<d<<endl;
		}
		
		
		
		
		
		
		
	}
	
	
return 0;
}