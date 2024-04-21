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
void yes(){cout<<"Yes"<<"\n";}
void no(){cout<<"No"<<"\n";}
pii secMin(vi &a){
    ll first=INT_MAX,second=INT_MAX;
    for(ll i=0;i<a.size();i++){
        if(first>=a[i]){
            second=first;
            first=a[i];
        }
        else if(second>a[i] && first!=second){
            second=a[i];
        }
    }
    return {first,second};
}

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

bool isPossible(ll moves,vi &a,ll x){
    pii curr;
    curr.first=a[0]-x;
    curr.second=a[0]+x;
    // (3,6)x1,y1
    ll cnt=0;
    for(ll i=1;i<a.size();i++){
        //pii temp={a[i]-x,a[i]+x};
        //(1,4)x2,y2
        curr.first=max(a[i],curr.first);
        curr.second=min(a[i],curr.second);
        if(curr.first<=curr.second) continue;
        else{
            cnt++;
            curr.first=a[i]-x;
            curr.second=a[i]+x;
        }
    }
    return cnt<=moves;
}
void solve(ll f){
    ll n,x;
    cin>>n>>x;
    vi a(n);
    getInput(a);
    //sort(all(a));
    //if(f==0) debug(a),print(x);
    ll l=a[0]-x,r=a[0]+x,cnt=0;
    for(ll i=1;i<n;i++){
        l=max(l,a[i]-x);
        r=min(r,a[i]+x);
        if(l>r){
            cnt++;
            l=a[i]-x;
            r=a[i]+x;
        }
    }
    print(cnt);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t){
        t--;
        solve(t);
    }
}