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

	for(int i = 0 ;i<t;i++){
		vector<int>v;
		for(int   j =0 ; j<3;j++){
			cin>>o;
			v.push_back(o);
		}
		if (((v[1]-(v[2]-v[1]))%v[0]==0 && (v[1]-(v[2]-v[1]))/v[0]>0) || ((v[2]-((v[2]-v[0])/2))%v[1]==0 && (v[2]-((v[2]-v[0])/2))/v[1]>0  &&  (v[2]-v[0]) %2==0) || ((v[1]+(v[1]-v[0]))%v[2]==0 && (v[1]+(v[1]-v[0]))/v[2]>0))
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