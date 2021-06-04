#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void input();
void solve();
int N;

vector <pair<int,int>> arr;
vector <pair<int,int>> arr2;

int main() {
  input();
  solve();
}

void input(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  int a,b;
  for(int i=0;i<N;i++)
  {
    cin >> a >> b;
    arr.push_back({a,-1});
    arr.push_back({b,1});
    arr2.push_back({a,b});
  }

  sort(arr.begin(),arr.end());

}

void solve(){
  int ret=0,here,now=0;//ret는 겹치는 개수 최댓값, here는 ret의 위치, now는 현재 겹친 개수
  for(int i=0;i<arr.size();i++){
    now -= arr[i].second;
    if(ret<now){
      ret=now;
      here=arr[i].first;
    }
    
  }
  cout << ret << "\n";
  
  for(int i=0;i<arr2.size();i++)
  {
    if(arr2[i].first<=here && arr2[i].second >= here)
    {
      cout << i+1 << " ";
    }
  }
}