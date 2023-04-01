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

const int MOD = 1e9+7;

int main() {
    int n;
    cin >> n;

    long long ans = 1;
    long long base = 2;

    while (n > 0) {
        if (n & 1) {
            ans = (ans * base) % MOD;
        }
        base = (base * base) % MOD;
        n >>= 1;
    }

    cout << ans << endl;

    return 0;
}