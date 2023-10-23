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
#define gcd __gcd

#define l0r(a, b) for (int a = 0; a < (b); ++ a)
#define lor(a, b, c) for (int a = (b); a < (c); ++ a)
#define r0r(a, b) for (int a = (b) - 1; a >= 0; -- a)
#define ror(a, b, c) for (int a = (c) - 1; a >= b; -- a)

int len(ll x) {
    return x == 0 ? 1 : (1 + len(x / 10) - (x < 10));
}

vector<ll> cont;
ll shft[20];

void init() {
    // a, a * d, a * d^2 (d > 1)
    // len(a) <= len(a * d) <= len(a * d^2)
    // 3 * len(a) <= len(a) + len(a * d) + len(a * d^2) <= 15
    // len(a) <= 5

    // a, a * d, a * d^2 <= 1e5
    // d = p / q (p > q)
    // all(a, ap/q, ap^2/q^2, ...| ap/q <= 1e5) <=> all(aq^2, apq, ap^2, ... | apq <= 1e5)

    ll m = 1e5;
    
    shft[0] = 1;
    lor(i, 1, 17) shft[i] = shft[i-1] * 10;

    lor(q, 1, m+1) {
        lor(p, q+1, m/q+1) {
            if (gcd(p, q) != 1) continue;
            lor(k, 1, m/p/q+1) {
                ll a = 1ll * k * q * q;
                ll b = 1ll * k * p * q;
                ll c = 1ll * k * p * p;

                int la = len(a);
                int lb = len(b);
                int lc = len(c);

                if (la + lb + lc > 15) break;

                ll num = a * shft[lb + lc] + b * shft[lc] + c;
                while (1) {
                    cont.eb(num);

                    if ((c * p) % q != 0) break;
                    c = c * p / q;
                    lc += len(c);

                    if (la + lb + lc > 15) break;
                    num = num * shft[len(c)] + c;
                }
            }
        }
    }

    sort(cont.bg(), cont.ed());
    cont.erase(unique(cont.bg(), cont.ed()), cont.ed());
}

void solve() {
    ll l, r; cin >> l >> r;

    int lb = lower_bound(cont.bg(), cont.ed(), l) - cont.bg();
    int rb = upper_bound(cont.bg(), cont.ed(), r) - cont.bg();

    cout << rb - lb << '\n';
}

int main()
{
    #ifdef LC
        freopen("zz.in", "r+", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    int t; cin >> t;  
    lor(i, 1, t+1) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}