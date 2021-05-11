#include <iostream>
#include <queue>

using namespace std;

void input();
int solve();
bool check(int x,int y);

int N,M;
int x,y;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

char arr[50][50];
bool visit[1<<6][50][50];

int main() {
  input();
  cout << solve();
}

void input()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<M;j++)
    {
      cin >> arr[i][j];
      if(arr[i][j]=='0')
      {
        x=i;
        y=j;
        arr[i][j]='.';
      }
    }
  }

}

int solve()
{
  int ret=0;
  int key=0;
  queue <pair<pair<int,int>,int>> q;
  q.push({{x,y},key});
  visit[key][x][y]=true;
  while(!q.empty())
  {
    int size=q.size();
    
    ret++;
    while(size--)
    {
      x = q.front().first.first;
      y = q.front().first.second;
      key = q.front().second;
      
      q.pop();

      
      for(int i=0;i<4;i++)
      {
        int nx=x+dx[i];
        int ny=y+dy[i];
        int nkey=key;
        if(check(nx,ny))
        {
          
          if(visit[nkey][nx][ny]==true)
            continue;

          // cout << arr[nx][ny] << " ";
          // cout << nkey << " " << nx << " " << ny << " " << ret << endl;

          if(arr[nx][ny]=='.')
          {
            q.push({{nx,ny},nkey});
            visit[nkey][nx][ny]=true;
          }
          else if(arr[nx][ny]>='a'&&arr[nx][ny]<='f')
          {
            int n = arr[nx][ny]-'a';
            nkey|=(1<<n);
            q.push({{nx,ny},nkey});
            visit[nkey][nx][ny]=true;
            // 줍기
          }
          else if(arr[nx][ny]>='A'&&arr[nx][ny]<='F')
          {
            int n = arr[nx][ny]-'A';
            if(nkey&(1<<n))
            {
              q.push({{nx,ny},nkey});
              visit[nkey][nx][ny]=true;
            }  
            else
              continue;
            // 열쇠가 있으면 들어가고 없으면 continue
          }
          else if(arr[nx][ny]=='#')
            continue;
          else
            return ret;
        }
        
      }  
    }
    
  }
  return -1;
}

bool check(int x,int y)
{
  if(x>=0&&x<N&&y>=0&&y<M)
    return true;
  return false;
}