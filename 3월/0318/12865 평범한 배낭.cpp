#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void input();
void solve();

int N,K;
vector <pair<int,int>> R;
int value[100001][101];

int main() {
  input();
  solve();
  int ret=0;
  for(int i=0;i<=N;i++)
    ret = max(ret,value[K][i]);

  cout << ret; 
}

void input()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;

  R.resize(N+1);
  int a,b;
  for(int i=1;i<=N;i++)
  {
    cin >> a >> b;
    R[i] ={a,b};
  }

  memset(value,0,sizeof(value));
}

void solve()
{
  for(int i=1;i<=N;i++)
  {
    for(int j=0;j<=K;j++)
    {
      value[j][i] = value[j][i-1];
      if(j>=R[i].first)
        value[j][i] = max(value[j-R[i].first][i-1]+R[i].second,value[j][i]);

    }
  }
}