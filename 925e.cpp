#include <bits/stdc++.h>
 
using namespace std;

 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;;
  cin >> tt;;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    auto length = [&] (int p) {
      return int(log10(p) + 1);
    };
    auto pad = [&] (int p) {
      int z = 1, r = 0;
      while (p % (z *= 10) == 0) {
        ++r;
      }
      return r;
    };
    sort(a.begin(), a.end(), [&] (int i, int j) {
      return pad(i) < pad(j);
    });
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      ans += length(a[i]);
      if (i % 2 == (n - 1) % 2) {
        ans -= pad(a[i]);
      }
    }
    cout << (ans <= m ? "Anna" : "Sasha") << '\n';
  }
  return 0;
}