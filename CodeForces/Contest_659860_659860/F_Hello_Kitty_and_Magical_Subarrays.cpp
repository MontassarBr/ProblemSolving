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



int ask(int i,int j){
    cout<<"? "<<i<<' '<<j<<endl;
    fflush(stdout);
    int r;
    cin>>r;
    return r;
}
int res=MAX_N;
string ans="";
long long bfs(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> visited(V, false);
    queue<int> q;

    int src = 0;              
    visited[src] = true;
    q.push(src);

    long long depth = -1;

    while (!q.empty()) {
        int levelSize = q.size();
        depth++;         
        for (int i = 0; i < levelSize; i++) {
            int curr = q.front();
            q.pop();

            for (int x : adj[curr]) {
                if (!visited[x]) {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
    }

    return depth;
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
void solve(){
   ll n;
   ll a;
   ll b;
   ll x;
   vector<ll>v;
   map<ll,ll>f;
   cin>>n>>a;
   v.push_back(0);
   for (int i = 0; i < n; i++)
   {
    cin>>b;
    v.push_back(b);
   }
   for (int i = 1; i < n+1; i++)
   {
        v[i]+=v[i-1];
   }
   ll s=0;
   for (int i = 0; i < n+1; i++)
   {
    s+=f[v[i]-a];
    f[v[i]]++;
   }
   
   
   cout<<s;
   
    
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
