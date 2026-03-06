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
	string s;
	
	for(int i = 0 ;i<t;i++){
		vector <int> occ(26);
		int p=0;
		fill(occ.begin(),occ.end(),0);
		cin>>n>>m;
		cin>>s;
		for(char c : s){
			occ[c-'a']++;
		}
		for(int el : occ){
			if (el%2!=0)
			{
				p++;
			}
		}
		if (m-p>=-1)
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