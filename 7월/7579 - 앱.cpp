#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

void input();
void solve();

vector<pair<int,int>> V;
int N,M;
long long memory[101];
int cost[101];
int dp[10101];
// 메모리합이 M이상의 최소비용
// M이 높고 c가 낮은거를 많이 넣어야됨
// 현재 앱을 추가를 할까...? 말까...?
/*
현재 n번째 앱을 넣는다면?
dp[n][1] = cost[n]+dp[M-cost[n]]
n번째 앱을 넣을때, 안넣을때의 최소비용을 구하자
넣는다면 cost[n]+M-
(m,c) c는 최소 m은 최대 잖아?
c가 무게 m은 비용
m이라는 비용이 나오기 까지 최소비용
dp[n][2] n까지 넣었을때의 최솟값
M이 넘는지 안넘는지...?
30 35 40 10 20
3  5   4  0  5
10 20 30 35 40
0  5   3  5  4
10 20 30  40 35 
0   3  3  4  5
비용의 최대 메모리
0 -> 10
3 -> 30
6 -> 60
n번째를 넣었을때
n을 넣는경우, n을 넣지 않는경우
1) 넣는 경우에는

13

*/

int main(){
  input();
  solve();
}

void input(){
  cin >> N >> M;
  V.resize(N);
  for(int i=0;i<N;i++){
    cin >> V[i].second;
  }

  for(int i=0;i<N;i++){
    cin >> V[i].first;
  }

  // sort(V.begin(),V.end()); 
}
//V-> cost, memory
void solve(){
  // for(int i=0;i<N;i++){
  //   dp[i]=0;
  // }
  memset(dp,0,sizeof(dp));
  int max_value=0;
  /*
  3-> 30
  0->10 , 
  */
  for(int i=0;i<V.size();i++){
    int now_cost = V[i].first;
    int now_mem = V[i].second;
    //dp[cost] = mem 최대화
    // 지금걸 넣어서 갱신가능하면 갱신
    max_value+=now_cost;
    
    // if(dp[now_cost]<now_mem)
    //   dp[now_cost]=now_mem;

    for(int j=max_value;j>=0;j--){
      if(dp[j+now_cost]<dp[j]+now_mem)
      {
        dp[j+now_cost]=dp[j]+now_mem;
        // cout << (j+now_cost) << ":"<<dp[j+now_cost]<< endl;
      }
        
    }
    
  }
  int ret=99999999;
  for(int i=0;i<=max_value;i++)
  {
    if(dp[i]>=M)
      ret=min(ret,i);
  }

  cout << ret;
  
}