#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int days = 0;
    int marked = 0;
    while (marked < K) {
        ++days;
        for (int i = 0; i < N; ++i) {
            if (days % (a[i] * 2) <= a[i] && marked < K) {
                ++marked;
            }
        }
    }

    cout << "Number of days needed: " << days << endl;

    return 0;
}
