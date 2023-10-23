#include "bits/stdc++.h"

using db = long double;
using ll = long long;
using namespace std;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdb = pair<db, db>;

#define INF 0x3f3f3f3f
#define LNF 0x3f3f3f3f3f3f3f3fll
#define MOD 1000000007

#define eb emplace_back
#define pb pop_back
#define is insert
#define fn front
#define bk back
#define bg begin
#define ed end
#define fi first
#define se second
#define pq priority_queue
#define bcnt __builtin_popcount

#define l0r(a, b) for (int a = 0; a < (b); ++ a)
#define lor(a, b, c) for (int a = (b); a < (c); ++ a)
#define r0r(a, b) for (int a = (b) - 1; a >= 0; -- a)
#define ror(a, b, c) for (int a = (c) - 1; a >= b; -- a)

#define maxn 4040
#define maxm 6000010

struct trie {
    bool v;
    int s[2], f, dep, sz, sn, top, dfn;
} tr[maxm];

int z = 1, dfn;

int ins(string& s) {
    int u = 1;
    for (char c : s) {
        if (!tr[u].s[c - '0']) tr[u].s[c - '0'] = ++ z;
        u = tr[u].s[c - '0'];
    }
    tr[u].v = 1;
    return u;
}

// pre
void dfs(int u, int fa, int d) {
    tr[u].sz = 1;
    tr[u].f = fa;
    tr[u].dep = d;
    for (auto& v : tr[u].s) {
        if (!v) continue;
        dfs(v, u, d+1);
        tr[u].sz += tr[v].sz;
        tr[u].sn = tr[tr[u].sn].sz < tr[v].sz ? v : tr[u].sn;
    }
}

// long link
void dfs(int u, int t) {
    tr[u].top = t;
    tr[u].dfn = ++ dfn;
    if (tr[u].sn) dfs(tr[u].sn, t);
    for (auto& v : tr[u].s) {
        if (!v || v == tr[u].sn) continue;
        dfs(v, v);
    }
}

int lca(int u, int v) {
    while (tr[u].top != tr[v].top) {
        if (tr[tr[u].top].dep > tr[tr[v].top].dep) {
            u = tr[tr[u].top].f;
        } else {
            v = tr[tr[v].top].f;
        }
    }
    return tr[u].dep > tr[v].dep ? v : u;
}

string debug(int v) {
    string res = "";

    while (v) {
        int u = tr[v].f;
        if (u == 0) break;
        res = (tr[u].s[0] == v ? "0" : "1") + res;
        v = u;
    }
    return res;
}

void solve() {
    int n, m, q; cin >> n >> m >> q;

    l0r(i, min(n * m, maxm)) {
        tr[i].v = 0;
        tr[i].f = 0;
        tr[i].s[0] = 0;
        tr[i].s[1] = 0;
        tr[i].sn = 0;
        tr[i].sz = 0;
    } 
    z = 1, dfn = 0;

    vector<int> id(n);
    l0r(i, n) {
        string s; cin >> s;
        id[i] = ins(s);
    }

    dfs(1, 0, 0);
    dfs(1, 1);

    l0r(i, q) {
        vector<int> tg;
        int sz; cin >> sz;
        
        l0r(j, sz) {
            int u; cin >> u;
            tg.eb(id[u]);
        }
        sort(tg.bg(), tg.ed(), [&](int x, int y) {
            return tr[x].dfn < tr[y].dfn;
        });

        set<int> res;

        l0r(j, sz-1) {
            int u = tg[j], v = tg[j+1];
            int k = lca(u, v);
            res.is(tr[k].dep);
        }

        cout << res.size() << ' ';
        for (auto& x : res) cout << x << ' ';
        cout << '\n';
    }
}

int main()
{
    #ifdef LC
        freopen("zz.in", "r+", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;  
    lor(i, 1, t+1) {
        cout << "Case #" << i << ":\n";
        solve();
    }

    return 0;
}