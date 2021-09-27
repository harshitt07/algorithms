#include <iostream>
#include <vector>
#define lli long long int
#define fo(i, a, b) for (i = a; i < b; i++)
#define Fo(i, a, b) for (i = a; i > b - 1; i--)
using namespace std;

const int mod = 1000000007;
const int maxN = 100005;

void precomputeAncestorAndDepth(lli src, lli parent, lli currentDepth, vector<vector<lli>> &ancestor, vector<lli> &depth, vector<lli> Adj[]) {

    depth[src] = currentDepth;
    ancestor[src][0] = parent;
    lli i = 2, j = 1;
    while(i < currentDepth) {
        ancestor[src][j] = ancestor[ancestor[src][j - 1]][j - 1];
        j++;
        i <<= 1;
    }
    for(auto &child : Adj[src]) {
        if(child != parent) {
            precomputeAncestorAndDepth(child, src, currentDepth + 1, ancestor, depth, Adj);
        }
    }
}

lli binaryLifting(lli diff, lli src, vector<vector<lli>> &ancestor) {
    if(diff == 0) return src;
    lli mask = (1 << 20);
    int currentSetBit = 20;
    while(mask) {
        if(diff&mask) {
            src = ancestor[src][currentSetBit];
        }
        mask >>= 1;
        currentSetBit--;
    }
    return src;
}

void solve() {

    lli i, N, Q; cin >> N >> Q;
    pair<lli, lli> Edges[N - 1];
    fo(i, 0, N - 1) {
        cin >> Edges[i].first >> Edges[i].second;
    }
    pair<lli, lli> Queries[Q];
    fo(i, 0, Q) cin >> Queries[i].first >> Queries[i].second;

    vector<lli> Adj[N + 1];
    Adj[1].push_back(0);
    fo(i, 0, N - 1) {
        lli u = Edges[i].first;
        lli v = Edges[i].second;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    vector<vector<lli>> ancestor(N + 1, vector<lli> (18));
    vector<lli> depth(N + 1);
    precomputeAncestorAndDepth(1, 0, 1, ancestor, depth, Adj);

    fo(i, 0, Q) {

        lli u = Queries[i].first;
        lli v = Queries[i].second;
        int L = u, R = v;
        lli diff = abs(depth[u] - depth[v]);

        if(depth[u] > depth[v]) {
            u = binaryLifting(diff, u, ancestor);
        } else {
            v = binaryLifting(diff, v, ancestor);
        }

        while(u != v) {
            lli j = 0, k = 1;
            while((1 << k) < depth[u] && ancestor[u][j + 1] != ancestor[v][j + 1]) {
                j++;
                k <<= 1;
            }
            u = ancestor[u][j];
            v = ancestor[v][j];
        }

        cout << depth[L] + depth[R] - 2*depth[u] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
