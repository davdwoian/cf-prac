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

#define maxa 100010

ll l[maxa];

void solve() {
    int p[5];
    l0r(i, 5) cin >> p[i];

    int n; cin >> n;
    ll res = 0;
    l0r(i, n) {
        int m; cin >> m;
        if (m <= 48) {
            res += p[0];
        } else if (m <= 56) {
            res += p[1];
        } else if (m <= 60) {
            res += p[2];
        } else if (m <= 62) {
            res += p[3];
        } else {
            res += p[4];
        }
    }
    cout << res * 10000 << '\n';
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
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}