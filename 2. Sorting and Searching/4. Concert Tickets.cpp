// ordered multiset
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
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    for (int &x : a)
        cin >> x;
    for (int &x : b)
        cin >> x;
    ordered_multiset<int> oms;
    for (int x : a)
        oms.insert(x);
    for (int x : b)
    {
        int i = oms.order_of_key(x);
        if (*oms.find_by_order(i) == x)
        {
            cout << x << endl;
            oms.erase(oms.find_by_order(i));
        }
        else
        {
            i -= 1;
            if (i == -1)
                cout << -1 << endl;
            else
            {
                cout << *oms.find_by_order(i) << endl;
                oms.erase(oms.find_by_order(i));
            }
        }
    }
}