#include <iostream>
#include <vector>
#include <queue>

#define INT_MAX 987654321

using namespace std;

int N,M,K;

typedef struct Data{
  int to;
  int cost;
  int time;
}Data;

struct comp{
  bool operator()(const Data &a, const Data &b)const{
    return a.time > b.time;
  }
};

vector<vector<Data>> adj;
int dist[101][10001];
// time , cost
void init();
void dijkstra();


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  
  for(int i=0;i<T;i++)
  {
    cin >> N >> M >> K;
    int u,v,c,d;
    adj.clear();
    adj.resize(N+1);
    init();
    for(int j=0;j<K;j++)
    {
      Data data;
      cin >> u >> data.to >> data.cost >> data.time;
      adj[u].push_back(data);
    }
    dijkstra();
    
  }
}

void dijkstra()
{
  int ret = INT_MAX;
  priority_queue<Data, vector<Data>,comp> pq;

  dist[1][0]=0;
  Data start;
  start.to = 1;
  start.cost = 0;
  start.time = 0;
  pq.push(start);

  while(!pq.empty())
  {
    Data cur = pq.top();
    pq.pop();

    if(dist[cur.to][cur.cost] < start.time) continue;

    for(Data item : adj[cur.to])
    {
      Data next;
      next.to = item.to;
      next.time = dist[cur.to][cur.cost]+item.time;
      next.cost = cur.cost + item.cost;

      if(next.cost > M) continue;
      if(dist[next.to][next.cost] > next.time)
      {
        
        for(int l=next.cost+1;l<=M;l++)
        {
            if(dist[next.to][l]<=next.time) break;
            dist[next.to][l]=next.time;
        }
         
        dist[next.to][next.cost] = next.time;
        pq.push(next);
      }
    }
  }

  for(int i=0;i<=M;i++)
  {
    ret = min(ret,dist[N][i]);
    // cout << ret << endl;
  }
    
  if(ret!=INT_MAX)
    cout << ret << "\n";
  else
    cout << "Poor KCM\n";
}


void init()
{
  for(int t=0;t<=N;t++)
  {
    for(int p=0;p<=M;p++)
    {
      dist[t][p]=INT_MAX;
    }
  }
}