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

int solve() {
    int n; cin >> n;
    lor(i, 1, n+1) cin >> a[i];
    a[n+1] = -a[n];
    ror(i, 1, n+1) a[i] = a[i] - a[i-1];

    ll sum = 0;
    lor(i, 1, n+1) {
        sum += a[i];

        if (a[i] < 0) return 0;
        if (i+3 <= n+1 && a[i+3] < 0) sum += a[i+3], a[i+3] = 0;  
        if (sum < 0) return 0;
    }
    return sum == 0;
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
        int res = solve();
        cout << (res ? "Yes" : "No") << '\n';
    }

    return 0;
}