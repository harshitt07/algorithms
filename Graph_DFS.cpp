#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include <queue>
#include <iterator>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;
int tim = 0; // for recording time

vector < list <int> > G;
vector <int> Par,disc,fin;
vector <char> Color;

double f = INFINITY;

void DFS_Visit(int v) {
    Color[v] = 'G';
    tim=tim+1;
    disc[v] = tim;

    for(list <int> :: iterator it = G[v].begin();it!=G[v].end();it++) {
        if(Color[*it] == 'W') {
            Par[*it] = v;
            DFS_Visit(*it);
        }
    }
    Color[v] = 'B';
    tim = tim + 1;
    fin[v] = tim;
}

void DFS(vector <list <int> > &G) {
    //cerr << G.size();
    Par.resize(G.size());
    //cerr << Par.size();
    disc.resize(G.size());
    fin.resize(G.size());
    Color.resize(G.size());

    // initialisation

    for(int i=1;i<G.size();i++) {
        Color[i] = 'W';
        Par[i] = 0;
        disc[i] = 0;
        fin[i] = 0;
    }

   //tim = 0;

    for(int i=1;i<G.size();i++) {
        if(Color[i] == 'W') DFS_Visit(i);
    }
}


int main() {
    fast
    // A 1 , B 2 , C 3 , D 4 , E 5
    int n,m;
    cin >> n; // no of vertices
    cin >> m; // no of edges
    G.resize(n+1);
    // making of undirected graph

    for(int i=0;i<m;i++) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        //G[y].push_back(x);
    }
    
    DFS(G);
    
    //cout << tim;

    for(int i=1;i<n+1;i++) cout << disc[i] << " ";
    cout << endl;

    for(int i=1;i<n+1;i++) cout << fin[i] << " ";
    cout << endl;


    return 0;
}
