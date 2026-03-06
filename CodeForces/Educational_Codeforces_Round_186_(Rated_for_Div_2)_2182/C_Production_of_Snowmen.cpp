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
bool isPrime(ll n)
{

    if (n == 1 || n == 0)
        return 0;
    else if (n == 2)
        return 1;
    else if (n % 2 == 0)
        return 0;
    for (ll i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void fact(int x, map<ll, ll> &f)
{
    for (ll i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            int c = 0;
            while (x % i == 0)
            {
                x /= i;
                c++;
            }
            f[i] += c;
        }
    }
    if (x > 1)
    {
        f[x]++;
    }
}
bool med(ll a,ll b ,ll md)
{
    ll s=0;
    ll c=1;
    for (int i = 1; i <= md; i++)
    {
        if(i%2){
            b-=c;
        }
        else
        {
            a-=c;
        }
        c*=2;
        if (a<0 || b<0)
        {
            return false;
        }
        
    }
    return a>=0&& b>=0;  
}
int knowbit(int i, int n)
{
    return (n >> i) & 1;
}
bool check(vector<int> v)
{
    int c = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] % 2 == 0)
        {
            c++;
        }
        if (c > v.size() / 2)
        {
            return true;
        }
    }
    return false;
}
bool ok(double a,double b,ll k,double f, ll c,ll x){
    double p=k*a;
    if (a>b)
    {
        return true;
    }
    
    while(p<c){
        p=p+(a*(p/(b-a)));
        if (p>=c)
        {
            return true;
        }
        if (x<=0)
        {
            return false;
        }
        p=p+(a*((p/b)+f));
        x--;
    }
    return true;
}

bool cmp(vector<int>&a,vector<int>&b){
    return a.size()<b.size();
}
void solve()
{
    ll n;
    ll r;
    ll l;
    ll w;
    ll c;
    ll a;
    ll b;
    ll k;
    ll o;
    ll q;
    string s;
    string ans;
    string mn;
    vector<ll>v;
    vector<ll>v2;
    vector<ll>v3;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>o;
        v.push_back(o);
    }
    for (int i = 0; i < n; i++)
    {
        cin>>o;
        v2.push_back(o);
    }
    for (int i = 0; i < n; i++)
    {
        cin>>o;
        v3.push_back(o);
    }
    c=0;
    for (int i = 0; i < n; i++)
    {
        l=1;
        for (int j = 0; j < n; j++)
        {
            if (v2[(j+i)%n]<=v[j])
            {
                l=0;
                break;    
            }
        }
        c+=l;
    }
    ll c2=0;
    for (int i = 0; i < n; i++)
    {
        l=1;
        for (int j = 0; j < n; j++)
        {
            if (v3[(j+i)%n]<=v2[j])
            {
                l=0;
            }
        }
        c2+=l;
    }
    
    cout<<c2*c*n<<endl;
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