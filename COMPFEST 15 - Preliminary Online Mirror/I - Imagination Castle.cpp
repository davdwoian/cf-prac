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

int r[maxn], c[maxn];

void solve() {
    int n, m, k; cin >> n >> m >> k;
    l0r(i, k) {
        int x, y; cin >> x >> y;
        r[x] = max(r[x], y);
        c[y] = max(c[y], x);
    }
    int x = n, y = m;
    while (x && y) {
        if (r[x] > y) {
            -- x; continue;
        }
        if (c[y] > x) {
            -- y; continue;
        }
        if (x == 1 && y == 1) {
            cout << "Bhinneka" << '\n';
            return;
        }
        -- x, -- y;
    }
    cout << "Chaneka" << '\n';
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