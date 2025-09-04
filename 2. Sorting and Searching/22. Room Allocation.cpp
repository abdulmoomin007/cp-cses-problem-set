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
    vector<pair<pii, int>> a(n);
    int o = 0;
    for (auto &x : a)
    {
        cin >> x.first.first;
        cin >> x.first.second;
        x.second = o++;
    }
    priority_queue<int, vector<int>, greater<int>> h;
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    rep(i, 1, n + 1) h.push(i);
    vi ans(n);
    int mi = -INF;
    sort(all(a));

    for (auto [p, i] : a)
    {
        while (pq.size() && pq.top().first < p.first)
        {
            h.push(pq.top().second);
            pq.pop();
        }
        mi = max(mi, h.top());
        pq.push({p.second, h.top()});
        ans[i] = h.top();
        h.pop();
    }

    cout << mi << endl;
    for (int &x : ans)
        cout << x << " ";
}