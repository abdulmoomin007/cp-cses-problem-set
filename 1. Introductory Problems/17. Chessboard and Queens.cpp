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
    vs a(8);
    for (string &s : a)
        cin >> s;
    int ans = 0;

    function<bool(int, int)> canPlace = [&](int i, int j)
    {
        if (a[i][j] != '.')
            return false;
        rep(k, 0, 8)
        {
            if (k == i)
                continue;
            if (a[k][j] == 'Q')
                return false;
        }
        int k = i - 1, l = j - 1;
        while (k >= 0 && l >= 0)
        {
            if (a[k][l] == 'Q')
                return false;
            k--;
            l--;
        }
        k = i + 1, l = j + 1;
        while (k < 8 && l < 8)
        {
            if (a[k][l] == 'Q')
                return false;
            k++;
            l++;
        }
        k = i + 1, l = j - 1;
        while (k < 8 && l >= 0)
        {
            if (a[k][l] == 'Q')
                return false;
            k++;
            l--;
        }
        k = i - 1, l = j + 1;
        while (k >= 0 && l < 8)
        {
            if (a[k][l] == 'Q')
                return false;
            k--;
            l++;
        }
        return true;
    };

    function<void(int)> backtrack = [&](int i)
    {
        if (i == 8)
        {
            ans++;
            return;
        }
        rep(j, 0, 8)
        {
            if (canPlace(i, j))
            {
                a[i][j] = 'Q';
                backtrack(i + 1);
                a[i][j] = '.';
            }
        }
    };

    backtrack(0);
    cout << ans;
}