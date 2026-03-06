#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int t;
	cin>>t;
	int o;
	for(int i = 0 ;i<t;i++){
		cin>>n;
		o=0;
		if ((n-1)%4==3)
		{
			cout<<"Bob"<<endl;
		}
		else
		{
			cout<<"Alice"<<endl;
		}
	}
		
return 0;
}