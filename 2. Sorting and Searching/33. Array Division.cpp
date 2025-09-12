// Binary search
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
using vs = vector<string>;

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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

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
    // cin >> T;
    while (T--)
    {
        solve();
        // cout << "\n";
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

// Solve function for each test case
void solve()
{
    int n, k;
    cin >> n >> k;
    vll a(n);
    ll tot = 0;
    ll ma = -LINF;
    for (ll &x : a)
    {
        cin >> x;
        tot += x;
        ma = max(x, ma);
    }
    ll l = ma, r = tot;
    ll ans = tot;
    auto test = [&](ll x)
    {
        int part = 1;
        ll cur = 0;
        rep(i, 0, n)
        {
            cur += a[i];
            if (cur > x)
            {
                cur = a[i];
                part++;
            }
        }
        return part <= k;
    };
    while (l <= r)
    {
        ll m = (l + r) / 2;
        if (test(m))
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << ans;
}