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

#define maxn 200010

struct seg {
    int a, l, r, ca;
} s[maxn];

auto lcmp = [](seg& x, seg& y) {
    return x.l < y.l;
};

auto rcmp = [](seg& x, seg& y) {
    return x.r > y.r;
};

void solve() {
    int n; cin >> n;
    int mx = 0;

    l0r(i, n) cin >> s[i].a, mx = max(mx, s[i].a);
    l0r(i, n) {
        int d; cin >> d;
        s[i].l = max(i - d, 0), s[i].r = min(i + d, n - 1);
    }
    sort(s, s+n, lcmp);

    int l = 0, r = mx;
    while (l < r) {
        int m = (l + r) / 2, ok = 1;
        pq<seg, vector<seg>, function<bool(seg&, seg&)>> q(rcmp);

        for (int i = 0, j = 0; i < n && ok; ++ i) {
            while (j < n && s[j].l == i) s[j].ca = s[j].a, q.push(s[j ++]);
            int s = m;
            while (s && !q.empty() && ok) {
                seg cur = q.top(); q.pop();
                ok &= cur.r >= i;
                int d = min(cur.ca, s);
                s -= d;
                cur.ca -= d;
                if (cur.ca) q.push(cur);
            }
        }
        ok &= q.empty();

        if (ok) r = m;
        else l = m + 1;
    }

    cout << l << '\n';
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