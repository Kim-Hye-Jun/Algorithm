#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

void input();
void solve();

int N,M;
int teamRank[500];
bool order[501][501];
int indegree[501];

int main() {
  int T;
  cin >> T;
  for(int i=0;i<T;i++)
  {
    input();
    solve();
  }
}

void input()
{
  memset(indegree,0,sizeof(indegree));
  memset(order,false,sizeof(order));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for(int i=0;i<N;i++)
  {
    cin >> teamRank[i];
  }

  for(int i=0;i<N;i++)
  {
    for(int j=i+1;j<N;j++)
    {
      order[teamRank[i]][teamRank[j]]=true;
      indegree[teamRank[j]]++;
      // teamRank[i] 팀 뒤에 teamRank[j] 팀이 있다.
    }
  }

  cin >> M;
  int a,b;
  for(int i=0;i<M;i++)
  {
    cin >>  a >> b;
    if(order[a][b])
    {
      order[a][b]=false;
      order[b][a]=true;
      indegree[a]++;
      indegree[b]--;
    }
    else
    {
      order[a][b]=true;
      order[b][a]=false;
      indegree[b]++;
      indegree[a]--;
    }
  }

}

void solve()
{
  vector<int> ret;
  queue<int> q;
  for(int i=1;i<=N;i++)
  {
    if(indegree[i]==0)
      q.push(i);
  }

  bool certain=true;

  while(!q.empty())
  {
    if(q.size()>1)
    {
      certain=false;
      break;
    }

    int cur = q.front();
    ret.push_back(cur);
    

    q.pop();
    for(int i=1;i<=N;i++)
    {
      if(order[cur][i])
      {
        indegree[i]--;
        if(indegree[i]==0)
          q.push(i);
      }
    }
  }

  if(!certain)
    cout << "?";
  else if(ret.size()==N)
  {
    for(int i=0;i<ret.size();i++)
      cout << ret[i] << " ";
  }
  else
    cout << "IMPOSSIBLE";
  cout << "\n";
}