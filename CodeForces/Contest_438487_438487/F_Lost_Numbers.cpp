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


vector<int>adj[MAX_N];
int vis[100000];

int ask(int i,int j){
    cout<<"? "<<i<<' '<<j<<endl;
    fflush(stdout);
    int r;
    cin>>r;
    return r;
}
int res=MAX_N;
string ans="";
void dfs(int n,int c,int s,string m){
    vis[n]=1;
    if (n==s)
    {
        if (res>c)
        {
            res=c;
            ans="1"+m;
        }
    }
    for (auto el:adj[n])
    {
        if (!vis[el])
        {
            dfs(el,c+1,s,m+" "+to_string(el));
        }
    }
vis[n]=0;
   
}
ll k; 
vector<double>v;
ll n;
bool med(double e){
    ll r=0;
   for (int i = 0; i <n; i++)
   {
    r+=(v[i]/e);
   }
   
   return r<k;
   
}
double bin(){
    double l=0;
    double r=1e7;
    double ans=0;
    ll it=300;
    while (l<=r && it)
    {
        it--;
        double md=(l+r)/2;
        if (med(md))
        {
            r=md;
        }
        else
        {
            ans=max(md,ans);
            l=md;
        }  
    }
    return ans;
}
void solve()
{
   ll e1=ask(1,2);
   ll e2=ask(1,3);
   ll e3=ask(1,4);
   ll e4=ask(1,5);
   ll a[]={4,8,15,16,23,42};
   ll b[]={e1,e2,e3,e4};
    ll s=0;
    for (int i = 0; i < 4; i++)
    {
        s=gcd(s,b[i]);
    }
    ll sum=0;
    ll p=s;
    for (int i = 0; i <= 5; i++)
    {
        if (s%a[i]==0)
        {
            p=a[i];
        }
        sum+=a[i];
    }
    vector<ll>ans;
    ans.push_back(p);
    ans.push_back(e1/p);
    ans.push_back(e2/p);
    ans.push_back(e3/p);
    ans.push_back(e4/p);
    ans.push_back(sum-ans[0]-ans[1]-ans[2]-ans[3]-ans[4]);
    cout<<"! ";
    for(auto el:ans) cout<<el<<' ';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
