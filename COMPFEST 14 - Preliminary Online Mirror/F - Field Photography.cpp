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

int l[maxn], r[maxn];
int res[32];

void solve() {
    int n; cin >> n;

    l0r(i, n) cin >> l[i] >> r[i];

    l0r(k, 32) {
        int m = 1 << k;

        vector<int> v;
        l0r(i, n) v.eb(l[i] % m), v.eb(r[i] % m);
        sort(v.bg(), v.ed());
        v.erase(unique(v.bg(), v.ed()), v.ed());

        int sz = v.size();
        vector<int> df(sz + 1, 0);

        l0r(i, n) {
            if (r[i] - l[i] + 1 >= m) {
                df[0] ++; continue;
            }

            int lb = lower_bound(v.bg(), v.ed(), l[i] % m) - v.bg();
            int rb = lower_bound(v.bg(), v.ed(), r[i] % m) - v.bg();

            if (rb < lb) df[0] ++;
            df[lb] ++;
            df[rb+1] --;
        }

        for (int i = 0, sum = 0; i <= sz; ++ i) {
            sum += df[i];
            res[k] = max(res[k], sum);
        }
    }

    int q; cin >> q;
    while (q --) {
        int w; cin >> w;
        cout << res[(int) log2(w - (w & w - 1))] << '\n';
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