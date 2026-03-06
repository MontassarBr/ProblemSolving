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
		c=0;
		for (int j = 0; j < n; j++)
		{
			cin>>b;
			if(b==0){
				a++;
			}
			else
			{
				c=max(c,a);
				a=0;
			}
			
		
		}
		cout<<max(a,c)<<endl;
	}
	
return 0;
}