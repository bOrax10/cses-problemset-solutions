#include <bits/stdc++.h>
using namespace std;
 
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repb(i,a,b) for(int i=a;i>=b;i--)
#define endl '\n'
#define print(x) cout<<x<<endl
#define printInline(x) cout<<x<<" "
 
#define ll long long
#define lli long long int
 
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vpi vector<pair<int,int>>
#define vpll vector<pair<long long,long long>>
 
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define popb pop_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
 
const int MAXN = 2e5 + 5, LOGN = 20;
 
int n, q, a[MAXN], M[MAXN][LOGN];
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        M[i][0] = a[i];
    }
 
    // Precompute the minimum values for all subarrays of size 2^j
    for (int j = 1; j < LOGN; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            M[i][j] = min(M[i][j-1], M[i+(1<<(j-1))][j-1]);
        }
    }
 
    // Answer the queries using the precomputed minimum values
    while (q--) {
        int a, b;
        cin >> a >> b;
        int k = log2(b - a + 1);
        int ans = min(M[a][k], M[b-(1<<k)+1][k]);
        cout << ans << "\n";
    }
 
    return 0;
}