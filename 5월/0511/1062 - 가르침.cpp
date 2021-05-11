#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N,K,ret=0;

void input();
void solve(int,int,int);
vector <string> v;
int visit[26];

int main() {
  input();
  int temp=0;
  temp |= (1<<('a'-'a'));
  temp |= (1<<('c'-'a'));
  temp |= (1<<('i'-'a'));
  temp |= (1<<('n'-'a'));
  temp |= (1<<('t'-'a'));
  solve(0,temp,0);
  cout << ret;
}

void input()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  K-=5;
  string s;
  for(int i=0;i<N;i++)
  {
    cin >> s;
    v.push_back(s);
  }

}

void solve(int cnt,int learn, int index)
{
  if(index>26) return;
  if(cnt==K)
  {
    int total=0;
    for(int i=0;i<N;i++)
    {
      string s = v[i];
      int flag = 0;
      for(int j=0;j<s.length();j++)
      {
        if((1<<(s.at(j)-'a'))& learn)
          continue;
        flag++;
        break;
      }

      if(!flag)
        total++;
    }
    ret = max(ret,total);
    return;
  }
  //anta tica
  if(index=='a'-'a'|| index=='t'-'a'|| index=='i'-'a'|| index=='n'-'a'|| index=='c'-'a')
    solve(cnt,learn,index+1);
  else
  {
    if(cnt<K)
      solve(cnt+1,learn|(1<<index),index+1);
    solve(cnt,learn,index+1);
  }
}