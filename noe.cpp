#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
using ll = long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
void solve(){
    long long n,m;
    cin>>n>>m;
    vector<long long> a(n),b(m);
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    for(long long i=0;i<m;i++){
        cin>>b[i];
    }
    long long i=0,cnt=0;
    long long j=0;
    while(i<n && j<m){
        if(a[i]>b[j]) j++;
        else if(b[j]>a[i]) i++;
        else if(a[i]==b[j]){
            long long temp1=1,temp2=1;
            while(i<n-1 && a[i]==a[i+1]){
                temp1++;
                i++;
            }
            while(j<m-1 && b[j]==b[j+1]){
                temp2++;
                j++;
            }
            i++,j++;
            cnt+=(temp1*temp2);
        }
    }
    cout<<cnt<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t=1;
    //cin>>t;
    while(t){
        t--;
        solve();
    }
}