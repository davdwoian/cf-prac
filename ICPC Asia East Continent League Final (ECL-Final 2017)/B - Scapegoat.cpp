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

#define maxn 200010

int a[maxn];
db xm;

db cost(int x, int k) {
    db e = 1.0 * a[x] / k;
    return k * (e - xm) * (e - xm);
}

db del(int x, int k) {
    return cost(x, k+1) - cost(x, k);
}

bool cmp(pii x, pii y) {
    return del(x.fi, x.se) > del(y.fi, y.se); 
}

void solve() {
    cout << setprecision(16);
    int n, m; cin >> n >> m;
    l0r(i, n) cin >> a[i];
    xm = 0;
    l0r(i, n) xm += a[i];
    xm /= m;
    pq<pii, vector<pii>, function<bool(pii, pii)>> q(cmp);
    l0r(i, n) q.push(pii(i, 1));
    l0r(i, m-n) {
        auto cur = q.top(); q.pop();
        cur.se ++;
        q.push(cur);
    }
    db res = 0;
    l0r(i, n) {
        auto cur = q.top(); q.pop();
        res += cost(cur.fi, cur.se);
    }
    cout << (res / m) << '\n';
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