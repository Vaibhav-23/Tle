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
using pii = pair<int,int>;
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
bool isPossible(ll steps,vector<pii>&loc,pii st,pii fi,ll n){
    pii free={(steps/n)*loc[n-1].first+st.first,(steps/n)*loc[n-1].second+st.second};
    if(steps%n){
        free.first+=loc[steps%n-1].first;
        free.second+=loc[steps%n-1].second;
    }
    ll dist = abs(free.first-fi.first)+abs(free.second-fi.second);
    return dist<=steps;
}
void solve(){
   pii st,fi;
   cin>>st.first>>st.second;
   cin>>fi.first>>fi.second;
   string str;
   ll n;
   cin>>n>>str;
   vector<pii> loc(n);
   pii curr={0,0};
    for(ll i=0;i<n;i++){
        if(str[i]=='U') curr.second++;
        else if(str[i]=='D') curr.second--;
        else if(str[i]=='L') curr.first--;
        else curr.first++;
        loc[i]={curr.first,curr.second};
    }

   ll low=0,high=2*1e14,res=-1;
    while(low<=high){
        ll mid=(low+high)/2;
        if(isPossible(mid,loc,st,fi,n)){
            res=mid;
            high=mid-1;
        }
        else low=mid+1;
    }

    print(res);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t){
        t--;
        solve();
    }
}