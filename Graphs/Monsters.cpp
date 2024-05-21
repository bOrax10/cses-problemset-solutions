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

int drow[] = {-1, 0, 1, 0};
int dcol[] = {0, 1, 0, -1};
char dir[] = {'U', 'R', 'D', 'L'};

void multibfs(vector<pii> &monsters, vector<vector<char>> &grid, vector<vector<int>> &timeM)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pii> q;
    for (auto it : monsters)
    {
        q.push(it);
        timeM[it.ff][it.ss] = 0;
    }

    while (!q.empty())
    {
        int row = q.front().ff;
        int col = q.front().ss;
        q.pop();

        rep(i, 0, 4)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] != '#')
            {
                if (timeM[row][col] + 1 < timeM[nrow][ncol])
                {
                    timeM[nrow][ncol] = timeM[row][col] + 1;
                    q.push(mp(nrow, ncol));
                }
            }
        }
    }
}

void bfs(pii a, vector<vector<char>> &grid, vector<vector<int>> &timeA)
{
    int n = grid.size();
    int m = grid[0].size();

    queue<pii> q;
    debug(a);
    q.push(a);
    timeA[a.ff][a.ss] = 0;

    while (!q.empty())
    {
        debug(q.front());
        int row = q.front().ff;
        int col = q.front().ss;
        q.pop();

        rep(i, 0, 4)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] != '#')
            {
                if (timeA[row][col] + 1 < timeA[nrow][ncol])
                {
                    timeA[nrow][ncol] = timeA[row][col] + 1;
                    q.push(mp(nrow, ncol));
                }
            }
        }
    }
}

void pathBfs(int n, int m, pii start, pii end, vector<vector<char>> &grid, vector<vector<char>> &vis)
{
    queue<pii> q;
    vis[start.ff][start.ss] = 'x';
    q.push(start);
    grid[end.ff][end.ss] = '.';

    while (!q.empty())
    {
        int row = q.front().ff;
        int col = q.front().ss;
        // debug(q.front());
        q.pop();
        if (row == end.ff && col == end.ss)
        {
            // print("YES");
            return;
        }
        rep(i, 0, 4)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 'x' && grid[nrow][ncol] == '.')
            {
                vis[nrow][ncol] = dir[i];
                // debug(vis[nrow][ncol]);
                q.push({nrow, ncol});
            }
        }
    }
}

void backtrack(pii start, pii node, string &s, vector<vector<char>> &grid, vector<vector<char>> &vis)
{
    if (node == start)
    {
        return;
    }
    s += vis[node.ff][node.ss];
    int ind = -1;
    rep(i, 0, 4)
    {
        if (vis[node.ff][node.ss] == dir[i])
        {
            ind = i;
        }
    }
    pii parent = mp(node.ff - drow[ind], node.ss - dcol[ind]);
    backtrack(start, parent, s, grid, vis);
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<char>> path(n, vector<char>(m, 'x'));
    vector<vector<int>> timeM(n, vector<int>(m, 1e9));
    vector<vector<int>> timeA(n, vector<int>(m, 1e9));
    pii a;
    vector<pii> monsters;
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
                a = mp(i, j);
            else if (grid[i][j] == 'M')
            {
                monsters.push_back(mp(i, j));
            }
        }
    }

    set<pii> exits;
    rep(i, 0, n)
    {
        if (grid[i][0] == '.')
            exits.insert(mp(i, 0));
        if (grid[i][m - 1] == '.')
            exits.insert(mp(i, m - 1));
        if (grid[i][0] == 'A' || grid[i][m - 1] == 'A')
        {
            print("YES");
            print(0);
            return;
        }
    }
    rep(j, 0, m)
    {
        if (grid[0][j] == '.')
            exits.insert(mp(0, j));
        if (grid[n - 1][j] == '.')
            exits.insert(mp(n - 1, j));
        if (grid[0][j] == 'A' || grid[n - 1][j] == 'A')
        {
            print("YES");
            print(0);
            return;
        }
    }
    if (exits.size() == 0)
    {
        print("NO");
        return;
    }
    multibfs(monsters, grid, timeM);
    bfs(a, grid, timeA);

    bool flag = 0;
    pii ans;
    for (auto it : exits)
    {

        if (timeA[it.ff][it.ss] < timeM[it.ff][it.ss])
        {
            flag = 1;
            ans = it;
            break;
        }
    }

    if (!flag)
    {
        print("NO");
        return;
    }
    else
    {
        print("YES");
        print(timeA[ans.ff][ans.ss]);
        string s = "";
        pathBfs(n, m, a, ans, grid, path);
        backtrack(a, ans, s, grid, path);
        reverse(all(s));
        print(s);
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
