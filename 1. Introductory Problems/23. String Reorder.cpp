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
    string s;
    cin >> s;
    int n = s.length();
    vi freq(26, 0);
    for (char c : s)
        freq[c - 'A']++;
    string ans;

    while (int(ans.size()) < n)
    {
        bool canFinishAtAll = true;
        rep(i, 0, 26)
        {
            if (freq[i] > 0 && (ans.empty() || ans.back() != char(i + 'A')))
            {
                ans.push_back(char(i + 'A'));
                freq[i]--;
                bool canFinish = true;
                int rem = n - ans.size();
                rep(j, 0, 26)
                {
                    if (i != j)
                    {
                        if (freq[j] > (rem + 1) / 2)
                            canFinish = false;
                    }
                    else
                    {
                        if (freq[j] > rem / 2)
                            canFinish = false;
                    }
                }
                if (canFinish)
                {
                    canFinishAtAll = true;
                    break;
                }
                else
                {
                    ans.pop_back();
                    freq[i]++;
                    canFinishAtAll = false;
                }
            }
        }
        if (!canFinishAtAll)
            break;
        // cout << ans << endl;
    }

    if (ans.empty())
        cout << -1;
    else
        cout << ans;
}