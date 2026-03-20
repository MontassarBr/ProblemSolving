#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n,a,b,c;
        cin >> n >> a >> b >> c;

        if(a+b+c > n){
            cout << -1 << "\n";
            continue;
        }

        int extra = n-(a+b+c);

        vector<int> cnt = {a,b,c};

        while(extra--){
            int id = min_element(cnt.begin(),cnt.end()) - cnt.begin();
            cnt[id]++;
        }

        if(*max_element(cnt.begin(),cnt.end()) > (n+1)/2){
            cout << -1 << "\n";
            continue;
        }

        vector<pair<int,char>> col = {
            {cnt[0],'R'},
            {cnt[1],'G'},
            {cnt[2],'B'}
        };

        string ans="";
        char last='?';

        for(int i=0;i<n;i++){
            sort(col.rbegin(),col.rend());

            bool placed=false;

            for(auto &p:col){
                if(p.first>0 && p.second!=last){
                    ans+=p.second;
                    last=p.second;
                    p.first--;
                    placed=true;
                    break;
                }
            }

            if(!placed){
                ans="";
                break;
            }
        }

        if(ans.size()!=n) cout<<-1<<"\n";
        else cout<<ans<<"\n";
    }
}