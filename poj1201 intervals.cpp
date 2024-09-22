#include <iostream>
#include <string.h>
#include <cstdio>
#include <queue>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 50005;
struct node
{
  int v, w, next;
}edge[maxn*3];
queue<int> q;
int n, no, MIN, MAX;
int head[maxn], dis[maxn], vis[maxn];
inline void init()
{
  no = 0;
  memset(vis, 0, sizeof vis);
  memset(head, -1, sizeof head);
  memset(dis, 0x3f, sizeof dis);
}
inline void add(int u, int v, int w)
{
  edge[no].v = v; edge[no].w = w;
  edge[no].next = head[u]; head[u] = no++;
}
void SPFA(int s, int t)
{
  while(!q.empty()) q.pop();
  q.push(s); dis[s] = 0; vis[s] = 1;
  while(!q.empty())
  {
    int tp = q.front(); q.pop();
    vis[tp] = 0;
    int k = head[tp];
    while(k != -1)
    {
      if(dis[edge[k].v] > dis[tp] + edge[k].w)
      {
        dis[edge[k].v] = dis[tp] + edge[k].w;
        if(!vis[edge[k].v])
        {
          vis[edge[k].v] = 1;
          q.push(edge[k].v);
        }
      }
      k = edge[k].next;
    }
  }
}
int main()
{
  int a, b, c;
  scanf("%d", &n); init();
  MIN = inf, MAX = -inf;
  for(int i = 1; i <= n; ++i)
  {
    scanf("%d %d %d", &a, &b, &c);
    add(b+1, a, -c);
    MIN = min(MIN, a);
    MAX = max(MAX, b+1);
  }
  for(int i = MIN; i < MAX; ++i)
  {
    add(i, i+1, 1); add(i+1, i, 0);
  }
  SPFA(MAX, MIN);
  printf("%d\n", -dis[MIN]);
  return 0;
}
