#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
using ll = long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
struct Interactor{
    int hiddenNumber=49;
    Interactor(){
        
    }
    bool query(int index){
        
    }
    string make_query(int ind){
        if(hiddenNumber%ind==0) return "yes";
        return "no";
    }
    void isValidOutput(int index){
        if(index == hiddenNumber){
            cout << "Passed";
        }else{
            cout << "Failed";
        }
        cout << endl;
    }
};
void solve(){
    vector<int>check={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,4,9,16,25,49};
    int cnt=0;
    string res;
    //Interactor interactor = Interactor();
    for(auto &it : check){
        cout<<it<<endl;
        cin>>res;
        //res=interactor.make_query(it);
        if(res == "yes") cnt++;
        if(cnt>1){
            cout<<"composite"<<endl;
            return;
        }
    }
    cout<<"prime"<<endl;
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