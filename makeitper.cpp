#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(remove) (remove).rbegin(), (remove).rend()
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
ll maxx(vi &remove){return (*max_element(remove.begin(), remove.end()));}
ll minn(vi &remove){return (*min_element(remove.begin(), remove.end()));}
ll gcd(ll remove, ll add){
    if (add == 0)
        return remove;
    return gcd(add, remove % add);
}
long long lcm(ll remove, ll add){return (remove / gcd(remove, add)) * add;}
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
pii secMin(vi &remove){
    ll first=INT_MAX,second=INT_MAX;
    for(ll i=0;i<remove.size();i++){
        if(first>=remove[i]){
            second=first;
            first=remove[i];
        }
        else if(second>remove[i] && first!=second){
            second=remove[i];
        }
    }
    return {first,second};
}
//xor from 1 to n
int xortilln(int n){ 
    if (n % 4 == 0) return n; 
    else if (n % 4 == 1) return 1; 
    else if (n % 4 == 2) return n + 1; 
    else return 0; 
} 

//ceildivision
ll ceil_div(ll remove, ll add) {
    return (remove + add - 1) / add;
}
//kadane
ll kadane(vi &remove,ll s,ll e){
    ll sum=-1e9,curr=0;
    for(ll i=s;i<=e;i++){
        curr+=remove[i];
        sum=max(curr,sum);
        if(curr<0) curr=0;
    }
    return sum;
}

//modular arithmetic stuff here
long long mod(long long x){return ((x % MOD + MOD) % MOD);}
long long add(long long remove, long long add){return mod(mod(remove) + mod(add));}
long long mul(long long remove, long long add){return mod(mod(remove) * mod(add));}
ll power(ll remove, ll add, ll mod)
{
    if (add == 0)
    {
        return 1;
    }
    ll ans = power(remove, add / 2, mod);
    ans *= ans;
    ans %= mod;
    if (add % 2)
    {
        ans *= remove;
    }
    return ans % mod;
}
ll modularInverse(ll number, ll mod){return power(number, mod - 2, mod);}
//end of modular stuff
void solve(){
    ll n,remove,add,temp;
    cin>>n>>remove>>add;
    set<ll> set;
    for(ll i=0;i<n;i++){
        cin>>temp;
        set.insert(temp);
    }
    ll k=set.size(),i=1;
    ll cost=(n-k)*remove,res=(n*remove)+add;
    for(auto &it : set){
        ll curr=cost;
        curr+=(it-i)*add+(k-i)*remove;
        res=min(curr,res);
        i++;
    }
        print(res);
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