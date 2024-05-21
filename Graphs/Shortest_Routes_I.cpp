#include <bits/stdc++.h>
using namespace std;

//========================Debug======================================

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}

#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

//=========================MACROS====================================

#define rep(i, a, b) for (int i = a; i < b; i++)
#define repb(i, a, b) for (int i = a; i >= b; i--)
#define endl '\n'
#define print(x) cout << x << endl
#define printInline(x) cout << x << " "
#define printContainer(x)  \
    for (auto it : x)      \
        cout << it << " "; \
    cout << endl
#define printMap(x)   \
    for (auto it : x) \
    cout << it.first << " " << it.second << endl

#define ll long long
#define lli long long int

#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vpi vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>

#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define popb pop_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

#define deci(n) fixed << setprecision(n)
#define high(n) __builtin_popcount(n)
#define highll(n) __builtin_popcountll(n)
#define parity(n) __builtin_parity(n)
#define clz(n) __builtin_clz(n)
#define clzll(n) __builtin_clzll(n)
#define ctz(n) __builtin_ctz(n)

#define bset(a, p) ((a) | (1ll << (p)))
#define bchk(a, p) ((a) & (1ll << (p)))
#define bxor(a, p) ((a) ^ (1ll << (p)));
#define brem(a, p) (bchk(a, p) ? (bxor(a, p)) : (a))

#define lb lower_bound
#define ub upper_bound
#define er equal_range

#define findnot find_first_not_of

#define maxe *max_element
#define mine *min_element

#define mod 1000000007
#define mod2 998244353
#define PI 3.1415926535897932384
#define INF LLONG_MAX

#define gcd __gcd
#define kira ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl

#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define osetlli tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

#define ofk order_of_key
#define fbo find_by_order
// member functions :
// 1. order_of_key(k) : number of elements sbtriectly lesser than k
// 2. find_by_order(k) : k-th element in the set

//==============================FUNCTIONS===========================================

auto clk = clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
/*void run_time()
{
#ifndef ONLINE_JUDGE
    cout << endl;
    cout << "Time elapsed: " << (double)(clock() - clk) / CLOCKS_PER_SEC << endl;
#endif
    return;
}*/

inline ll power(ll x, ll y, ll p = mod)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

inline ll modadd(ll a, ll b, ll m = mod)
{
    a += b;
    if (a >= m)
        a -= m;
    return a;
}

inline ll modmul(ll a, ll b, ll m = mod)
{
    return ((a % m) * (b % m)) % m;
}

inline ll modi(ll a, ll m = mod) { return power(a, m - 2, m); }

//================================CODE=============================================

vector<ll> dijkstra(ll V, vector<vector<ll>> adj[], ll S)
{

    // Create a priority queue for storing the nodes as a pair {dist,node}
    // where dist is the distance from source to the node.
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    // Initialising distTo list with a large number to
    // indicate the nodes are unvisited initially.
    // This list contains distance from source to the nodes.
    vector<ll> distTo(V, LLONG_MAX);

    // Source initialised with dist=0.
    distTo[S] = 0;
    pq.push({0, S});

    // Now, pop the minimum distance node first from the min-heap
    // and traverse for all its adjacent nodes.
    while (!pq.empty())
    {
        ll node = pq.top().second;
        ll dis = pq.top().first;
        pq.pop();

        // Check for all adjacent nodes of the popped out
        // element whether the prev dist is larger than current or not.
        for (auto it : adj[node])
        {
            ll v = it[0];
            ll w = it[1];
            if (dis + w < distTo[v])
            {
                distTo[v] = dis + w;

                // If current distance is smaller,
                // push it into the queue.
                pq.push({dis + w, v});
            }
        }
    }
    // Return the list containing shortest distances
    // from source to all the nodes.
    return distTo;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll V = n + 1;
    vector<vector<ll>> adj[V];
    rep(i, 0, m)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    vector<ll> ans = dijkstra(V, adj, 1);
    rep(i, 1, ans.size())
    {
        cout << ans[i] << " ";
    }
    return;
}

int main()
{
    kira;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
