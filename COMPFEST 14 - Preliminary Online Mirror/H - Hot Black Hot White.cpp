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

int sqm3(int x) { return (x % 3) * (x % 3) % 3; };
char c[maxn];
int a[maxn];

void solve() {
    int n; cin >> n;

    int z = 0;
    l0r(i, n) cin >> a[i], z += sqm3(a[i]);
    cout << (z > n / 2 ? 0 : 2) << '\n';
    
    vector<int> idx(n); iota(idx.bg(), idx.ed(), 0);
    sort(idx.bg(), idx.ed(), [&](int x, int y) { return sqm3(a[x]) < sqm3(a[y]); });
    l0r(i, n) c[idx[i]] = i < n / 2 ? '1' : '0';
    cout << c << '\n';
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