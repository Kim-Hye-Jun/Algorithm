#include <iostream>
#include <cstring>

using namespace std;

void input();
void solve();
int check(int);

int col,row,N,M,low;
int arr[1000001];

int main() {
  input();
  solve();
}

void input()
{
  memset(arr,0,sizeof(arr));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> row >> col;
  cin >> N; // N장 색종이 사용
  cin >> M; // M개의 잘못칠해진 칸
  int a,b;
  for(int i=0;i<M;i++)
  {
    cin >> a >> b;
    arr[b]=max(arr[b],a);
    low=max(low,a);
  }
  /*
  밑변에 붙여서 색종이를 붙여야 하기 때문에 답의 최솟값 = 가장 높이있는 점의 높이
  */
}

void solve()
{
  
  // low<= X <= row
  int X;
  int left=low;
  int right=row;
  int mid;

  while(left<=right)
  {
    mid=(left+right)/2;
    if(check(mid))
    {
      X=mid;
      right=mid-1;
    }
    else
      left=mid+1;
  }
  
  cout << X;
}

int check(int x)
{
  int ret=0;
  // cout << "@" << x << endl;
  for(int i=1;i<=col;i++)
  {
    if(arr[i])
    {
      // cout << i << " ";
      ret++;
      i+=x-1;
    }
  }

  if(ret>N)
    return 0;
  return 1;
  
}