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


bool cmp(vector<ll>& a, 
        vector<ll>& b) 
{ 
    return accumulate(all(a),0ll) > accumulate(all(b),0ll); 
} 



int ask(int i,int j){
    cout<<"? "<<i<<' '<<j<<endl;
    fflush(stdout);
    int r;
    cin>>r;
    return r;
}

void solve(){
   ll n;
   ll a;
   ll b;
   ll x;
   vector<vector<ll>>v;
   vector<ll>v2;
   cin>>n>>a;
   for (int i = 0; i < n; i++)
   {
    v2.clear();
    for (int i = 0; i < a; i++)
    {
        cin>>x;
        v2.push_back(x);
    }
    v.push_back(v2);
   }
   sort(all(v),cmp);
   v2.clear();
   for (int i = 0; i < n; i++)
   {
        for (int j = 0; j < a; j++)
        {
            v2.push_back(v[i][j]);
        }
   }
   
   for (int i = 1; i < (n*a); i++)
   {
        v2[i]+=v2[i-1];
   }
   ll res=accumulate(all(v2),0ll);
   
   
   cout<<res<<endl;
   
    
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
