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

#define maxn 510

char a[maxn], b[maxn];
int nxt[maxn], aut[maxn][2], dp[maxn][maxn][maxn];

void kmp(int n) {
    aut[0][0] = b[0] == '0';
    aut[0][1] = b[0] == '1';

    for (int i = 1, j = 0; i <= n; ++ i) {
        while (j && b[i] != b[j]) j = nxt[j];
        if (b[i] == b[j]) ++ j;
        nxt[i+1] = j;

        aut[i][0] = b[i] == '0' ? (i + 1) : aut[nxt[i]][0];
        aut[i][1] = b[i] == '1' ? (i + 1) : aut[nxt[i]][1];
    }
}

void solve() {
    int n, m; cin >> n >> m;
    cin >> a >> b;

    kmp(m);

    memset(dp, 0x3f, sizeof dp);
    dp[0][0][0] = 0;

    l0r(i, n) {
        l0r(j, m+1) {
            l0r(k, n-m+1) {
                l0r(l, 2) {
                    int s = aut[j][l];
                    dp[i+1][s][k+(s==m)] = min(dp[i+1][s][k+(s==m)], dp[i][j][k] + (a[i] != '0' + l));
                }
            }
        }
    }

    l0r(k, n-m+2) {
        int res = INF;
        l0r(i, m+1) res = min(res, dp[n][i][k]);
        cout << (res == INF ? -1 : res) << ' ';
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