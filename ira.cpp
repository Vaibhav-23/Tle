#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
using ll = long long;
ll mod=1e9+7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
void debug(vector<ll> &arr){
    for(auto &it : arr){
        cout<<it<<" ";
    }
    cout<<"\n";
}
void getInput(vector<ll> &arr){
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
}
void printr(ll res){cout<<res<<"\n";}
void prints(string &res){cout<<res<<"\n";}
void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n),h(n);
    getInput(a);
    getInput(h);
    ll i=0,j=0,sum=0,res=0;
    while(j<n){
        if(j==0 || h[j-1]%h[j]==0) sum+=a[j];
        else sum=a[j],i=j;
        //cout<<sum<<" ";
        while(i<=j && sum>k){
            sum-=a[i];
            i++;
        }
        if(sum<=k) res=max(res,j-i+1);
        j++;
    }
    printr(res);
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