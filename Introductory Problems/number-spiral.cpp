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
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        lli y, x;
        cin >> y >> x;
        if (x == y) {
            cout << x*x-(y-1) << endl;
        } else if (x > y && x%2 == 1) {
            cout << x*x-(y-1) << endl;
        } else if (x > y && x%2 == 0) {
            cout << (x-1)*(x-1)+y << endl;
        } else if (x < y && y%2 == 1) {
            cout << (y-1)*(y-1)+x << endl;
        } else if (x < y && y%2 == 0) {
            cout << y*y-(x-1) << endl;
        }
    }
    return 0;
}