// BFS
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
    int n;
    cin >> n;
    vector<vi> a(n, vi(n));
    bool seen[n][n];
    rep(i, 0, n) rep(j, 0, n) seen[i][j] = false;
    auto inBounds = [&](int i, int j)
    {
        return i < n && j < n && i >= 0 && j >= 0;
    };
    vector<pii> dirs = {{1, 2}, {2, 1}, {-1, -2}, {-2, -1}, {1, -2}, {2, -1}, {-1, 2}, {-2, 1}};
    // BFS
    deque<pii> q = {{0, 0}};
    int depth = 0;
    while (q.size())
    {
        int t = q.size();
        rep(_, 0, t)
        {
            pii cur = q.front();
            q.pop_front();
            if (seen[cur.first][cur.second])
                continue;
            seen[cur.first][cur.second] = true;
            a[cur.first][cur.second] = depth;
            for (pii p : dirs)
            {
                if (inBounds(cur.first + p.first, cur.second + p.second) && !seen[cur.first + p.first][cur.second + p.second])
                    q.push_back({cur.first + p.first, cur.second + p.second});
            }
        }
        depth++;
        // cout << depth << endl;
    }
    rep(i, 0, n)
    {
        rep(j, 0, n) cout << a[i][j] << " ";
        cout << endl;
    }
}