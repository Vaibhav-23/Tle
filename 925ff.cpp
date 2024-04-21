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
void yes(){cout<<"YES"<<"\n";}
void no(){cout<<"NO"<<"\n";}
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
//xor from 1 to n
ll xortilln(ll n){ 
    if (n % 4 == 0) return n; 
    else if (n % 4 == 1) return 1; 
    else if (n % 4 == 2) return n + 1; 
    else return 0; 
} 

//ceildivision
ll ceil_div(ll a, ll b) {
    return (a + b - 1) / b;
}
//kadane
ll kadane(vi &a,ll s,ll e){
    ll sum=-1e9,curr=0;
    for(ll i=s;i<=e;i++){
        curr+=a[i];
        sum=max(curr,sum);
        if(curr<0) curr=0;
    }
    return sum;
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
vector<ll> lis[200001];
ll visited[200001];
ll dfsvisited[200001];
 
bool isPossible(ll node)
{
    visited[node]=1;
    dfsvisited[node]=1;
    for (auto &it : lis[node]){
        if (!visited[it]){
            if (isPossible(it)) return true;
        }
        else if (dfsvisited[it]){
            return true;
        }
    }
    dfsvisited[node]=0;
    return false;
}
void solve(){
    ll n,k;
    cin>>n>>k;
        ll f=0;
        while(f<=n){
            lis[f].clear();
            visited[f] = 0;
            dfsvisited[f] = 0;
            f++;
        }
        ll i=0;
        while(i<k){
            vector<ll> arr(n);
            getInput(arr);
            for (ll j = 2; j < n; j++){
                lis[arr[j-1]].push_back(arr[j]);
            }
            i++;
        }
        bool flag = false;
        ll t=1;
        while(t<=n){
            if(!visited[t]){
                if(isPossible(t)){
                    flag = true;
                    break;
                }
            }
            t++;
        }
        if(flag) no();
        else yes();
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