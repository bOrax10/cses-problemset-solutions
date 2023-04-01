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

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
    } else if (1 < n && n < 4) {
        cout << "NO SOLUTION" << endl;
    } else if (n == 4) {
        cout << "2 4 1 3" << endl;
    } else {
        for (int i = 1; i <= n; i += 2) {
            cout << i << " ";
        }
        for (int i = 2; i <= n; i += 2) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}