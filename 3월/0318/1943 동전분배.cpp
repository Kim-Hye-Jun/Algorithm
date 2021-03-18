#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

void input();
int solve();

int N,K;
vector <int> coin;
int dp[50001];
int main() {
  for(int i=0;i<3;i++)
  {
    input();
    if(K==-1)
    {
      cout << 0 << "\n";
    }
    else
    {
      cout << solve() << "\n";
    }
  }
}

void input()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  int a,b;
  int total = 0;
  coin.clear();
  for(int i=0;i<N;i++)
  {
    cin >> a >> b;
    total+=a*b;

    for(int c=1;c<=b;c*=2)
    {
      b-=c;
      coin.push_back(c*a);
    }
    if(b)
      coin.push_back(b*a);

  }

  K=total/2;
  if(total%2==1)
    K=-1;

  return;
}

int solve()
{
  memset(dp,0,sizeof(dp));

  dp[0]=1;
  for(int i=0;i<coin.size();i++)
  {
    for(int j=K;j>=coin[i];j--)
    {
      if(dp[j-coin[i]])
        dp[j]=1;
    }
  }

  if(dp[K])
    return 1;
  else
    return 0;
}