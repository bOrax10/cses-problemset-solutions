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

class DisjointSet
{
public:
    vector<int> rank, parent, size;
    int maxSize, components;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        components = n;
        maxSize = 0;
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    int findComponents(int n)
    {
        int cnt = 0;
        set<int> st;

        rep(i, 1, n + 1)
        {
            st.emplace(parent[i]);
        }
        return st.size();
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
        components--;
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        components--;
        maxSize = max(maxSize, max(size[ulp_u], size[ulp_v]));
    }

    int getComponents()
    {
        return components;
    }

    int getMaxSize()
    {
        return maxSize;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    DisjointSet ds(n);

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        ds.unionBySize(a, b);
        p2(ds.getComponents(), ds.getMaxSize());
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
