#include "bits/stdc++.h"

using db = long double;
using ll = long long;
using namespace std;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdb = pair<db, db>;

#define INF 0x3f3f3f3f
#define LNF 0x3f3f3f3f3f3f3f3fll
#define MOD (int) (1e9+7)

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
#define M_PI 3.14159265358979323846

#define l0r(a, b) for (int a = 0; a < (b); ++ a)
#define lor(a, b, c) for (int a = (b); a < (c); ++ a)
#define r0r(a, b) for (int a = (b) - 1; a >= 0; -- a)
#define ror(a, b, c) for (int a = (c) - 1; a >= b; -- a)

#define maxn 100010
#define maxr 150000

pii p[maxn];

void solve() {
    int n, k; cin >> n >> k;

    db l = 0, r = 0;
    
    l0r(i, n) cin >> p[i].fi >> p[i].se, r = max(r, (db) hypot(p[i].fi, p[i].se) + 1);

    while (r - l > 1e-9) {
        db m = (l + r) / 2.0;

        vector<pair<db, int>> vec;
        l0r(i, n) {
            if (p[i].fi == 0 && p[i].se == 0) {
                vec.eb(-M_PI, 1); continue;
            }

            db dis = hypot(p[i].fi, p[i].se);
            if (dis > 2 * m) continue;

            db del = acos(dis / (2 * m));
            db mid = atan2(p[i].se, p[i].fi);

            db la = mid - del + (mid - del < -M_PI) * 2.0 * M_PI;
            db lb = mid + del - (mid + del > M_PI) * 2.0 * M_PI;

            vec.eb(la, 1);
            vec.eb(lb, -1);
            if (lb < la) vec.eb(-M_PI, 1);
        }

        sort(vec.bg(), vec.ed());

        int sum = 0, mx = 0;
        l0r(i, vec.size()) sum += vec[i].se, mx = max(mx, sum);

        if (mx >= k) {
            r = m;
        } else {
            l = m + 1e-9;
        }
    }

    cout << l << '\n';
}

int main()
{
    #ifdef LC
        freopen("zz.in", "r+", stdin);
    #endif

    cout << setprecision(16);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; t = 1;  
    while (t --) solve();

    return 0;
}