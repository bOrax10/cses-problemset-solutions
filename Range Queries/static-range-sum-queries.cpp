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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n,q;
	cin>>n>>q;
 
	int arr[n];
    lli presum[n+1]={0};
	rep(i,0,n) cin>>arr[i];
	rep(i,1,n+1) presum[i]=presum[i-1]+arr[i-1];
 
	rep(i,0,q) {
		int a,b;
		cin>>a>>b;
		print(presum[b]-presum[a-1]);
	}
 
	return 0;
}