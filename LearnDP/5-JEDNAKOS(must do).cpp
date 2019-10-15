#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vii;
 
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)
#define s(n) cin >> n
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rsz(x,n) x.clear(); x.resize(n)
#define rrsz(x,a,n) x.clear(); x.resize(n,a)
#define wt while(true)
#define all(x) x.begin(),x.end()
#define pb push_back
#define ls(x) ((2*(x)) + 1)
#define rs(x) ((ls(x)) + 1)
#define md(a,b) (((a) + (b))/2)
#define INF (1e9 + 7)
 
ll t, u, v, n, k, m;
string ss, s1, s2;
const int N = 5010;
int DP [N][N];
int P [N];
int rec (int pos, int rem) {
	if (pos == n && rem == 0) return 0;
	if (pos == n) return INF;
	if (DP[pos][rem] != -1) return DP[pos][rem];
	int ans = INF;
	int qk = 0;
	for (int i = P[pos]; i < n; ++i) {
		qk = qk * 10 + (s1[i] - '0');
		if (qk > rem) break;
		ans = min(ans, 1 + rec(i + 1, rem - qk));
	}
	return DP[pos][rem] = ans;
}
int main(){
	csl;
	cin >> ss;
	int p;
	for (p = 0; p < ss.size(); ++p) {
		if (ss[p] != '=')
			s1.push_back(ss[p]);
		else break;
	}
	reps (i, p + 1, ss.size()) {
		s2.push_back(ss[i]);
	}
	int sum = 0;
	n = s1.size();
	P[n - 1] = n - 1;
	for (int i = n - 2; i >= 0; --i) {
		P[i] = (s1[i] == '0') ? P[i + 1] : i;
	}
	rep (i, s2.size()) {
		sum = sum * 10 + (s2[i] - '0');
	}
	rep (i, n + 1)
		rep (j, sum + 1)
			DP[i][j] = -1;
	cout << rec(0, sum) - 1 << '\n';
    return 0;
}
