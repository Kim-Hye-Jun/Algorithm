#include <iostream>
#include <algorithm>

using namespace std;

void input();
void solve();

int cut[10001];
int piece[10001];
int L,K,C,retA,retB;

int main() {
  
  input();
  solve();
  cout << retA << " " << retB;
}

void input()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  
  cin >> L >> K >> C;

  for(int i=0;i<K;i++)
  {
    cin >> cut[i];
  }
  cut[K] = L;
  sort(cut,cut+K);

  for(int i=1;i<=K;i++)
  {
    piece[i] = cut[i] - cut[i-1];
  }
  piece[0] = cut[0];

  
}

void solve()
{
  int left=0,right=1000000000,mid,i;
  int cur=0,cutN=0,cutLast;
  while(left<=right)
  {
    mid = (left + right) / 2;

    for(cutLast=cur=cutN=0,i=K;i>=0;i--)
    {
      if(piece[i]>mid)
      {
        cutN = C+1;
        break;
      }
      
      if(piece[i]+cur > mid)
      {
        cur = 0;
        cutLast = i;
        cutN++;
      }
      cur += piece[i];
    }

    if(cutN>C)
    {
      left = mid + 1;
    }
    else
    {
      retA = mid;
      right = mid - 1;
      if(cutN==C)
        retB = cut[cutLast];
      else
        retB = cut[0];
    }
  }
}