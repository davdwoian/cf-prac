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

void solve() {
    int n; cin >> n;

    int l = 3, r = INF << 1;
    while (l < r) {
        int m = l + ((r - l) >> 1);
        
        if (((m - 1) / 2) + (max(m - 4, 0) / 4) < n) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    cout << l << '\n';
}

// c^2 = b^2 - a^2 = (a+x)^2 - a^2 = x^2 + 2ax
// x = 1 => 1 + 2a => 3 5 7 ...
// x = 2 => 4 + 4a => 8 12 ...

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