#include <bits/stdc++.h>
 
using namespace std;
 
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
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
template <typename T>
T gcd(T a, T b) { return (b ? __gcd(a, b) : a); }
 
template <typename T>
T lcm(T a, T b) { return (a * (b / gcd(a, b))); }

void solve() {

    int a,b,c,k,o,n;
    unordered_map<int,int>mp(5000);
    cin>>n>>b>>k;
    c=1e9;
   for (ll i = 0; i < n*n; i++)
   {
        cin>>o;
        mp[o]++;
        c=min(c,o);
   }
   ll c1=c;
   for (ll i = 0; i < n; i++)
   {
    if (i!=0)
    {
        c=c1+b;
    }
    for (ll j = 0; j < n; j++)
    {
        if (j==0)
        {
            c1=c;
        }
        //cout<<c<<" ";
         if (!mp[c])
         {
            cout<<"NO"<<endl;
            return;
         }
         else
         {
            mp[c]--;
            c+=k;
            
         } 
    }
    //cout<<endl;
   }
   
    
    
    
    cout<<"YES"<<endl;
 
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    //init(MAX_N);
    //linear_sieve();
     cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        //memset(dp,-1,sizeof dp);
         //cout << "Case #" << t << ": ";
        solve();
    }
}