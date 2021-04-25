#include <iostream>

using namespace std;
int N,M;

void input();
void solve();
int Otime[10001];

int main() {
  
  input();
  if(N<=M)
    cout << N;
  else
    solve();
}

void input()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  
  for(int i=0;i<M;i++)
    cin >> Otime[i];
  
}

void solve()
{
  long long left=0;
  long long right=60000000000;
  
  long long mid,share,X,x,sumS,ret;
  mid = (left+right)/2;

  while(left<=right)
  {
    mid = (left+right)/2;
    sumS=M;
    for(int i=0;i<M;i++)
    {
      share = mid/Otime[i];
      sumS += share;
    }
    
    if(sumS>=N)
    {
      right = mid-1;
      ret = mid;
    }
    if(sumS<N)
      left = mid+1;
  }
  //sumS와 mid 저장 (mid 에는 ret값 sumS 에는 N..?))
  // cout << ret;
  X = M;
  for(int i=0;i<M;i++)
  {
    share = (ret-1)/Otime[i];
    X += share;
  }
  
  int j=0;
  for(int i=0;i<M;i++)
  {
    if(!(ret%Otime[i]))
    {
      j++;
      if(j==N-X)
      {
        x=i+1;
        break;
      }
    }
  }
  
  cout << x;
}