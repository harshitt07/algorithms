#include "bits/stdc++.h"
#define lli long long int
#define fo(i, a, b) for (i = a; i < b; i++)
#define Fo(i, a, b) for (i = a; i > b - 1; i--)
using namespace std;

const int mod = 1000000007;
const int maxN = 100005;

vector<vector<int>> preCompute(int arr[], int N) {
    vector<vector<int>> Ans(N, vector<int> (log2(N) + 1, INT_MAX));
    for(int i = N - 1; i >= 0; i--) {
        Ans[i][0] = arr[i];
        for(int j = 1; j <= log2(N); j++) {
            if(i + (1 << (j - 1)) >= N) break;
            Ans[i][j] = min(Ans[i][j - 1], Ans[i + (1 << (j - 1))][j - 1]);
        } 
    }
    return Ans;
}

void solve() {

    int i, N; cin >> N;
    int arr[N]; fo(i, 0, N) cin >> arr[i];
    int Q; cin >> Q;
    pair<int, int> Queries[Q]; fo(i, 0, Q) cin >> Queries[i].first >> Queries[i].second;
    vector<vector<int>> MIN = preCompute(arr, N);
    int LOG[N];
    fo(i, 0, N) LOG[i] = log2(i);
    fo(i, 0, Q) {
        int L = Queries[i].first;
        int R = Queries[i].second;
        int length = R - L + 1;
        int logValue = LOG[length];
        cout << min(MIN[L][logValue], MIN[R - (1 << logValue) + 1][logValue]) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;// cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}