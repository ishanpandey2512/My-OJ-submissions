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
 
long long t, n, m;
vector < vll > DP;
vector < vll > Discount;
vector < vll > Price;
int main(){
	csl;
	cin >> t;
	while(t--){
		DP.clear();
		Discount.clear();
		Price.clear();
		cin >> n >> m;
		DP.resize(n), Price.resize(n), Discount.resize(n);
		rep (i, n) {
			DP[i].resize(m);
			Discount[i].resize(m);
			Price[i].resize(m);
		}
		rep (i, n) {
			rep (j, m) {
				cin >> Price[i][j];
			}
		}
		rep (i, n) {
			rep (j, m) {
				cin >> Discount[i][j];
			}
		}
		ll curmin = (1LL << 44LL);
		rep (j, m) {
			DP[0][j] = Price[0][j];
			curmin = min(Price[0][j], curmin);
		}
		reps (i, 1, n)	{
			rep (j, m){
				DP[i][j] = min(curmin + Price[i][j], DP[i - 1][j] + max(0LL, Price[i][j] - Discount[i - 1][j]));
			}
			curmin = (1LL << 44LL);
			rep (j, m)
				curmin = min(curmin, DP[i][j]);
		}
		cout << curmin << '\n';
	}
    return 0;
}
