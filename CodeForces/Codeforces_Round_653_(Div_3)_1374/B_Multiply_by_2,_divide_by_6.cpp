#include <bits/stdc++.h>
#include <numeric>
using namespace std;
int main() {
	long long n;
	int t;
cin>>t;
	long long ans;
	int m;
	long long d;
	int b;
	int a;
	long long o;
	while(t--){
		ans=0;
		cin>>n;
		while (n!=1 )
		{
			if (n%6==0)
			{
				n/=6;
			}
			else if ((n*2)%6==0)
			{
				n*=2;
			}
			else
			{
				break;
			}
			ans+=1;
		}
		if (n==1)
		{
			cout<<ans<<endl;
		}
		else
		{
			cout<<-1<<endl;
		}
		
		
	}
		
		
	
return 0;
}