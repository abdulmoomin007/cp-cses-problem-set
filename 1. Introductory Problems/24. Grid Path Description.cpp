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

const int n = 7;
string s = "";
bool vis[n][n];

int ans = 0;

void dfs(int i, int j, int k)
{
    // cout << k << endl;
    if (vis[i][j])
        return;
    if (i == n - 1 && j == 0 && k == (n * n - 1))
    {
        ans++;
        return;
    }
    if (i == n - 1 && j == 0)
        return;
    if (k >= (n * n - 1))
        return;

    if (j == n - 1 && i - 1 >= 0 && i + 1 < n && !vis[i - 1][j] && !vis[i + 1][j])
        return;
    if (i == n - 1 && j - 1 >= 0 && j + 1 < n && !vis[i][j - 1] && !vis[i][j + 1])
        return;
    if (i == 0 && j - 1 >= 0 && j + 1 < n && !vis[i][j - 1] && !vis[i][j + 1])
        return;
    if (j == 0 && i - 1 >= 0 && i + 1 < n && !vis[i - 1][j] && !vis[i + 1][j])
        return;

    if (i - 1 >= 0 && vis[i - 1][j] && i + 1 < n && vis[i + 1][j] && j - 1 >= 0 && j + 1 < n && !vis[i][j - 1] && !vis[i][j + 1])
        return;
    if (i + 1 < n && vis[i + 1][j] && i - 1 >= 0 && vis[i - 1][j] && j - 1 >= 0 && j + 1 < n && !vis[i][j - 1] && !vis[i][j + 1])
        return;
    if (j - 1 >= 0 && vis[i][j - 1] && j + 1 < n && vis[i][j + 1] && i - 1 >= 0 && i + 1 < n && !vis[i - 1][j] && !vis[i + 1][j])
        return;
    if (j + 1 < n && vis[i][j + 1] && j - 1 >= 0 && vis[i][j - 1] && i - 1 >= 0 && i + 1 < n && !vis[i - 1][j] && !vis[i + 1][j])
        return;

    if (s[k] == 'L' || s[k] == '?')
    {
        vis[i][j] = 1;
        if (j - 1 >= 0)
            dfs(i, j - 1, k + 1);
        vis[i][j] = 0;
    }
    if (s[k] == 'R' || s[k] == '?')
    {
        vis[i][j] = 1;
        if (j + 1 < n)
            dfs(i, j + 1, k + 1);
        vis[i][j] = 0;
    }
    if (s[k] == 'U' || s[k] == '?')
    {
        vis[i][j] = 1;
        if (i - 1 >= 0)
            dfs(i - 1, j, k + 1);
        vis[i][j] = 0;
    }
    if (s[k] == 'D' || s[k] == '?')
    {
        vis[i][j] = 1;
        if (i + 1 < n)
            dfs(i + 1, j, k + 1);
        vis[i][j] = 0;
    }
}

// Solve function for each test case
void solve()
{
    cin >> s;
    dfs(0, 0, 0);
    cout << ans;
}