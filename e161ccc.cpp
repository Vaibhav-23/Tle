#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(a) (a).rbegin(), (a).rend()
#define lb lower_bound
#define ub upper_bound
using vi = vector<long long>;
using vpi = vector<pair<ll, ll>>;
using pii = pair<ll,ll>;
#define ps(x, y) fixed << setprecision(y) << x
ll INF = 1e18;
ll MOD = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}

//Operations in array
ll maxx(vi &a){return (*max_element(a.begin(), a.end()));}
ll minn(vi &a){return (*min_element(a.begin(), a.end()));}
ll gcd(ll a, ll b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
long long lcm(ll a, ll b){return (a / gcd(a, b)) * b;}
bool isPrime(ll n)
{
    if (n <= 1) return false;
    for (ll i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

void getInput(vector<ll> &arr){
    for(ll i=0;i<arr.size();i++){
        cin>>arr[i];
    }
}
//debuging part
void debug(vector<ll> &arr){
    for(auto &it : arr){
        cout<<it<<" ";
    }
    cout<<"\n";
}
void print(ll res){cout<<res<<"\n";}
void prints(string &res){cout<<res<<"\n";}

//modular arithmetic stuff here
long long mod(long long x){return ((x % MOD + MOD) % MOD);}
long long add(long long a, long long b){return mod(mod(a) + mod(b));}
long long mul(long long a, long long b){return mod(mod(a) * mod(b));}
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
ll modularInverse(ll number, ll mod){return power(number, mod - 2, mod);}
//end of modular stuff
void solve(){
    ll n;
    cin>>n;
    vi a(n);
    getInput(a);
    vi left(n+1,0),right(n+1,0);
    map<ll,ll>freq;
    freq[0] = 1;
    freq[n-1] = -1;
    for (ll i = 1; i < n - 1; i++){
        ll left = abs(a[i] - a[i - 1]);
        ll right = abs(a[i] - a[i + 1]);
        if (left < right) freq[i] = -1;
        else freq[i] = 1;
    }
    for (ll i = 1; i < n; i++){
            if (freq[i] == -1) left[i] = left[i-1]+1;
            else left[i] = left[i - 1]+abs(a[i] - a[i - 1]);
    }
    for (ll i = n - 2; i >= 0; i--){
        if (freq[i] == 1) right[i] = 1 + right[i + 1];
        else right[i] = right[i + 1] + abs(a[i] - a[i + 1]);
    }

    ll query;
    cin>>query;
    for(ll k=0;k<query;k++){
        ll x,y;
        cin>>x>>y;
        if(x==y) print(0);
        else{
            if (y>x) print(right[x - 1] - right[y - 1]);
            else print(left[x - 1] - left[y - 1]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t){
        t--;
        solve();
    }
}