#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
int N, M, W;

int dis[501];
int counter = 0;

struct EDGE {
  int to; 
  int from;
  int w;
};

vector <EDGE> edges[3000];

bool bellman(int source) {
    bool nCycle = false;
    memset(dis, 0x7f, sizeof(dis));
    dis[source] = 0; 
    for (int i = 1; i <= N; i++) {
        nCycle=false;
        for (int j = 0; j < counter; j++) {
            EDGE edge = edges[j][0];
            int v = edge.to, w = edge.w, u = edge.from;
            if (u == 0x7f) continue;
            //cout<<to_string(u) + " " + to_string(v)<<endl;
            if (dis[v] > dis[u] + w) { 
                dis[v] = dis[u] + w;
                nCycle=true;
            }
            //cout<<dis[v]<<endl;
        }
        //cout<<"check"<<endl;
        if(!nCycle) break;
        //cout<<"check"<<endl;
    }
    //cout<<"check"<<endl;
    return nCycle;
}

int main() {
  int F;
  cin>>F;
  for (int i = 0; i < F; i++) {
    cin>>N>>M>>W;

    for (int j = 0; j < M; j++) {
      int S, E, T;
      (void) scanf("%d%d%d",&S,&E,&T);
      edges[counter].push_back({S, E, T}); counter++;
      edges[counter].push_back({E, S, T}); counter++;
    }
    for (int j = 0; j < W; j++) {
      int S, E, T;
      (void) scanf("%d%d%d",&S,&E,&T);
      edges[counter].push_back({S, E, 0 - T}); counter++;
    }

    if (bellman(1)) {
      cout<<"YES"<<endl;
    } else {
      cout<<"NO"<<endl;
    }
  }
}
