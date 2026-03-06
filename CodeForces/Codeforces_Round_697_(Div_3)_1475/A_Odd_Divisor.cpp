#include <bits/stdc++.h>
#include <numeric>
using namespace std;
int main() {
	long long n;
	int t;
cin>>t;
	int ans;
	int m;
	int d;
	float b;
	int a;
	int o;    
	while(t--){
			cin>>n;
            bitset<50>nn=n;
			if ((n%2)!=0)
			{
				cout<<"YES"<<endl;
			}
			else
			{
                if (nn.count()==1)
                {
                    cout<<"NO"<<endl;
                }
                else
                {
                    cout<<"YES"<<endl;
                }
                
			}
			
			
	}
		
		
	
return 0;
}