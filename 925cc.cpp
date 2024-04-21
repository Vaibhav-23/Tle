#include<bits/stdc++.h>
void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    rep(n) cin >> arr[i];
    ll i = 0;
    while(arr[i] == arr[i+1] and i<n) i++;
    ll j = n-1;
    while(arr[j] == arr[j-1] and j>=0) j--;
    if(j == n-1 or i == 0) {
        if(arr[i] == arr[j]) cout << max((j-i-1),0LL) << endl;
        else cout << max((j-i),0LL) << endl;
    }
    else if(i != n-1 or j != 0 or i < j or i != j-1){
        if(arr[i] == arr[j]) cout << max((j-i-1),0LL) << endl;
        else {
            cout << max(min(n-1-i,j),0LL) << endl;
        }
    }
    else cout << "0\n";
}

int main(){
    solve();
}