#include <iostream>
#include <stdio.h>
#include <string.h>
#define INF 1000000000
using namespace std;

void input();
bool check(int,int);
void toggle(int x,int y);
void solve();
int func(int);

int N,M;
int arr[15][15];
int temp[15][15];
int tog[15][15];
int ans[15][15];

int dx[5]={-1,1,0,0,0};
int dy[5]={0,0,-1,1,0};

int main(){
  input();
  solve();
}

void input(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> M >> N;

  for(int i=0;i<M;i++)
  {
    for(int j=0;j<N;j++)
    {
      cin >> arr[i][j];
    }
  }
}

bool check(int x,int y)
{
  if(x>=0&&y>=0&&x<M&&y<N)
    return true;
  return false;
}

void toggle(int x,int y)
{
  for(int i=0;i<5;i++){
    if(check(x+dx[i],y+dy[i]))
      temp[x+dx[i]][y+dy[i]]^=1;
  }
}

void solve()
{
  int ret = INF;
  for(int i=0;i<(1<<N);i++)
  {
    int t=func(i);
    if(t<ret)
    {
      ret=t;
      memcpy(ans,tog,sizeof(tog));
    }
  }

  if(ret==INF)
    cout << "IMPOSSIBLE";
  else{
    for(int i=0;i<M;i++)
    {
      for(int j=0;j<N;j++)
        cout << ans[i][j] << " ";
      cout << '\n';
    }
  }
}

int func(int topState)
{
  int ret=0;
  memcpy(temp,arr,sizeof(arr));
  memset(tog,0,sizeof(tog));
  
  for(int i=0;i<N;i++)
  {
    if(topState & (1<<i)){
      ret++;
      tog[0][N-1-i]=1;
      toggle(0,N-1-i);
    }
  }

  for(int i=1;i<M;i++)
  {
    for(int j=0;j<N;j++)
    {
      if(temp[i-1][j])
      {
        ret++;
        tog[i][j]=1;
        toggle(i,j);
      }
    }
  }

  for(int i=0;i<M;i++)
  {
    for(int j=0;j<N;j++)
    {
      if(temp[i][j])
        return INF;
    }
  }

  return ret;

}