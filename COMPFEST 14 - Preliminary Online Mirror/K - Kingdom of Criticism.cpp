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

#define maxn 400010
#define maxm 2000010

int f[maxm], h[maxm], z;

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]); 
}

int add(int hg) {
    f[z] = z, h[z] = hg;
    return z ++;
}

bool cmp(int x, int y) {
    return h[x] < h[y];
};
multiset<int, function<bool(int, int)>> s(cmp);

void solve() {
    int n; cin >> n;
    z = n + 1;
    lor(i, 1, n+1) {
        int hg; cin >> hg;
        s.is(f[i] = add(hg));
    }

    int q; cin >> q;
    while (q --) {
        int t; cin >> t;
        if (t == 1) {
            int k, w; cin >> k >> w;
            s.is(f[k] = add(w));
        }
        if (t == 2) {
            int k; cin >> k;
            cout << h[find(k)] << '\n';
        }
        if (t == 3) {
            int l, r; cin >> l >> r;
            db m = (l + r) / 2.0;

            int bl = add(l - 1);
            int br = add(r + 1);

            h[0] = l;
            auto lb = s.lower_bound(0);
            h[0] = r;
            auto rb = s.upper_bound(0);

            while (lb != rb) f[*lb] = h[*lb] < m ? bl : br, lb = s.erase(lb);
            
            s.is(bl);
            s.is(br);
        }
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

    int t; t = 1;
    while (t --) solve();

    return 0;
}