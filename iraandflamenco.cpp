#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(a) (a).rbegin(), (a).rend()
#define lb lower_bound
#define ub upper_bound
ll MOD = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}

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
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    map<ll,ll> freq;
    set<ll> set;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        set.insert(a[i]);
        freq[a[i]]++;
    }
    vector<ll>distinct(set.begin(),set.end());
    //debug(distinct);

    ll i=0,j=0,res=0,prod=1;
    while(j<distinct.size()){
        //prod=(prod*1LL*freq[distinct[j]])%MOD;
        prod=mul(prod,freq[distinct[j]]);
        while (i <= j && distinct[j] - distinct[i] >= k)
        {
            prod = mul(prod, modularInverse(freq[distinct[i]], MOD));
            i++;
        }
        if(j-i+1==k) res=add(res,prod);
        j++;
    }
    print(res);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t){
        t--;
        solve();
    }
}