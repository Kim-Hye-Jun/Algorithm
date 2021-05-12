#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void input();
void solve();
bool check(int);

int weight[30];
int marble[7];
int N,M,total,low;
int dp[15001];

int main() {
  input();
  solve();
}

void input()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> N;
  for(int i=0;i<N;i++)
  {
    cin >> weight[i];
    total+=weight[i];
  }
  cin >> M;
  for(int i=0;i<M;i++)
  {
    cin >> marble[i];
  }

}

void solve()
{
  vector<int> V;
  memset(dp,0,sizeof(dp));
  dp[total]=1;
  low=total;
  for(int i=0;i<N;i++)
  {
    V.clear();
    int low2;
    for(int j=total;j>=low;j--)
    {
      if(dp[j]==1)
      {
        if(check(j-weight[i]))
        {
          if(dp[j-weight[i]]==0)
          {
            // dp[j-weight[i]]=1;
            // cout << j-weight[i] << endl;
            V.push_back(j-weight[i]);
            low2=min(low,j-weight[i]);
          }
          if(check(j-2*weight[i]))
          {
            if(dp[j-2*weight[i]]==0)
            {
              // dp[j-2*weight[i]]=1;
              // cout << j-2*weight[i] << endl;
              V.push_back(j-2*weight[i]);
              low2=min(low,j-2*weight[i]);
            }
            
          }
        }
      }
      
    }
    // low , dp 값변경
    low=low2;
    for(int k=0;k<V.size();k++)
    {
      dp[V[k]]=1;
      // cout << k;
    }
  }

  for(int i=0;i<M;i++)
  {
    if(marble[i]>total)
      cout << "N" << " ";
    else
    {
      if(dp[marble[i]]==1)
        cout << "Y" << " ";
      else
        cout << "N" << " ";
    }
    
  }
}

bool check(int t)
{
  if(t>=0)
    return true;
  else
    return false;
}