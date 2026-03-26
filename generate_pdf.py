#!/usr/bin/env python3
"""Generate a PDF of all CP templates with explanations, use cases, and tricks."""

from reportlab.lib.pagesizes import A4
from reportlab.lib.styles import getSampleStyleSheet, ParagraphStyle
from reportlab.lib.units import cm
from reportlab.lib import colors
from reportlab.platypus import (
    SimpleDocTemplate, Paragraph, Spacer, Preformatted,
    HRFlowable, PageBreak, Table, TableStyle, KeepTogether
)
from reportlab.lib.enums import TA_LEFT, TA_CENTER, TA_JUSTIFY

# ── colour palette ──────────────────────────────────────────────────────────
DARK_BLUE   = colors.HexColor("#1a237e")
MID_BLUE    = colors.HexColor("#1565c0")
LIGHT_BLUE  = colors.HexColor("#e3f2fd")
ACCENT      = colors.HexColor("#0288d1")
CODE_BG     = colors.HexColor("#f5f5f5")
CODE_BORDER = colors.HexColor("#b0bec5")
TRICK_BG    = colors.HexColor("#fff8e1")
TRICK_BOR   = colors.HexColor("#f9a825")
WARN_RED    = colors.HexColor("#b71c1c")
GREEN       = colors.HexColor("#1b5e20")
WHITE       = colors.white

# ── styles ───────────────────────────────────────────────────────────────────
base = getSampleStyleSheet()

def make_styles():
    styles = {}

    styles["cover_title"] = ParagraphStyle(
        "cover_title", fontSize=32, leading=40, alignment=TA_CENTER,
        textColor=WHITE, fontName="Helvetica-Bold", spaceAfter=12)

    styles["cover_sub"] = ParagraphStyle(
        "cover_sub", fontSize=14, leading=20, alignment=TA_CENTER,
        textColor=colors.HexColor("#bbdefb"), fontName="Helvetica", spaceAfter=6)

    styles["h1"] = ParagraphStyle(
        "h1", fontSize=20, leading=26, fontName="Helvetica-Bold",
        textColor=WHITE, spaceBefore=18, spaceAfter=8,
        backColor=DARK_BLUE, leftIndent=-12, rightIndent=-12,
        borderPadding=(6, 12, 6, 12))

    styles["h2"] = ParagraphStyle(
        "h2", fontSize=15, leading=20, fontName="Helvetica-Bold",
        textColor=WHITE, spaceBefore=14, spaceAfter=6,
        backColor=MID_BLUE, leftIndent=-8, rightIndent=-8,
        borderPadding=(5, 8, 5, 8))

    styles["h3"] = ParagraphStyle(
        "h3", fontSize=12, leading=16, fontName="Helvetica-Bold",
        textColor=DARK_BLUE, spaceBefore=10, spaceAfter=4)

    styles["body"] = ParagraphStyle(
        "body", fontSize=10, leading=15, fontName="Helvetica",
        textColor=colors.HexColor("#212121"), spaceAfter=6, alignment=TA_JUSTIFY)

    styles["bullet"] = ParagraphStyle(
        "bullet", fontSize=10, leading=14, fontName="Helvetica",
        textColor=colors.HexColor("#212121"), leftIndent=16, spaceAfter=3,
        bulletIndent=6)

    styles["code"] = ParagraphStyle(
        "code", fontSize=8, leading=11, fontName="Courier",
        textColor=colors.HexColor("#263238"), backColor=CODE_BG,
        leftIndent=8, rightIndent=8, spaceBefore=4, spaceAfter=4,
        borderColor=CODE_BORDER, borderWidth=1, borderPadding=6)

    styles["trick"] = ParagraphStyle(
        "trick", fontSize=10, leading=14, fontName="Helvetica",
        textColor=colors.HexColor("#37474f"), backColor=TRICK_BG,
        leftIndent=8, rightIndent=8, spaceBefore=2, spaceAfter=2,
        borderColor=TRICK_BOR, borderWidth=1, borderPadding=6)

    styles["label"] = ParagraphStyle(
        "label", fontSize=9, leading=12, fontName="Helvetica-Bold",
        textColor=ACCENT, spaceAfter=2)

    styles["use_case"] = ParagraphStyle(
        "use_case", fontSize=10, leading=14, fontName="Helvetica-Oblique",
        textColor=GREEN, leftIndent=12, spaceAfter=4)

    styles["toc_entry"] = ParagraphStyle(
        "toc_entry", fontSize=10, leading=16, fontName="Helvetica",
        textColor=DARK_BLUE, leftIndent=20)

    styles["toc_section"] = ParagraphStyle(
        "toc_section", fontSize=12, leading=18, fontName="Helvetica-Bold",
        textColor=DARK_BLUE)

    return styles

S = make_styles()


def hr():
    return HRFlowable(width="100%", thickness=1, color=ACCENT, spaceAfter=6)

def code_block(code_str):
    """Return a Preformatted flowable styled as a code block."""
    return Preformatted(code_str.strip(), S["code"])

def section(title):
    return [Paragraph(title, S["h1"]), Spacer(1, 4)]

def subsection(title):
    return [Paragraph(title, S["h2"]), Spacer(1, 3)]

def body(text):
    return Paragraph(text, S["body"])

def bullet(text):
    return Paragraph(f"• {text}", S["bullet"])

def use_case(text):
    return Paragraph(f"✔ Use case: {text}", S["use_case"])

def label(text):
    return Paragraph(text, S["label"])

def trick_box(text):
    return Paragraph(f"💡 {text}", S["trick"])


# ── template data ─────────────────────────────────────────────────────────────
TEMPLATES = [
    # ── 1. BASE TEMPLATE ──────────────────────────────────────────────────────
    {
        "title": "1. Base Competitive Programming Template",
        "description": (
            "This is the standard boilerplate used across all solutions in this "
            "repository. It includes the essential headers, fast I/O setup, common "
            "type aliases, constants, and a multi-test-case main loop."
        ),
        "code": """\
#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define ld  long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

#define PI  3.1415926535897932384626433832795l
const int MAX_N = 1e5 + 5;
const ll  MOD   = 1e9 + 7;
const ll  INF   = 1e9;
const ld  EPS   = 1e-9;

void solve() {
    // your solution here
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
}""",
        "use_cases": [
            "Starting point for every competitive programming problem.",
            "ios_base::sync_with_stdio(0) + cin.tie(0) gives ~3-5x faster I/O.",
            "MOD = 1e9+7 is the standard modulus for modular arithmetic problems.",
            "INF = 1e9 is a safe sentinel that fits in int and doesn't overflow when doubled in ll.",
        ],
    },

    # ── 2. DEBUG TEMPLATE ─────────────────────────────────────────────────────
    {
        "title": "2. Debug / Pretty-Print Template",
        "description": (
            "Generic output operators for pairs and any container (vector, set, map, …), "
            "plus a variadic debug macro that prints variable names and values to stderr. "
            "Has zero performance cost in online judges (compile with -DLOCAL to activate, "
            "or strip before submission)."
        ),
        "code": """\
// ── pretty-print for pairs ──────────────────────────────────────────────────
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A,B>& p) {
    return os << '(' << p.first << ", " << p.second << ')';
}

// ── pretty-print for any iterable container ─────────────────────────────────
template <typename C,
          typename T = typename enable_if<
              !is_same<C, string>::value,
              typename C::value_type>::type>
ostream& operator<<(ostream& os, const C& v) {
    os << '{';
    string sep;
    for (const T& x : v) os << sep << x, sep = ", ";
    return os << '}';
}

// ── variadic debug macro ─────────────────────────────────────────────────────
void dbg_out() { cerr << '\\n'; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

// ── usage ────────────────────────────────────────────────────────────────────
// vector<int> v = {1,2,3};
// pair<int,int> p = {4,5};
// dbg(v, p);
// stderr → (v, p): {1, 2, 3} (4, 5)""",
        "use_cases": [
            "Instantly print any STL container or nested structure during debugging.",
            "dbg(a, b, c) prints names AND values so you never confuse variables.",
            "Wrap in #ifdef LOCAL to auto-disable on judge servers.",
            "Saves significant time tracking down wrong-answer bugs.",
        ],
    },

    # ── 3. GCD / LCM ──────────────────────────────────────────────────────────
    {
        "title": "3. GCD & LCM (Math Template)",
        "description": (
            "Template functions for Greatest Common Divisor and Least Common Multiple. "
            "Uses the built-in __gcd for correctness and wraps it in a template to work "
            "with both int and long long without implicit-cast bugs."
        ),
        "code": """\
template <typename T>
T gcd(T a, T b) { return b ? __gcd(a, b) : a; }

template <typename T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }   // divide first to avoid overflow

// Examples:
// gcd(12, 8)   → 4
// lcm(4, 6)    → 12
// gcd<ll>(1e18, 999999999) → works correctly""",
        "use_cases": [
            "Simplifying fractions: numerator/gcd, denominator/gcd.",
            "Synchronising periodic events: first overlap at lcm(period1, period2).",
            "Checking if a/b is an integer: a % b == 0.",
            "Array problems: find minimum steps to equalise using gcd of differences.",
        ],
    },

    # ── 4. PRIME CHECKING (BASIC) ──────────────────────────────────────────────
    {
        "title": "4. Prime Checking — Basic O(n)",
        "description": (
            "Straightforward primality test used in the repository's earlier solutions. "
            "Checks every divisor from 2 to n-1. Simple but slow for large n."
        ),
        "code": """\
bool isPrime(int n) {
    if (n == 1) return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0) return false;
    return true;
}""",
        "use_cases": [
            "Suitable for small n (n < 10,000).",
            "Quick sanity checks inside brute-force solutions.",
        ],
    },

    # ── 5. PRIME CHECKING (OPTIMISED) ─────────────────────────────────────────
    {
        "title": "5. Prime Checking — Optimised O(√n)",
        "description": (
            "The production-ready primality test used in N_Integer and A_Notelock. "
            "Handles edge cases (0, 1, 2, even numbers) and only checks odd divisors "
            "up to √n — reducing iterations from n to roughly √n/2."
        ),
        "code": """\
bool isPrime(ll n) {
    if (n <= 1)   return false;
    if (n == 2)   return true;
    if (n % 2 == 0) return false;
    for (ll i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

// Complexity: O(√n)
// Works correctly for n up to ~10^18 (with ll)""",
        "use_cases": [
            "Checking primality of a single number up to 10^12.",
            "Filtering primes inside a solve() loop for moderate inputs.",
            "Validating that an answer is prime as part of problem constraints.",
        ],
    },

    # ── 6. LINEAR SIEVE ───────────────────────────────────────────────────────
    {
        "title": "6. Linear Sieve (Sieve of Eratosthenes variant)",
        "description": (
            "Generates all primes up to N in O(N) time. Each composite is crossed out "
            "exactly once by its smallest prime factor — making it strictly linear. "
            "Produces the list of primes in vector p."
        ),
        "code": """\
const ll N = 1e6 + 5;
vector<bool> is_prime(N, true);
vector<ll>   primes;

void linear_sieve() {
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i < N; i++) {
        if (is_prime[i]) primes.push_back(i);
        for (ll j = 0; j < (ll)primes.size() && i * primes[j] < N; j++) {
            is_prime[i * primes[j]] = false;
            if (i % primes[j] == 0) break;   // key line for linearity
        }
    }
}

// After calling linear_sieve():
// is_prime[x] == true  ↔  x is prime
// primes contains all primes < N in sorted order""",
        "use_cases": [
            "Count primes in range [1, N] in O(N).",
            "Precompute smallest prime factor table for fast factorisation.",
            "Problems asking for all primes up to 10^6 or 10^7.",
            "Euler's totient function batch computation.",
        ],
    },

    # ── 7. FACTORISATION ──────────────────────────────────────────────────────
    {
        "title": "7. Prime Factorisation",
        "description": (
            "Decomposes a number x into its prime factors, accumulating exponents in a "
            "map<prime, exponent>. Supports calling multiple times to merge factorisations "
            "(used in N_Integer to track a running product's prime factors)."
        ),
        "code": """\
void factorize(ll x, map<ll,ll>& f) {
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) { x /= i; cnt++; }
            f[i] += cnt;
        }
    }
    if (x > 1) f[x]++;   // remaining prime factor > sqrt(x)
}

// Example: factorize(12, f) → f = {2:2, 3:1}  (12 = 2^2 * 3)
// factorize(18, f) → f = {2:3, 3:3}  (merged: 12*18=216=2^3*3^3)""",
        "use_cases": [
            "Checking if x^(1/k) is an integer: all exponents must be divisible by k.",
            "Finding the number of divisors: product of (exponent+1).",
            "LCM of many numbers: take max exponent per prime.",
            "GCD of many numbers: take min exponent per prime.",
        ],
    },

    # ── 8. MODULAR EXPONENTIATION ─────────────────────────────────────────────
    {
        "title": "8. Modular Exponentiation (Fast Power)",
        "description": (
            "Computes (x^y) % MOD in O(log y) using repeated squaring. "
            "Essential for any problem involving large powers under a modulus."
        ),
        "code": """\
ll powmod(ll x, ll y, ll mod = MOD) {
    ll res = 1;
    x %= mod;
    while (y > 0) {
        if (y & 1) res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

// Example: powmod(2, 10) → 1024 % (1e9+7) = 1024
// Modular inverse of x: powmod(x, MOD-2)  (when MOD is prime)""",
        "use_cases": [
            "Computing n! / k! mod p using Fermat's little theorem.",
            "Modular inverse: inv(x) = powmod(x, MOD-2, MOD).",
            "Matrix exponentiation to solve linear recurrences in O(k^3 log n).",
            "Cryptographic computations (RSA key steps).",
        ],
    },

    # ── 9. COMBINATORICS (nCr mod p) ──────────────────────────────────────────
    {
        "title": "9. Combinatorics — nCr mod p with Precomputed Factorials",
        "description": (
            "Precomputes factorial, inverse factorial, and modular inverse tables so "
            "that C(n, r) mod p can be answered in O(1) per query after O(N) init."
        ),
        "code": """\
const int MAXN = 1e6 + 5;
ll fac[MAXN], inv_fac[MAXN];

void init_comb(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i-1] * i % MOD;
    inv_fac[n] = powmod(fac[n], MOD - 2);
    for (int i = n-1; i >= 0; i--) inv_fac[i] = inv_fac[i+1] * (i+1) % MOD;
}

ll nCr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return fac[n] % MOD * inv_fac[r] % MOD * inv_fac[n-r] % MOD;
}

// Usage: init_comb(1e6); then nCr(50, 10) → answer mod MOD""",
        "use_cases": [
            "Counting paths on a grid: C(m+n-2, m-1).",
            "Number of ways to choose k items from n: C(n, k).",
            "Stars and bars: distributing identical objects into distinct bins.",
            "Inclusion-exclusion principle computations.",
        ],
    },

    # ── 10. BINARY SEARCH ─────────────────────────────────────────────────────
    {
        "title": "10. Binary Search on Answer",
        "description": (
            "Binary search on the answer space when the predicate 'can we achieve value k?' "
            "is monotone. Used in C_Maximum_Median and E_Cardboard_for_Pictures."
        ),
        "code": """\
// Generic template: find the maximum k such that check(k) is true.
// Requires: check(lo) == true, check(hi+1) == false (or vice versa).

bool check(ll mid) {
    // return true if mid is achievable
}

ll binary_search_answer(ll lo, ll hi) {
    ll ans = lo;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;   // avoids overflow vs (lo+hi)/2
        if (check(mid)) {
            ans = mid;
            lo  = mid + 1;             // try to do better
        } else {
            hi  = mid - 1;
        }
    }
    return ans;
}

// ── Real usage from C_Maximum_Median ────────────────────────────────────────
// Find max median achievable after adding k elements to sorted array v:
bool can_reach_median(ll target, vector<ll>& v, ll budget) {
    int mid = v.size() / 2;
    for (int i = mid + 1; i < (int)v.size(); i++) {
        if (v[i] > target) { budget -= v[i] - target; if (budget < 0) break; }
        else break;
    }
    return budget >= 0;
}""",
        "use_cases": [
            "Minimise the maximum load (split array, painters partition).",
            "Find the minimum time/cost that satisfies a constraint.",
            "Kth smallest/largest in a sorted matrix.",
            "Rope cutting, book allocation, aggressive cows problems.",
        ],
    },

    # ── 11. BIT MANIPULATION ──────────────────────────────────────────────────
    {
        "title": "11. Bit Manipulation Utilities",
        "description": (
            "Low-level bit tricks used in E_Even_odd_subset and N_Integer. "
            "Efficient for subset enumeration and parity checks."
        ),
        "code": """\
// ── Read the i-th bit of n ───────────────────────────────────────────────────
int bit(int n, int i) { return (n >> i) & 1; }

// ── Set / clear / toggle ─────────────────────────────────────────────────────
int set_bit   (int n, int i) { return n |  (1 << i); }
int clear_bit (int n, int i) { return n & ~(1 << i); }
int toggle_bit(int n, int i) { return n ^  (1 << i); }

// ── Count set bits ───────────────────────────────────────────────────────────
int popcount(int n) { return __builtin_popcount(n); }   // or __builtin_popcountll for ll

// ── Enumerate all subsets of a set represented by mask ─────────────────────
for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
    // process subset `sub`
}

// ── Enumerate all subsets of {0..n-1} with exactly k bits ──────────────────
int sub = (1 << k) - 1;   // smallest number with k bits set
while (sub < (1 << n)) {
    // process sub
    int c = sub & -sub, r = sub + c;
    sub = (((r ^ sub) >> 2) / c) | r;   // Gosper's hack
}

// ── From E_Even_odd_subset: enumerate all 2^n subsets ──────────────────────
for (int mask = 0; mask < (1 << n); mask++) {
    for (int j = 0; j < n; j++)
        if (bit(mask, j)) { /* j is in this subset */ }
}""",
        "use_cases": [
            "Subset-sum / knapsack DP states over bitmask.",
            "Graph problems on small vertex sets (TSP, Hamiltonian path).",
            "Checking parity, checking if a number is a power of 2: n & (n-1) == 0.",
            "XOR-based hashing to detect duplicates or changes.",
        ],
    },

    # ── 12. STACK — BRACKET MATCHING ──────────────────────────────────────────
    {
        "title": "12. Stack-Based Bracket Matching",
        "description": (
            "Classic use of a stack to validate balanced brackets. "
            "Directly taken from G_Brackets_Hard_Version."
        ),
        "code": """\
bool is_balanced(const string& s) {
    stack<char> stk;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        } else {
            if (stk.empty()) return false;
            char top = stk.top(); stk.pop();
            if (c == ')' && top != '(') return false;
            if (c == ']' && top != '[') return false;
            if (c == '}' && top != '{') return false;
        }
    }
    return stk.empty();   // all opened brackets must be closed
}""",
        "use_cases": [
            "Validate HTML/JSON/code syntax.",
            "Evaluate arithmetic expressions using two stacks (operators + operands).",
            "Next Greater Element pattern: monotone stack.",
            "Largest rectangle in histogram (monotone stack).",
        ],
    },

    # ── 13. RECURSIVE ENUMERATION ─────────────────────────────────────────────
    {
        "title": "13. Recursive Subset / Combination Enumeration",
        "description": (
            "Recursively builds all combinations by branching on choices at each step. "
            "Used in B_Tavas_and_SaDDas to generate all 'lucky numbers' (digits 4 & 7)."
        ),
        "code": """\
// ── Lucky numbers example (digits 4 and 7 only) ─────────────────────────────
vector<int> lucky;
void generate(string cur) {
    if (cur.size() > 9) return;        // stop at 9-digit numbers
    lucky.push_back(stoi(cur));
    generate(cur + '4');
    generate(cur + '7');
}
// Call: generate("4"); generate("7");
// Then sort lucky and binary-search.

// ── Generic permutation template ────────────────────────────────────────────
void permutations(vector<int>& arr, int start) {
    if (start == (int)arr.size()) {
        // process current permutation
        return;
    }
    for (int i = start; i < (int)arr.size(); i++) {
        swap(arr[start], arr[i]);
        permutations(arr, start + 1);
        swap(arr[start], arr[i]);   // backtrack
    }
}

// ── Generic combination template (choose k from n) ──────────────────────────
void combinations(int n, int k, int start, vector<int>& chosen) {
    if ((int)chosen.size() == k) {
        // process chosen
        return;
    }
    for (int i = start; i <= n; i++) {
        chosen.push_back(i);
        combinations(n, k, i + 1, chosen);
        chosen.pop_back();   // backtrack
    }
}""",
        "use_cases": [
            "Generating all subsets of a small set (n ≤ 20).",
            "Brute-force solutions for n ≤ 8 (8! = 40320 permutations).",
            "Pre-generating lookup tables for special number families.",
            "Backtracking: N-Queens, Sudoku solver.",
        ],
    },

    # ── 14. CUSTOM COMPARATOR ─────────────────────────────────────────────────
    {
        "title": "14. Custom Comparator & Sorting",
        "description": (
            "Custom comparison functions / lambdas to sort complex structures. "
            "Directly taken from multiple files in the repository."
        ),
        "code": """\
// ── Function comparator (pairs sorted by second DESC) ───────────────────────
bool cmp(const pair<string,int>& a, const pair<string,int>& b) {
    return a.second > b.second;
}
sort(v.begin(), v.end(), cmp);

// ── Lambda comparator ────────────────────────────────────────────────────────
sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;   // tie-break: second DESC
});

// ── Struct with operator< ────────────────────────────────────────────────────
struct Event {
    int time, type;
    bool operator<(const Event& o) const {
        return time < o.time || (time == o.time && type < o.type);
    }
};
sort(events.begin(), events.end());

// ── Partial sort (only need top-k) ──────────────────────────────────────────
partial_sort(v.begin(), v.begin() + k, v.end()); // O(n log k)

// ── nth_element (k-th smallest in O(n) average) ─────────────────────────────
nth_element(v.begin(), v.begin() + k, v.end());  // v[k] is in correct position""",
        "use_cases": [
            "Leaderboard / frequency ranking problems.",
            "Scheduling: sort tasks by deadline, duration, ratio.",
            "Greedy algorithms requiring a specific ordering.",
            "Finding the median or k-th order statistic efficiently.",
        ],
    },

    # ── 15. PREFIX SUM ────────────────────────────────────────────────────────
    {
        "title": "15. Prefix Sum (1D & 2D)",
        "description": (
            "Precompute running sums to answer range-sum queries in O(1) after O(n) build."
        ),
        "code": """\
// ── 1-D prefix sum ───────────────────────────────────────────────────────────
vector<ll> pre(n + 1, 0);
for (int i = 0; i < n; i++) pre[i+1] = pre[i] + a[i];

// sum of a[l..r] (0-indexed, inclusive):
ll range_sum = pre[r+1] - pre[l];

// ── 2-D prefix sum ───────────────────────────────────────────────────────────
int grid[MAXN][MAXN], ps[MAXN][MAXN];

// Build (1-indexed):
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        ps[i][j] = grid[i][j] + ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];

// Sum of rectangle (r1,c1)..(r2,c2) (1-indexed):
ll rect_sum = ps[r2][c2] - ps[r1-1][c2] - ps[r2][c1-1] + ps[r1-1][c1-1];""",
        "use_cases": [
            "Subarray sum queries in O(1): classic interview + CP staple.",
            "Count of elements satisfying a condition in any subarray.",
            "2D grid queries: sum/count in rectangles.",
            "Difference array technique (inverse of prefix sum) for range updates.",
        ],
    },

    # ── 16. TWO POINTERS / SLIDING WINDOW ─────────────────────────────────────
    {
        "title": "16. Two Pointers & Sliding Window",
        "description": (
            "Linear-time technique for subarray/substring problems using two indices "
            "moving in the same or opposite directions."
        ),
        "code": """\
// ── Fixed-size window (maximum sum of k consecutive elements) ────────────────
ll window_sum = 0, best = 0;
for (int i = 0; i < n; i++) {
    window_sum += a[i];
    if (i >= k) window_sum -= a[i - k];
    if (i >= k - 1) best = max(best, window_sum);
}

// ── Variable-size window (smallest subarray with sum >= target) ──────────────
int lo = 0;
ll cur = 0;
int ans = INT_MAX;
for (int hi = 0; hi < n; hi++) {
    cur += a[hi];
    while (cur >= target) {
        ans = min(ans, hi - lo + 1);
        cur -= a[lo++];
    }
}

// ── Two-pointer on sorted array (pair with given sum) ────────────────────────
sort(a.begin(), a.end());
int lo = 0, hi = n - 1;
while (lo < hi) {
    if (a[lo] + a[hi] == target) { /* found */ break; }
    else if (a[lo] + a[hi] < target) lo++;
    else hi--;
}""",
        "use_cases": [
            "Longest substring without repeating characters.",
            "Count subarrays with exactly k distinct elements.",
            "3-Sum / 4-Sum problems on sorted arrays.",
            "Container with most water.",
        ],
    },

    # ── 17. INTERACTIVE PROBLEM TEMPLATE ─────────────────────────────────────
    {
        "title": "17. Interactive Problem Template",
        "description": (
            "Template for problems where you query a judge and receive answers. "
            "Critical: flush output after every query (endl or '\\n' + flush)."
        ),
        "code": """\
int ask(int i, int j) {
    cout << "? " << i << ' ' << j << '\\n';
    cout.flush();          // MUST flush — judge won't respond otherwise
    int response;
    cin >> response;
    return response;
}

void answer(int x) {
    cout << "! " << x << '\\n';
    cout.flush();
}

// Typical binary search on hidden value in [1, n]:
void solve() {
    int n; cin >> n;
    int lo = 1, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (ask(mid, mid + 1) == 1)   // judge says left half
            hi = mid;
        else
            lo = mid + 1;
    }
    answer(lo);
}""",
        "use_cases": [
            "Guess the hidden number / permutation problems.",
            "Binary search with oracle queries.",
            "Finding a heavy ball among n balls with a balance scale.",
        ],
    },

    # ── 18. DISJOINT SET UNION (DSU) ──────────────────────────────────────────
    {
        "title": "18. Disjoint Set Union (DSU / Union-Find)",
        "description": (
            "Tracks connected components with nearly O(1) amortised operations "
            "via path compression and union by rank."
        ),
        "code": """\
struct DSU {
    vector<int> parent, rank_;
    DSU(int n) : parent(n), rank_(n, 0) {
        iota(parent.begin(), parent.end(), 0);   // parent[i] = i
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);  // path compression
        return parent[x];
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;                // already connected
        if (rank_[x] < rank_[y]) swap(x, y);
        parent[y] = x;
        if (rank_[x] == rank_[y]) rank_[x]++;
        return true;
    }
    bool connected(int x, int y) { return find(x) == find(y); }
};

// Usage:
DSU dsu(n);
dsu.unite(0, 1);
dsu.connected(0, 2);   // false""",
        "use_cases": [
            "Kruskal's MST algorithm.",
            "Detecting cycles in an undirected graph.",
            "Number of connected components.",
            "Online connectivity queries.",
        ],
    },
]

# ── CP TRICKS ─────────────────────────────────────────────────────────────────
CP_TRICKS = [
    {
        "category": "I/O Speed",
        "tricks": [
            (
                "Fast I/O boilerplate",
                'ios_base::sync_with_stdio(0); cin.tie(0);',
                "Always add this to main(). Gives 3-5x speedup. Never mix printf/scanf with cin/cout after this.",
            ),
            (
                "Print '\\n' instead of endl",
                'cout << "\\n";  // NOT cout << endl;',
                "endl flushes the buffer — avoid it in loops. Use '\\n' or '\\n' only.",
            ),
            (
                "Read entire line after numbers",
                'int n; cin >> n; cin.ignore(); getline(cin, s);',
                "After reading a number with cin>>, a leftover newline stays in the buffer. cin.ignore() skips it before getline.",
            ),
        ],
    },
    {
        "category": "Overflow Prevention",
        "tricks": [
            (
                "Always use long long for products",
                '(ll)a * b  // cast before multiply\nll ans = (ll)n * (n+1) / 2;',
                "If a and b are int, a*b overflows before assignment to ll. Cast one operand first.",
            ),
            (
                "Safe mid-point in binary search",
                'll mid = lo + (hi - lo) / 2;  // NOT (lo+hi)/2',
                "(lo+hi) can overflow when both are close to INT_MAX. The subtraction form is always safe.",
            ),
            (
                "Use __int128 for very large intermediate values",
                '__int128 big = (__int128)a * b % MOD;',
                "When two ll values are multiplied and the product can exceed 9*10^18, use __int128.",
            ),
        ],
    },
    {
        "category": "STL One-Liners",
        "tricks": [
            (
                "Sort + unique to deduplicate",
                'sort(all(v)); v.erase(unique(all(v)), v.end());',
                "After sort, unique moves duplicates to the end; erase removes them. Result: sorted unique vector.",
            ),
            (
                "Binary search on sorted vector",
                'lower_bound(all(v), x)  // first element >= x\nupper_bound(all(v), x)  // first element >  x',
                "Returns iterator. Subtract v.begin() for index. Check iterator != v.end() before dereferencing.",
            ),
            (
                "Max/min of entire container",
                '*max_element(all(v))  // O(n)\n*min_element(all(v))',
                "Works on any random-access container. Use priority_queue for repeated max queries.",
            ),
            (
                "Accumulate (sum) a vector",
                'll total = accumulate(all(v), 0LL);',
                "Pass 0LL (not 0) as the initial value to avoid int overflow when summing ll values.",
            ),
            (
                "Count occurrences",
                'count(all(v), x)                   // O(n) on any container\nmp.count(key)                      // O(1) on unordered_map',
                "Use unordered_map / unordered_set for O(1) average lookup; std::map is O(log n).",
            ),
            (
                "Reverse a container",
                'reverse(all(v));',
                "In-place O(n) reversal. Also works on strings.",
            ),
        ],
    },
    {
        "category": "Number Theory Tricks",
        "tricks": [
            (
                "Check if n is a power of 2",
                'bool isPow2 = n > 0 && (n & (n-1)) == 0;',
                "n & (n-1) clears the lowest set bit. If result is 0, only one bit was set.",
            ),
            (
                "Number of divisors of n",
                '// After factorisation f = {p: e, ...}:\nll d = 1;\nfor (auto& [p, e] : f) d *= (e + 1);',
                "Product of (exponent+1) for each prime in the factorisation.",
            ),
            (
                "Sum of divisors of n",
                '// After factorisation:\nll sigma = 1;\nfor (auto& [p, e] : f)\n    sigma *= (powmod(p, e+1) - 1) / (p - 1);',
                "Formula: product of (p^(e+1) - 1) / (p - 1). Use modular arithmetic for large n.",
            ),
            (
                "Euler's totient φ(n)",
                'll phi = n;\nfor (auto& [p, e] : f) phi = phi / p * (p - 1);',
                "φ(n) = n * product(1 - 1/p) for each distinct prime p dividing n.",
            ),
            (
                "Fast even/odd check",
                'if (n & 1)  // n is odd\nif (!(n & 1))  // n is even',
                "Faster than n % 2 on some compilers, and avoids negative-number issues.",
            ),
        ],
    },
    {
        "category": "Graph & DP",
        "tricks": [
            (
                "BFS shortest path template",
                'vector<int> dist(n, -1);\nqueue<int> q;\ndist[src] = 0; q.push(src);\nwhile (!q.empty()) {\n    int u = q.front(); q.pop();\n    for (int v : adj[u])\n        if (dist[v] == -1) { dist[v] = dist[u]+1; q.push(v); }\n}',
                "BFS gives shortest path in unweighted graphs. Use Dijkstra (priority_queue) for weighted.",
            ),
            (
                "Memoisation with map",
                'map<tuple<int,int,int>, ll> memo;\nll dp(int i, int j, int k) {\n    auto key = make_tuple(i,j,k);\n    if (memo.count(key)) return memo[key];\n    return memo[key] = /* recurrence */;\n}',
                "Quick memoisation for recursive DP. Use unordered_map with a custom hash for speed.",
            ),
            (
                "Detect negative cycle (Bellman-Ford)",
                '// After n-1 relaxations, run one more:\nfor each edge (u,v,w):\n    if (dist[u]+w < dist[v]) // negative cycle reachable',
                "Run Bellman-Ford n-1 times, then one more pass. If any distance decreases, a negative cycle exists.",
            ),
        ],
    },
    {
        "category": "String Tricks",
        "tricks": [
            (
                "Frequency array for lowercase letters",
                'int freq[26] = {};\nfor (char c : s) freq[c - \'a\']++;',
                "O(1) lookup per character. Useful for anagram checks, character counting.",
            ),
            (
                "Check if two strings are anagrams",
                'sort(all(s)); sort(all(t)); return s == t;\n// or compare freq arrays for O(n)',
                "Sorting approach is O(n log n). Frequency array approach is O(n).",
            ),
            (
                "String to integer / integer to string",
                'int x = stoi(s);\nstring s = to_string(x);',
                "stoi throws on invalid input. Use try/catch or validate first in production code.",
            ),
        ],
    },
    {
        "category": "Common Pitfalls to Avoid",
        "tricks": [
            (
                "Off-by-one in binary search",
                '// Use lo + (hi-lo)/2, check boundary conditions carefully\n// Template: lo=0, hi=n-1 for index; lo=min_val, hi=max_val for value',
                "Most WA in binary search come from wrong boundary updates (lo=mid vs lo=mid+1).",
            ),
            (
                "Initialise all DP arrays",
                'fill(dp, dp+MAXN, -1);  // or\nvector<ll> dp(n, INF);',
                "Uninitialised DP arrays cause silent wrong answers that are hard to debug.",
            ),
            (
                "Use ll for array indices when n can be large",
                'for (ll i = 0; i < (ll)v.size(); i++)',
                "v.size() returns size_t (unsigned). Comparing signed int with unsigned can cause bugs when i < 0.",
            ),
            (
                "Set precision for floating-point output",
                'cout << fixed << setprecision(9) << answer;',
                "Always set precision when outputting doubles. Default precision is only 6 significant digits.",
            ),
        ],
    },
]


# ── PDF builder ───────────────────────────────────────────────────────────────
def build_pdf(output_path):
    doc = SimpleDocTemplate(
        output_path,
        pagesize=A4,
        leftMargin=2*cm, rightMargin=2*cm,
        topMargin=2*cm,  bottomMargin=2*cm,
    )

    story = []

    # ── Cover page ────────────────────────────────────────────────────────────
    cover_table = Table(
        [[Paragraph("Competitive Programming", S["cover_title"]),
          Paragraph("Templates &amp; Tricks", S["cover_title"]),
          Paragraph("", S["cover_sub"]),
          Paragraph("MontassarBr / ProblemSolving", S["cover_sub"]),
          Paragraph("C++ Reference Book", S["cover_sub"])]],
        colWidths=["100%"],
    )
    cover_table.setStyle(TableStyle([
        ("BACKGROUND", (0,0), (-1,-1), DARK_BLUE),
        ("TOPPADDING",  (0,0), (-1,-1), 40),
        ("BOTTOMPADDING",(0,0),(-1,-1), 40),
        ("LEFTPADDING", (0,0), (-1,-1), 20),
        ("RIGHTPADDING",(0,0), (-1,-1), 20),
        ("ALIGN",       (0,0), (-1,-1), "CENTER"),
    ]))
    story.append(cover_table)
    story.append(Spacer(1, 1*cm))

    # Decorative banner
    banner = Table([[""]],
        colWidths=["100%"], rowHeights=[8])
    banner.setStyle(TableStyle([("BACKGROUND",(0,0),(-1,-1), ACCENT)]))
    story.append(banner)
    story.append(Spacer(1, 0.5*cm))

    story.append(body(
        "This document is automatically generated from the "
        "<b>MontassarBr/ProblemSolving</b> repository. It collects all reusable "
        "C++ templates along with explanations, real-world use cases drawn from "
        "competitive programming problems, and a curated list of tips &amp; tricks "
        "to help you solve problems faster and avoid common mistakes."
    ))
    story.append(Spacer(1, 0.3*cm))
    story.append(hr())
    story.append(PageBreak())

    # ── Table of Contents ─────────────────────────────────────────────────────
    story += section("Table of Contents")
    story.append(Paragraph("<b>Part I — Algorithm &amp; Data Structure Templates</b>", S["toc_section"]))
    story.append(Spacer(1, 4))
    for t in TEMPLATES:
        story.append(Paragraph(t["title"], S["toc_entry"]))
    story.append(Spacer(1, 10))
    story.append(Paragraph("<b>Part II — Competitive Programming Tricks</b>", S["toc_section"]))
    story.append(Spacer(1, 4))
    for section_data in CP_TRICKS:
        story.append(Paragraph(f"• {section_data['category']}", S["toc_entry"]))
    story.append(PageBreak())

    # ── Part I : Templates ────────────────────────────────────────────────────
    story += section("Part I — Templates")

    for t in TEMPLATES:
        block = []
        block += subsection(t["title"])
        block.append(body(t["description"]))
        block.append(Spacer(1, 4))
        block.append(label("Code:"))
        block.append(code_block(t["code"]))
        block.append(Spacer(1, 4))
        block.append(label("Use Cases:"))
        for uc in t["use_cases"]:
            block.append(use_case(uc))
        block.append(hr())
        block.append(Spacer(1, 6))
        story += block

    story.append(PageBreak())

    # ── Part II : CP Tricks ───────────────────────────────────────────────────
    story += section("Part II — Useful CP Tricks")
    story.append(body(
        "The following tricks are language- and algorithm-level techniques that "
        "frequently appear in competitive programming. Master them to write faster, "
        "more correct solutions."
    ))
    story.append(Spacer(1, 8))

    for sec in CP_TRICKS:
        story += subsection(sec["category"])
        for name, code_str, explanation in sec["tricks"]:
            inner = []
            inner.append(Paragraph(f"<b>{name}</b>", S["h3"]))
            inner.append(code_block(code_str))
            inner.append(trick_box(explanation))
            inner.append(Spacer(1, 8))
            story.append(KeepTogether(inner))
        story.append(hr())

    doc.build(story)
    print(f"PDF generated: {output_path}")


if __name__ == "__main__":
    out = "/home/runner/work/ProblemSolving/ProblemSolving/CP_Templates_and_Tricks.pdf"
    build_pdf(out)
