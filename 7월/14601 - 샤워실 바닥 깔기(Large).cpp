#include <iostream>
#include <cmath>

using namespace std;

void input();
void solve();
void PRINT();
void func(int,int,int);

const int K=7;
int N,x,y;
int num;
int arr[(1<<K)+1][(1<<K)+1];

int main() {
  input();
  solve();
  PRINT();
}

void input(){
  ios_base::sync_with_stdio(false);

  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  cin >> x >> y;
  
  arr[(int)pow(2,N)-y+1][x]=-1;
}

void PRINT(){
  for(int i=1;i<=(int)pow(2,N);i++){
    for(int j=1;j<=(int)pow(2,N);j++){
      cout << arr[i][j] << " ";
    }
    cout << '\n';
  }
}

bool check(int x,int y,int n){
  for(int i=x;i<x+n;i++){
    for(int j=y;j<y+n;j++){
      if(arr[i][j]!=0)
        return false;    
    }
  }
  return true;
}

void func(int x,int y,int n){

  if(n==2){
    for(int i=x;i<x+n;i++){
      for(int j=y;j<y+n;j++){
        if(arr[i][j]==0)
          arr[i][j]=num;
      }
    }
    num++;
    return;
  }
  
  n/=2;
  if(check(x,y,n)) arr[x+n-1][y+n-1]=num;
  if(check(x+n,y,n)) arr[x+n][y+n-1]=num;
  if(check(x,y+n,n)) arr[x+n-1][y+n]=num;
  if(check(x+n,y+n,n)) arr[x+n][y+n]=num;
  num++;

  func(x,y,n);
  func(x,y+n,n);
  func(x+n,y,n);
  func(x+n,y+n,n);
  
}

void solve(){
  num=1;
  func(1,1,pow(2,N));
}