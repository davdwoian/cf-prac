#include "bits/stdc++.h"

using db = long double;
using ll = long long;
using namespace std;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdb = pair<db, db>;

#define INF 0x3f3f3f3f
#define LNF 0x3f3f3f3f3f3f3f3fll
#define MOD 998244353

#define eb emplace_back
#define pb pop_back
#define is insert
#define fn front
#define bk back
#define bg begin
#define ed end
#define pq priority_queue
#define bcnt __builtin_popcount

#define l0r(a, b) for (int a = 0; a < (b); ++ a)
#define lor(a, b, c) for (int a = (b); a < (c); ++ a)
#define r0r(a, b) for (int a = (b) - 1; a >= 0; -- a)
#define ror(a, b, c) for (int a = (c) - 1; a >= b; -- a)

#define maxn 100010

// inv, cnt 0, cnt 1
ll f[maxn], g[maxn], k[maxn];
vector<pii> G[maxn];

void dfs(int u) {
    if (g[u] | k[u]) return;

    for (auto& [v, w] : G[u]) {
        dfs(v);

        f[u] = (f[u] + f[v] + (w + k[u]) * ((w^1) + g[v]) % MOD) % MOD;
        g[u] = (g[u] + (w^1) + g[v]) % MOD;
        k[u] = (k[u] + w + k[v]) % MOD;
    }
}

void solve() {
    int n; cin >> n;
    lor(i, 1, n+1) {
        int s; cin >> s;
        l0r(j, s) {
            int l, w; cin >> l >> w;
            G[i].eb(l, w);
        }
    }

    dfs(1);
    cout << f[1] << '\n';
}

int main()
{
    #ifdef LC
        freopen("zz.in", "r+", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; t = 1;
    while (t --) solve();

    return 0;
}