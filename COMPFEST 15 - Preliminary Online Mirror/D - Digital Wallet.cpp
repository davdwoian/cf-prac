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

#define maxn 15
#define maxm 100010

unordered_map<int, ll> dp[maxm];
ll a[maxm][maxn];

void solve() {
    int n, m, k; cin >> n >> m >> k;

    lor(i, 1, n+1) lor(j, 1, m+1) cin >> a[j][i];
    lor(i, 1, m+1) sort(a[i]+1, a[i]+n+1), reverse(a[i]+1, a[i]+n+1);
    lor(i, 1, m+1) lor(j, 1, n+1) a[i][j] += a[i][j-1];

    dp[0][0] = 0;
    lor(i, 1, m+1) {
        int l = max(i-k+1, 0), r = min(i, m-k+1); 
        lor(j, l, r+1) {
            l0r(s, min(j, n)+1) {
                if (dp[i-1].count(j-s)) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-s] + a[i][s]);
                }
            }
        }
    }
    cout << dp[m][m-k+1] << '\n';
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