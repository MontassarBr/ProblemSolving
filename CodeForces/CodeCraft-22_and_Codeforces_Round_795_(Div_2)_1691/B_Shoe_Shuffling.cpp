#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

#define PI 3.1415926535897932384626433832795l 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
// ----------------------<MATH>--------------------------- 
 
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);} 

template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));} 

void solve() {
int n;
int o;
vector<int>v;
cin>>n;
for(int i=0;i<n;i++){
    cin>>o;
    v.push_back(o);
}
int ans=0;
int c=v[0];
int b=0;
if (n==1)
{
    cout<<-1<<endl;
}
else
{
    for(int i=1;i<n;i++){
    if (v[i]==c)
    {
        b++;
    }
    else
    {
        if (b==0)
        {
        ans=-1;
        break;
        }
        else
        {
            b=0;
            c=v[i];
        }
    }
}
if (ans==-1 || b==0)
{
    cout<<-1<<endl;
}
else
{
    c=v[0];
    vector<int>v2;
    vector<int>res;
    for (int i = 0; i < n; i++)
    {
        if (v[i]==c)
        {
            v2.push_back(i+1);
        }
        else
        {
            rotate(v2.begin(),v2.begin()+1,v2.end());
            for (auto el:v2)
            {
                res.push_back(el);
            }
            v2.clear();
            v2.push_back(i+1);
            c=v[i];
        }
      
    }     
    rotate(v2.begin(),v2.begin()+1,v2.end());
    for (auto el:v2)
    {
    res.push_back(el);
    }
    for (int i = 0; i < res.size()-1; i++)
    {
        cout<<res[i]<<' ';
    }
    cout<<res[n-1]<<endl;
    
    
}
}




}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
     cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
