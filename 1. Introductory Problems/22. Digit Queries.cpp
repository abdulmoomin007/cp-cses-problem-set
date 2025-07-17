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
    cin >> T;
    while (T--)
    {
        solve();
        cout << "\n";
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

// Solve function for each test case
void solve()
{
    ll n;
    cin >> n;
    // cout << n;
    // 1 - 9 = 9 x 1
    // 10 - 99 = 90 x 2
    // 100 - 999 = 900 x 3
    // 1000 - 9999 = 9000 x 4
    ll i = 1, j = 9;
    ll from = 1, to = 9;
    ll rFrom = 1, rTo = 9;

    while (true)
    {
        if (rTo >= n)
        {
            // cout << from << " " << to << endl;
            // cout << rFrom << " " << rTo << endl;
            n = n - rFrom + 1;
            cout << to_string(from + (n - 1) / i)[(n - 1) % i];
            break;
        }
        i++;
        j *= 10;
        from = to + 1;
        to += j;
        rFrom = rTo + 1;
        rTo += j * i;
    }
}