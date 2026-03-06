#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int t;
	cin>>t;
	int ans;
	int m;
	int f;
	queue <int>a;
	for(int i = 0 ;i<t;i++){
		ans=0;
		cin>>n;
		cin>>m;
		a.push(m);
		for (int j = 1; j < n; j++)
		{
			cin>>m;
			if(a.back()>m){
				a.push(m);
			}
			a.push(m);
		
		}
		cout<<a.size()<<endl;
		while (a.size()!=1)
		{
			cout<<a.front()<<' ';
			a.pop();
		}
		cout<<a.front();
			a.pop();
		cout<<endl;

	}
	
	
return 0;
}