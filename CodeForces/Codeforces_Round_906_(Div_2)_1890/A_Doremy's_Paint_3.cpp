#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int t;
	vector <int>v;
	cin>>t;
	int o;
	vector<int> occ(10e5+1);
	for(int i = 0 ;i<t;i++){
		cin>>n;
		v.clear();
		fill(occ.begin(),occ.end(),0);
		set<int>s;
		for (int j = 0; j < n; j++)
		{
			cin>>o;
			v.push_back(o);
			occ[o]++;
		}
		int p=0;
		for (int j = 0; j < 100000+1; j++)
		{
			if (occ[j]!=0)
			{
				p++;
				s.insert(j);
			}
		}
		
		if (p>2)
		{
			cout<<"NO"<<endl;
		}
		else if (p==1)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			if (n%2==0 && occ[*s.begin()]==occ[*s.rbegin()])
			{
				cout<<"YES"<<endl;
			}
			else if (n%2!=0 && abs(occ[*s.begin()]-occ[*s.rbegin()])==1)
			{
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
			
		}
	}
	
return 0;
}