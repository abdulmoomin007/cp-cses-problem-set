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

// GNU PBDS
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// ordered_set: supports find_by_order() and order_of_key()
template <typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

// Ordered Multiset (allows duplicates using pair<T, int> with unique index)
template <typename T>
using ordered_multiset = tree<
    T,
    null_type,
    less_equal<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

// Solve function for each test case
void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    vll aa(n);
    vll ps = {0LL};
    ll acc = 0;
    for (ll &x : aa)
    {
        cin >> x;
        acc += x;
        ps.push_back(acc);
    }
    // let's do the optimal way

    ordered_multiset<ll> oms;
    rep(i, a, b + 1) oms.insert(ps[i]);
    ll ans = max(*oms.find_by_order(oms.size() - 1) - ps[0], -LINF);

    rep(i, 0, n - a + 1)
    {
        ans = max(*oms.find_by_order(oms.size() - 1) - ps[i], ans);
        oms.erase(oms.find_by_order(oms.order_of_key(ps[a + i])));
        if (i + b + 1 <= n)
            oms.insert(ps[i + b + 1]);
    }

    cout << ans;
}