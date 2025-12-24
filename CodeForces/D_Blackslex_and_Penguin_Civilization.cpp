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
    ll o;
    vector<ll>v;
    string s;
    cin>>n;
    vector<ll>f(pow(2,n)+1);
    ll ms=pow(2,n)-1;
    ll c=0;
    while (c<pow(2,n) && ms)
    {
        for (int i = 0; i <= pow(2,n)-1; i++)
        {
            if (!f[i] && (i&ms)==ms)
            {
                v.push_back(i);
                c++;
                f[i]=1;
            }
        }
        ms/=2;
    }
    for (auto el:v)
    {
        cout<<el<<' ';
    }
    if (c<pow(2,n))
    {
        for (int i = 0; i <= pow(2,n)-1; i++)
        {
            if (!f[i])
            {
                cout<<i<<' ';
            }
        }
    }
    
    
    cout<<endl; 
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
