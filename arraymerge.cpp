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
ll count(vi &a){
    ll prev=a[0],res=1,curr=1;
    for(ll i=1;i<a.size();i++){
        if(a[i]==a[i-1]) curr++;
        else prev=a[i],curr=1;
        res=max(curr,res);
    }
    return res;
}
void solve(){
    ll n;
    cin>>n;
    vi a(n),b(n);
    map<ll,ll> freq,freq2;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        freq[a[i]]=0;
    }
    for(ll i=0;i<n;i++){
        cin>>b[i];
        freq2[b[i]]=0;
    }
    //getInput(b); 
    if(n==1){
        if(a[0]==b[0]) print(2);
        else print(1);
        return;
    }
    //freq[a[0]]++;
    ll temp=1;
    for(ll i=1;i<n;i++){
        if(i==n-1){
            if(a[i]==a[i-1]){
                temp++;
                freq[a[i]]=max(freq[a[i]],temp);                
            }
            else{
                freq[a[i-1]]=max(freq[a[i-1]],temp);   
                freq[a[i]]=max(freq[a[i]],1LL); 
            }
        }
        else if(a[i]==a[i-1]) temp++;
        else{
            freq[a[i-1]]=max(freq[a[i-1]],temp);
            temp=1;
        }
    }
    //freq2[b[0]]++;
    temp=1;
    for(ll i=1;i<n;i++){
        if(i==n-1){
            if(b[i]==b[i-1]){
                temp++;
                freq2[b[i]]=max(freq2[b[i]],temp);                
            }
            else{
                freq2[b[i-1]]=max(freq2[b[i-1]],temp);   
                freq2[b[i]]=max(freq2[b[i]],1LL); 
            }
        }
        else if(b[i]==b[i-1]) temp++;
        else{
            freq2[b[i-1]]=max(freq2[b[i-1]],temp);
            temp=1;
        }
    }
    for(auto &it: freq2){
        freq[it.first]+=it.second;
    }
    ll res=0;
    for(auto &it :freq){
        res=max(res,it.second);
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