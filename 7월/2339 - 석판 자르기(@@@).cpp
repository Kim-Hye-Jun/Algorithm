#include <iostream>
#include <vector>

using namespace std;

void input();
int solve(int,int,int,int,bool);

int N,ret;
int arr[20][20];

int main() {
  input();
  int ret1=solve(0,0,N,N,true);
  int ret2=solve(0,0,N,N,false);
  int ans=ret1+ret2;

  if(ans==0)
    cout << -1;
  else
    cout << ans;
}

void input(){
  cin >> N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> arr[i][j]; 
    }
  }
}

int solve(int x,int y,int X,int Y,bool dir){
  // 더 잘라야 하는지, 못자르는지 ??
  
  int imp=0,jew=0;
  for(int i=x;i<X;i++){
    for(int j=y;j<Y;j++){
      if(arr[i][j]==1)
        imp++;
      else if(arr[i][j]==2)
        jew++;
    }
  }
  // cout << imp << " " << jew << endl;
  if(jew==0)
    return 0;
  else if(jew==1){
    if(imp==0)
      return 1;
    else
      return 0;
  }
  else if(jew>=2){
    if(imp==0)
      return 0;
  }
  
  int ret=0;
  for(int i=x;i<X;i++){
    for(int j=y;j<Y;j++){
      bool flag=true;
      if(arr[i][j]==1){
        if(dir){
          if(i==x||i==X-1)
            flag=false;
          
          for(int k=y;k<Y;k++){
            if(arr[i][k]==2){
              flag=false;
              break;
            }
          }

          if(flag){
            ret += solve(x,y,i,Y,false)*solve(i+1,y,X,Y,false);
          }
        }else{ // !dir
          if(j==y||j==Y-1)
            flag=false;
          
          for(int k=x;k<X;k++){
            if(arr[k][j]==2){
              flag=false;
              break;
            }
          }

          if(flag){
            ret += solve(x,y,X,j,true)*solve(x,j+1,X,Y,true);
          }
        }
      }
    }
  }
  return ret;

}