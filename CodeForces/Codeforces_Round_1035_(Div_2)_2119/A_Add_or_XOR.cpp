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
	vector<int>s;
	for(int i = 0 ;i<t;i++){
		cin>>a>>b>>m>>d;
		if (a-b>1 || (a>b)&& a%2==0)
		{
			cout<<-1<<endl;
		}
		else
		{
			if (a-b==1)
			{
				cout<<d<<endl;
			}
			
			else if(m<=d)
			{
				cout<<(b-a)*m<<endl;
			}
			else
			{
				int p=0;
				for (int j = a; j < b; j++)
				{
					if (j%2==0)
					{
						p+=d;
					}
					else
					{
						p+=m;
					}
					
				}
				
				cout<<p<<endl;
			}
			
			
		}
		
	}
	
	
return 0;
}