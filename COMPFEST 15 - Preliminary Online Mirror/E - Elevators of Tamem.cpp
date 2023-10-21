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
#define maxq 330

int a[3][maxq], e[3], x[maxq], y[maxq], pos[maxq], h[maxq], z;
ll c[3][maxq][maxq], dp[maxq][maxq][maxq];

void solve() {
    int n, q; cin >> n >> q;
    
    a[0][0] = a[1][0] = a[2][0] = INF, x[0] = y[0] = h[0] = z = 1;

    lor(i, 1, q+1) cin >> a[0][i];
    lor(i, 1, q+1) a[1][i] = a[2][i] = a[0][i];

    lor(i, 1, q+1) {
        int t, p; cin >> t;
        if (t == 1) cin >> x[z] >> y[z], pos[i] = z ++, h[i] = 1;
        else cin >> p, e[p-1] ^= 1;
        l0r(j, 3) a[j][i] = e[j] ? INF : a[j][i];
    }

    l0r(i, 3) {
        lor(j, 1, q+1) {
            if (!h[j]) continue;
            int mn = a[i][j];
            r0r(k, j) {
                mn = min(mn, a[i][k]);
                if (!h[k]) continue;
                int u = pos[k], v = pos[j];
                c[i][u][v] = 1ll * mn * abs(y[u] - x[v]) + 1ll * a[i][j] * abs(y[v] - x[v]);
            }
        }
    }

    memset(dp, 0x3f, sizeof dp);
    dp[0][0][0] = 0;
    lor(i, 1, z) {
        l0r(j, i) {
            l0r(k, i) {
                int ii = i-1, jj = j, kk = k;
                l0r(l, 3) {
                   dp[i][jj][kk] = min(dp[i][jj][kk], dp[ii][jj][kk] + c[0][ii][i]);
                   dp[ii][i][kk] = min(dp[ii][i][kk], dp[ii][jj][kk] + c[1][jj][i]);
                   dp[ii][jj][i] = min(dp[ii][jj][i], dp[ii][jj][kk] + c[2][kk][i]);
                   swap(ii, jj);
                   swap(jj, kk);
                }
            }
        }
    }

    ll res = LNF;
    l0r(i, z) {
        l0r(j, z) {
            res = min(res, dp[z-1][i][j]);
            res = min(res, dp[i][z-1][j]);
            res = min(res, dp[i][j][z-1]);
        }
    }
    cout << res << '\n';
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