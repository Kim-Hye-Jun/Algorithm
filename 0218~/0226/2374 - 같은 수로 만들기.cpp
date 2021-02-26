#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;
void solve();

int N;
int A[1001];

int main() {
  solve();
}

void solve()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  vector<int> V;
  long long ret=0;

  for(int i=1;i<=N;i++)
  {
    cin >> A[i];
    if(V.empty())
      V.push_back(A[i]);
    else
    {
      if(V.back()>A[i])
        V.push_back(A[i]);
      else
      {

        while(V.back()<A[i])
        {        
          int bot = V.back();
          V.pop_back();

          if(V.back()>A[i] || V.empty())
          {
            ret+=A[i]-bot;
            V.push_back(A[i]);
          }
          else
          {
            ret+=V.back()-bot;
          }
        }
      }
    }
  }

  if(!V.empty())
    ret+=V.front()-V.back();
  
  cout << ret;
}