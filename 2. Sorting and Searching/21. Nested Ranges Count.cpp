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
    int n;
    cin >> n;
    vector<pii> a(n);
    ordered_set<pii> os;
    map<pii, int> ind;
    int i = 0;
    for (pii &p : a)
    {
        cin >> p.first;
        cin >> p.second;
        ind[p] = i;
        i++;
    }
    sort(all(a), [](pii x, pii y)
         {
        if(x.first == y.first) return x.second > y.second;
        return x.first < y.first; });
    vi cs(n),
        cd(n);
    rep(i, 0, n)
    {
        os.insert({a[i].second, -i});
        cd[ind[a[i]]] = os.size() - os.order_of_key({a[i].second, -i}) - 1;
    }
    os.clear();

    for (int i = n - 1; i >= 0; i--)
    {
        os.insert({a[i].second, -i});
        cs[ind[a[i]]] = os.order_of_key({a[i].second, -i});
    }

    for (int &x : cs)
        cout << x << " ";
    cout << endl;
    for (int &x : cd)
        cout << x << " ";
}

/*
3 0 1 1 0
0 2 0 1 2
*/