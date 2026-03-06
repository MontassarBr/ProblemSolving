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
const ll N=1e7;
vector<bool>isPrime(N,true);vector<ll>p;
void linear_sieve()
{
    isPrime[0]=isPrime[1]=0;
    for(ll i=2;i<N;i++)
    {
        if(isPrime[i]==1) p.push_back(i);
        for(ll o=0;o<p.size();o++)
        {
            if(i*p[o]>=N) break;
            isPrime[i*p[o]]=0;
            if(i%p[o]==0) break;
        }
    }
}
bool cmp(pair<int,bitset<2>>& a, 
       pair<int,bitset<2>>& b) 
{ 
    return a.first > b.first; 
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
int ask(int i,int j){
    cout<<"? "<<i<<' '<<j<<endl;
    fflush(stdout);
    int r;
    cin>>r;
    return r;
}
vector<vector<pair<int,int>>>adj(MAX_N);
int vis[MAX_N];
ll m,n;
ll res=MAX_N;
char cc[1000][1000];
vector<ll>sol(MAX_N,LONG_LONG_MAX);
void bfs(int i){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
    q.push({0,i});
    while (!q.empty())
    {
    pair<ll,ll>pp=q.top();
    q.pop();
    if (vis[pp.second])
    {
        continue;
    }
    vis[pp.second]=1;
    sol[pp.second-1]=min(sol[pp.second-1],pp.first);
    for (auto el:adj[pp.second])
    {
      q.push({pp.first+el.second,el.first}); 
    }
    }
}
ll dp[2*MAX_N];
vector<pair<ll,ll>>v;
map<ll,ll>mm;
ll rec(ll i){
    if (i==n)
    {
        return 0;
    }
    if (dp[i]!=-1)
    {
        return dp[i];
    }
    ll leave=rec(i+1);
    ll take=0;
    if (mm[i])
    {
        take=rec(mm[i])+1;
    }
    return dp[i]=max(take,leave);
}
void solve() {
    ll r;
    ll l;
    ll w;
    ll c;
    ll d;
    ll a;
    ll b;
    ll k;
    ll o;
    ll q;
    string s;
    set<ll>st;
    vector<ll>v2;
    map<int,int>mp;
    cin>>n;
    cin>>a>>b>>c>>d;
    if (a>n/2)
    {
        a=n-a;
    }
    else
    {
        a-=1;    
    }
    if (b>n/2)
    {
        b=n-b;
    }
    else
    {
        b-=1;    
    }
    if (c>n/2)
    {
        c=n-c;
    }
    else
    {
        c-=1;    
    }
    if (d>n/2)
    {
       d=n-d;
    }
    else
    {
        d-=1;    
    } 
    cout<<abs(min(a,b)-min(d,c))<<endl;
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