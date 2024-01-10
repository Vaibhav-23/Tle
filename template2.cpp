// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp> // everything related to pbds
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef int node; // change type here
// typedef tree<node, null_type, less<node>,
//              rb_tree_tag, tree_order_statistics_node_update> // this is push_backds
//     ordered_set;
using ll = long long;
using vi = vector<long long>;
using vpi = vector<pair<ll, ll>>;
typedef long double ld;
#define all(x) (x).begin(), (x).end()
#define rall(a) (a).rbegin(), (a).rend()
#define lb lower_bound
#define ps(x, y) fixed << setprecision(y) << x
#define int long long

ll INF = 1e18;
ll MOD = 1e9 + 7;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0}; // useful when dealing with points
ll maxx(vi &a)
{
    return (*max_element(a.begin(), a.end()));
}

ll minn(vi &a)
{
    return (*min_element(a.begin(), a.end()));
}

long long gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to return LCM of two numbers
long long lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

bool isPrime(ll n)
{
    if (n <= 1)
    {
        return false;
    }
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

// mod stuff starts here
long long mod(long long x)
{
    return ((x % MOD + MOD) % MOD);
}
long long add(long long a, long long b)
{
    return mod(mod(a) + mod(b));
}
long long mul(long long a, long long b)
{
    return mod(mod(a) * mod(b));
}
// this is mod stuff

void input(vi &a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void print(vector<int> &a)
{
    for (auto x : a)
    {
        cout << x << " ";
    }
    cout << endl;
}

int stringToInt(string s)
{
    stringstream geek(s);
    int x = 0;
    geek >> x;
    return x;
}

bool isPowerOfTwo(ll n)
{
    if (n == 0)
        return false;

    return (ceil(log2(n)) == floor(log2(n)));
}

bool isPalindrome(string s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            return false;
        }
    }
    return true;
}
string binaryTransformation(long long x)
{
    if (x == 0)
        return "";
    else
    {
        string s = binaryTransformation(x / 2);
        s.push_back(char('0' + x % 2));
        return s;
    }
}
ll power(ll a, ll b, ll mod)
{
    if (b == 0)
    {
        return 1;
    }
    ll ans = power(a, b / 2, mod);
    ans *= ans;
    ans %= mod;
    if (b % 2)
    {
        ans *= a;
    }
    return ans % mod;
}
double power(double a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    double t = power(a, b / 2);
    if (b & 1)
    {
        return t * t * a;
    }
    else
    {
        return t * t;
    }
}
int modularInverse(int number, int mod)
{
    return power(number, mod - 2, mod);
}
// it should be 1LL and not 1
// write more tests
// google if stuck
// take a walk if stuck

void solve()
{
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    vector<pair<int, int>> a;
    for (auto x : mp)
    {
        a.push_back(x);
       // cout << x.first << " " << x.second << endl;
    }

    // now we need prefixes
    int ans = 0;
    // how will we maintain prefixes
    vi pre(a.size() + 1);
    pre[0] = 1;
    n = a.size();
    for (int i = 1; i <= a.size(); i++)
    {
        pre[i] = mul(pre[i - 1], a[i - 1].second);
    }
   // print(pre);
    for (int i = 0; i < a.size(); i++)
    {
        int j = i + m - 1;
        if (j < a.size() && a[j].first - a[i].first < m)
        {
            int curr = mul(pre[j + 1], modularInverse(pre[i], MOD));
            ans = add(ans, curr);
        }
    }
    cout << ans << endl;
}

// https://github.com/Manjunath0408/CPSnippets

int32_t main()
{
    // freopen("dishes.in", "r", stdin);
    // freopen("dishes.out", "w", stdout);
    /* stuff you should look for
     * int overflow, array bounds
     * special cases (n==1?)
     * do smth instead of nothing and stay organized
     * WRITE STUFF DOWN
     * DON'T GET STUCK ON ONE APPROACH
     * IF STUCK ON A QUESTION, MOVE TO THE NEXT ONE
     */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}