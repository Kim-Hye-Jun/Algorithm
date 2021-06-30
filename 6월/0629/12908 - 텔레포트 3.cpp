#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void input();
void solve();
long long check(int ex,int ey,int n,long long d);
long long MIN(long long,long long,long long);

int xs,ys,xe,ye;

int x1[3];
int y1[3];
int x2[3];
int y2[3];

vector<int> k;

int main(){
  input();
  solve();
  
  
}

long long check(int ex,int ey,int n,long long d)
{
  if(n==3)
  {
    return d+abs(xe-ex)+abs(ye-ey);
  }
  else
    return MIN(check(ex,ey,n+1,d),
    check(x1[k[n]],y1[k[n]],n+1,d+10+abs(x2[k[n]]-ex)+abs(y2[k[n]]-ey)),
    check(x2[k[n]],y2[k[n]],n+1,d+10+abs(x1[k[n]]-ex)+abs(y1[k[n]]-ey)));

}

void input()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> xs >> ys;
  cin >> xe >> ye;
  

  for(int i=0;i<3;i++)
  {
    cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
  }
  
}


void solve()
{
  k.push_back(0);
  k.push_back(1);
  k.push_back(2);

  long long ret;
  ret=abs(xs-xe)+abs(ys-ye);
  do{
    

    long long distance=MIN(check(xs,ys,1,0),
    check(x1[k[0]],y1[k[0]],1,10+abs(x2[k[0]]-xs)+abs(y2[k[0]]-ys)),
    check(x2[k[0]],y2[k[0]],1,10+abs(x1[k[0]]-xs)+abs(y1[k[0]]-ys)));

    ret=min(ret,distance);
    
  }while(next_permutation(k.begin(),k.end()));
  cout << ret;
}

long long MIN(long long a,long long b,long long c)
{
  return min(min(a,b),c);
}