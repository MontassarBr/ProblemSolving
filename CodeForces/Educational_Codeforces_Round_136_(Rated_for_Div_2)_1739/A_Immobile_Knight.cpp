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


bool cmp(pair<string, int>& a, 
        pair<string, int>& b) 
{ 
    return a.second > b.second; 
} 
bool med(ll k,vector<ll>v,ll l){
    int p=v.size()/2;

    for (int i = p+1; i < v.size(); i++)
    {
        if (v[i]>k)
        {
            l-=v[i]-k;
            if (l<0)
            {
                break;
            }
            
        }
        else 
        {
            break;
        }
        
    }
    return l>=0;
    
}
int vis[1001][1001];
int ask(int i,int j){
    cout<<"? "<<i<<' '<<j<<endl;
    fflush(stdout);
    int r;
    cin>>r;
    return r;
}
bool valid(int x,int y,int n ,int m,char t[][1001]){
    return (x<n)&&(y<m)&&(x>=0)&&(y>=0)&&(vis[x][y]==0)&&(t[x][y]=='.');
}
void dfs(int x,int y,int n,int m,char t[][1001]){
    vis[x][y]=1;
    if (valid(x+1,y,n,m,t))
    {
        dfs(x+1,y,n,m,t);
    }
     if (valid(x,y+1,n,m,t))
    {
        dfs(x,y+1,n,m,t);
    }
     if (valid(x-1,y,n,m,t))
    {
        dfs(x-1,y,n,m,t);
    }
     if (valid(x,y-1,n,m,t))
    {
        dfs(x,y-1,n,m,t);
    }
}
void solve()
{
    ll n;
    ll r;
    ll l;
    ll w;
    char c;
    ll a;
    ll b;
    ll k;
    ll o;
    ll m;
    string s;
    
    vector<ll> v;
    map<string,int>mp;
    cin >>n>>m;
    cout<<(n/2)+1<<' '<<(m/2)+1<<endl;
    

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
