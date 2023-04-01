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
    string s;
    cin >> s;
    int j = 0, ans = 0, n = s.length();
    while (j < n) {
        int cnt = 1;
        while (j+1 < n && s[j+1] == s[j]) {
            cnt++;
            j++;
        }
        ans = max(ans, cnt);
        j++;
    }
    cout << ans << endl;
    return 0;
}