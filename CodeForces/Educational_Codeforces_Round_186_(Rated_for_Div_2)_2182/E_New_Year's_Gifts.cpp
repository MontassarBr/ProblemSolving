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
struct fr
{
    ll b;
    ll y;
    ll z;
    ll d;
    fr(ll b,ll y,ll z){
        this->b=b;
        this->y=y;
        this->z=z;
        this->d=z-y;
    }
};
bool cmp(fr a,fr b){
    if(a.d==b.d) return a.b>b.b;
    return a.d>b.d;
}
bool cmp2(fr a, fr b){
    return a.d<b.d;
}


void solve()
{
    ll n,m,k;
    cin>>n>>m>>k;
    multiset<ll> v;
    for (int i = 0; i < m; i++)
    {
        ll o;
        cin>>o;
        v.insert(o);
    }
    vector<fr> v2;
    for (int i = 0; i < n; i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        k-=b;
        v2.push_back(fr(a, b, c));
    }
    sort(all(v2), cmp);
    
    ll c=0;
    vector<fr> v3;
    
    for (int i = 0; i < n; i++)
    {
        auto x=v.lower_bound(v2[i].b);
        if (x==v.end())
        {
            v3.push_back(v2[i]);
        }
        else
        {
            c++;
            v.erase(x);
        }
        
    }
    sort(all(v3), cmp2);
    for (int i = 0; i < v3.size(); i++)
    {
        if (k-v3[i].d>=0)
        {
            k-=v3[i].d;
            c++;
        }
        else
        {
            break;
        }
        
    }

    cout<<c<<endl;
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