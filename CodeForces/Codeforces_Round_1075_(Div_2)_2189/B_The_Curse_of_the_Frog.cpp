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
const ll N=1e6;
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
ll powmod(ll x, ll y)
{
    ll res = 1;
    x = x % MOD;
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % MOD;
        y = y>>1;
        x = (x*x) % MOD;
    }
    return res;
}
vector<ll> fac,inv,finv;
void init(int n)
{
    fac.resize(n+1);
    inv.resize(n+1);
    finv.resize(n+1);
    fac[0]=inv[0]=inv[1]=finv[0]=finv[1]=1;
    for(ll i=1;i<=n;++i)fac[i]=fac[i-1]*i%MOD;
    for(ll i=2;i<=n;++i)inv[i]=MOD-MOD/i*inv[MOD%i]%MOD;
    for(ll i=2;i<=n;++i)finv[i]=finv[i-1]*inv[i]%MOD;
}
ll nCr(ll x,ll y)
{
    if(x<0||y>x||y<0)return(0);
    return(fac[x]*finv[y]%MOD*finv[x-y]%MOD);
}
ll nPr(ll x,ll y)
{
    if(x<0||y>x||y<0)return 0;
    return fac[x]*finv[x-y]%MOD;
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
ll m,n,k;vector<ll>v;vector<string>v2;string res="";vector<ll>vv2; string s1;
    ll r;
    ll l;
    ll w;
    ll a;
    ll b;
    ll o;
    ll c;
ll dp[MAX_N][2];
bool valid(string s){
    queue<char>k;
    queue<char>c;
    for (int i = 0; i < s.length(); i++)
    {
        k.push(s[i]);
    }
    for (int i = 0; i < n; i++)
    {
        c=k;
        for (int j = 0; j < v2[i].length(); j++)
        {
            if (c.empty())
            {
                break;
            } 
            if (c.front()==v2[i][j])
            {
                c.pop();
            }
        }
        if (!c.empty())
        {
            return false;
        }
    }
    return true;
    
}
void rec(ll i,string s){
    if (i>=s1.length())
    {
        if(valid(s)){
            if (s.length()>res.length() || (s.length()==res.length() && s<res))
            {
                res=s;
            }
        }
        return;
    }
    rec(i+1,s+s1[i]);
    rec(i+1,s);
}



void solve() {
    string s;
    v.clear();
    v2.clear();
    
    priority_queue<ll>pp;
    unordered_map<ll,string>mp;
    unordered_set<ll>st;
    char cc;
    pair<ll,pair<ll,ll>>vp;
    cin>>n>>k;
    l=0;
    for (int i = 0; i < n; i++)
    {
        cin>>o>>a>>b;
        if (i==0)
        {
            vp={o,{a,b}};
        }
        else
        {
            if((o*a)-b>vp.first*vp.second.first-vp.second.second)  vp={o,{a,b}};
        }
        if ((o*(a-1))>0)
        {
            l+=(o*(a-1));
        }
    }
    if(l>=k){
        cout<<0<<endl;
        return;
    }
    l-=(vp.first*(vp.second.first-1));
    if(l>=k){
        cout<<0<<endl;
        return;
    }
    if(vp.first*vp.second.first-vp.second.second<=0){
        cout<<-1<<endl;
        return;
    }
    k-=l;
    b=vp.first*vp.second.first-vp.second.second;
    c=(k/b)+(k%b>0); // dbg(c,vp);
    while(k<=((c-1)*b)+(vp.first*(vp.second.first-1)) && c>0) c--;
    cout<<c<<endl;
    
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