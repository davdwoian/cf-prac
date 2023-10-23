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
#define pq priority_queue
#define bcnt __builtin_popcount

#define l0r(a, b) for (int a = 0; a < (b); ++ a)
#define lor(a, b, c) for (int a = (b); a < (c); ++ a)
#define r0r(a, b) for (int a = (b) - 1; a >= 0; -- a)
#define ror(a, b, c) for (int a = (c) - 1; a >= b; -- a)

#define maxk 100010

ll fp(ll b, ll p=MOD-2, ll mu=1) {
    for (; p; b=b*b%MOD, p>>=1) if (p&1) mu=mu*b%MOD; return mu;
}

ll sncr(int n, int r) {
    ll res = 1, cur = 1;
    for (int i = 0; i < r; ++ i) {
        cur = (cur * (n - i)) % MOD;
        cur = (cur * fp(i + 1)) % MOD;
        res = (res + cur) % MOD;
    }
    return res;
}

void solve() {
    int n, k; cin >> n >> k;
    cout << (fp(2, n) - sncr(n, k - 1) + MOD) % MOD << '\n';
}

// nCk + nCk+1 ..  2^n - (nC0 + ... + nCk-1)

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