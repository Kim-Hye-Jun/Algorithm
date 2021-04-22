#include <iostream>

int main() {
  int a,k=0,b;
  char c;
  for(scanf("%d",&a);scanf("%c",&c),c!=10;)
  {
    if(c=='-') k=1;
    scanf("%d",&b);
    if(k==0)
      a+=b;
    else
      a-=b;
  }
  printf("%d",a);
}