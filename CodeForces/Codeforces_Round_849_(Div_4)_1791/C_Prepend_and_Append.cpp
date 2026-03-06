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
	int c;
	
	vector<int>s;
	for(int i = 0 ;i<t;i++){
		cin>>n;
		s.clear();
		string a;
		cin>>a;
	for(char c:a){
		s.push_back(c-'0');
	}
		
		if (n==1)
		{
			cout<<1<<endl;
		}
		else
		{
			c=0;
			for (int j = 0; j < n; j++)
		{
			if (s[j]+s[n-(j+1)]!=1)
			{
				c=n-(j)-(j);
				break;
			}
			
		}
		cout<<c<<endl;
	}
		
		
	}
	
return 0;
}