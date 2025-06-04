// Math

#include <bits/stdc++.h>
using namespace std;

// Type aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

// Constants
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

// Fast I/O
#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

// Macros
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define all(x) x.begin(), x.end()

// Debug macro
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << x << endl;
#else
#define dbg(x)
#endif

// GCD & LCM
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

void solve();

int main()
{
    FAST_IO;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
        cout << "\n";
    }

    return 0;
}

// Solve function for each test case
void solve()
{
    ll i, j;
    cin >> i >> j;
    if (i > j)
    {
        if (i & 1)
        {
            cout << (i - 1) * (i - 1) + j;
        }
        else
        {
            cout << i * i - j + 1;
        }
    }
    else if (j > i)
    {
        if (j & 1)
        {
            cout << j * j - i + 1;
        }
        else
        {
            cout << (j - 1) * (j - 1) + i;
        }
    }
    else
    {
        cout << i * j - i + 1;
    }
}