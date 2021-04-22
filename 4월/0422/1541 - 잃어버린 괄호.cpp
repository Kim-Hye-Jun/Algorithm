#include <iostream>
#include <cstring>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  
  int a=0,b=0,c=0;
  int flag=0;
  for(int i=0;i<s.length();i++)
  {
    if(s.at(i)>='0'&&s.at(i)<='9')
    {
      if(flag==0)
      {
        a*=10;
        a+=s.at(i)-'0';
      }
      else
      {
        b*=10;
        b+=(int)s.at(i)-'0';
      }
    }
    else
    {
      if(flag!=0) // 첫 숫자가 아님
      {
        if(c==1) // -계산
          a-=b;
        else if(c==2)
          a-=b;
        else
          a+=b;
        b=0;
      }
      if(s.at(i)=='-')
        c=2;
      
      flag+=1;
    }
  }
  if(c==1) // -계산
    a-=b;
  else if(c==2)
    a-=b;
  else
    a+=b;
  b=0;
  cout << a;
}