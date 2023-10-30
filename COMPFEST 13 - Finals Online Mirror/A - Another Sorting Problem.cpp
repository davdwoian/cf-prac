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
#define fi first
#define se second
#define pq priority_queue
#define bcnt __builtin_popcount
 
#define l0r(a, b) for (int a = 0; a < (b); ++ a)
#define lor(a, b, c) for (int a = (b); a < (c); ++ a)
#define r0r(a, b) for (int a = (b) - 1; a >= 0; -- a)
#define ror(a, b, c) for (int a = (c) - 1; a >= b; -- a)
 
char rev(char c) {
    return 'A' + ('Z' - c);
}
 
void solve() {
    int n, m; cin >> n >> m;
 
    vector<pair<string, int>> v;
 
    l0r(i, n) {
        string s; cin >> s;
        for (int j = 1; j < m; j += 2) s[j] = rev(s[j]);
        v.eb(s, i);
    }
 
    sort(v.begin(), v.end());
 
    for (auto& [s, i] : v) cout << i + 1 << ' ';
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