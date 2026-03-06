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
int o=0;
string s="";
int r;
int l;
int w;
int h;
int k;
vector<pair<ll,ll>>v;
vector<pair<ll,ll>>v1;
vector<pair<ll,ll>>v2;
pair<ll,ll>pp;
cin>>n;
for (int i = 0;i<n; i++)
{
    cin>>o;
    pp.first=o;
    pp.second=i+1;
     v.push_back(pp);
     v2.push_back(pp);
}
sort(v.begin(),v.end());
reverse(v.begin(),v.end());
r=(n/2)+1;
l=(n/2)+1;
for (int i = 0; i < n; i++)
{
    if ((i+1)%2==0)
    {
        l--;
        pp.first=v[i].second;
        pp.second=l;
        v1.push_back(pp);
    }
    else
    {
        r++;
        pp.first=v[i].second;
        pp.second=r;
        v1.push_back(pp);
    }
}
sort(v1.begin(),v1.end());
vector<ll>res;
res.push_back((n/2)+1);
for (int i = 0; i < n; i++)
{

res.push_back(v1[i].second);
 
}
ll y=0;
for (int i = 1; i < n+1; i++)
{
    y+=(2*abs(res[0]-res[i])*v2[i-1].first);
}
cout<<y<<endl;
for (int i = 0; i <n; i++)
{
    cout<<res[i]-1<<' ';
}
cout<<res[n]-1<<endl;

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
