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

vector<pii> G[maxn << 1];
ll d[maxn << 1];

void solve() {
    int n, m; cin >> n >> m;

    lor(i, 1, n+1) {
        G[i].eb(i+n, 0);
    }
    l0r(i, m) {
        int u, v, w; cin >> u >> v >> w;
        G[u].eb(v, w), G[v+n].eb(u+n, w);
    }
    
    memset(d, 0x3f, sizeof d);
    pq<pll, vector<pll>, greater<pll>> q;
    q.push(pll(0, 1));
    
    while (!q.empty()) {
        auto [cd, u] = q.top(); q.pop();
        if (d[u] != LNF) continue; 
        d[u] = cd;
        for (auto& [v, w] : G[u]) if (d[v] == LNF) q.push(pll(cd + w, v));
    }

    lor(i, 2, n+1) cout << (d[i+n] == LNF ? -1 : d[i+n]) << ' ';
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