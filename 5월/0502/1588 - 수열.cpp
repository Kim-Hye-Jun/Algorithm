#include <iostream>


using namespace std;
void input();
void init();
void solve(int num, long long start, long long end, long long range);
long long pow(int x, int y);
int sqrt(long long x);


int n,l,r,N;
long long ret1=0,ret2=0,ret3=0;
long long dp[4][21][4]; // 시작 , N ? , 무엇의 개수

int main()
{
  input();
  init();
  solve(n,0,pow(3,N)-1,pow(3,N));
  cout << ret1 << " " << ret2 << " " << ret3;
}

void input()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> l >> r >> N;
}

void init()
{
  long long a1,a2,a3;
  long long t1,t2,t3;
  a1=1,a2=0,a3=0;
  for(int i=1;i<=20;i++)
  {
    t1 = a1 + a2*2;
    t2 = a1 + a2 + a3*2;
    t3 = a1 + a3;

    a1 = dp[1][i][1] = t1;
    a2 = dp[1][i][2] = t2;
    a3 = dp[1][i][3] = t3;  
  }

  a1=0,a2=1,a3=0;
  for(int i=1;i<=20;i++)
  {
    t1 = a1 + a2*2;
    t2 = a1 + a2 + a3*2;
    t3 = a1 + a3;

    a1 = dp[2][i][1] = t1;
    a2 = dp[2][i][2] = t2;
    a3 = dp[2][i][3] = t3;  
  }

  a1=0,a2=0,a3=1;
  for(int i=1;i<=20;i++)
  {
    t1 = a1 + a2*2;
    t2 = a1 + a2 + a3*2;
    t3 = a1 + a3;

    a1 = dp[3][i][1] = t1;
    a2 = dp[3][i][2] = t2;
    a3 = dp[3][i][3] = t3;
  }
}

void solve(int num, long long start, long long end, long long range)
{
  if( (range != 1) && (r<start || l>end)) // 아예 포함되지 않음 inRange(start,end)==0
    return;
  if ((range != 1) &&(l<=start && end <=r)) // 완전 포함 inRange(start,end)==2
  {
    int r = sqrt(range);
    ret1 += dp[num][r][1];
    ret2 += dp[num][r][2];
    ret3 += dp[num][r][3];
    return;
  }
  if(range==1)
  {
    if((l<=start && start <=r)) //inRange(start,end)==2
    {
      switch(num){
        case 1:
        {
          ret1++;
          break;
        }
        case 2:{
          ret2++;
          break;
        }
          
        case 3:{
          ret3++;
          break;
        }
      }
    }
    return;
  }

  long long new_range = range / 3;

  long long s1 = start, e1 = s1 + new_range-1;
  long long s2 = e1+1, e2 = s2 + new_range-1;
  long long s3 = e2+1, e3 = s3 + new_range-1;
  
  switch(num){
    case 1:{
      solve(1,s1,e1,new_range);
      solve(3,s2,e2,new_range);
      solve(2,s3,e3,new_range);
      break;
    }
    case 2:{
      solve(2,s1,e1,new_range);
      solve(1,s2,e2,new_range);
      solve(1,s3,e3,new_range);
      break;
    }
    case 3:{
      solve(2,s1,e1,new_range);
      solve(3,s2,e2,new_range);
      solve(2,s3,e3,new_range);
      break;
    }
  }
  return;
}

long long pow(int x, int y){

  if (y == 0)
    return 1;
  else if (y == 1)
    return x;

  if (y & 1)
    return pow(x, y - 1)*pow(x, 1);
  else
    return pow(x, y / 2)*pow(x, y / 2);

}

int sqrt(long long x){

  int cnt = 0;

  for(; x != 1; x /= 3, cnt++);
  
  return cnt;
}