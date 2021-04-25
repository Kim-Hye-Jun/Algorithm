#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void input();
void solve();
int N;

int arr[5001];
int main() {
  input();
  solve();

  // vector <int> a;
  // a.push_back(1);
  // a.push_back(5);
  // a.push_back(3);
  // a.push_back(22);

  // auto it = a.begin()+1;
  // cout << *it;
}

void input()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a;
  cin >> N;
  for(int i=0;i<N;i++)
  {
    cin >> arr[i];
  }
  sort(arr,arr+N);
  
}

void solve()
{
  long long X,ret=3000000000,ans1,ans2,ans3;
  int idx;
  int flag=0;
  for(int i=0;i<N-2;i++)
  {
    for(int j=i+2;j<N;j++)
    {
      X = -(arr[i]+arr[j]);
      idx = lower_bound(arr+(i+1),arr+(j-1),X)-arr;
      if(idx>i+1&&abs(arr[idx]-X)>abs(arr[idx-1]-X))
        idx--;
      
      if(abs(arr[idx]-X)<ret)
      {
        ret = abs(arr[idx]-X);
        ans1 = arr[i];
        ans2 = arr[idx];
        ans3 = arr[j];
      }
      if(!abs(arr[idx]-X))
      {
        flag = 1;
        break;
      }
    }
    if(flag)
      break;
  }
  cout << ans1 << " " << ans2 << " " << ans3;
}