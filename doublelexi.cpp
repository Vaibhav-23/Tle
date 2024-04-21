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
void debug2d(vector<vector<ll>>& a){
    for(ll i=0;i<a.size();i++){
        for(ll j=0;j<a[0].size();j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
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
//xor from 1 to n
int xortilln(int n){ 
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

//popfront
template<typename T>
void pop_front(std::vector<T>& vec){
    assert(!vec.empty());
    vec.front() = std::move(vec.back());
    vec.pop_back();
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
void solve(){
    string s;cin>>s;
    ll n=s.size();
    vector<ll> cnt(26,0);
    for(auto it : s){
        cnt[it-'a']++;
    }
    //debug(cnt);
    ll l=0,r=n-1;
    string res(n,'?');
    for(ll i=0;i<26;i++){
        while(cnt[i]>=2){
            cnt[i]-=2;
            res[l++] = res[r--] = 'a'+i;
        }
        if(cnt[i]==1){
            cnt[i]-=1;
            if(l==r){
                res[l]='a'+i;
            }
            else{
                ll x=i+1;
                while(cnt[x]==0){
                    x++;
                }
                if(cnt[x]==r-l){
                    ll temp=ceil_div(r-l,2);
                    while(temp){
                        res[l++]='a'+x;
                        temp--;
                    }
                    res[l++]='a'+i;
                    temp=cnt[x]/2;
                    while(temp){
                        res[l++]='a'+x;
                        temp--;
                    }
                }
                else{
                    for(;x<26;x++){
                        while(cnt[x]>0){
                            cnt[x]-=1;
                            res[l++]='a'+x;
                        }
                    }
                    res[r]='a'+i;
                }
            }
            break;
        }
    }
    prints(res);
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