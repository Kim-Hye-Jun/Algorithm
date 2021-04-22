#include <iostream>
#include <deque>
using namespace std;

deque<long long> number;
deque<char> oper;

void input();
void compute();
void computeRight();
void computeLeft();

int main() {
  
  input();


  while(oper.size()>0)
    compute();
  

  cout << number[0];

}

void input()
{
  long long a,b;
  char c;
  for(scanf("%lld",&a);scanf("%c",&c),c!=10;)
  {
    number.push_back(a);
    oper.push_back(c);
    scanf("%lld",&a);
  }
  number.push_back(a);
}

void compute()
{
  int left,right;
  left = 0,right = oper.size()-1;

  char c1 = oper[left];
  char c2 = oper[right];

  long long k1,k2;

  if(c1=='*'||c1=='/')
  {
    if(c2=='*'||c2=='/') // 3번 조건 판단
    {
      if(c1=='*')
        k1 = number[0]*number[1];
      else
        k1 = number[0]/number[1];

      if(c2=='*')
        k2 = number[number.size()-2] * number[number.size()-1];
      else
        k2 = number[number.size()-2] / number[number.size()-1];

      if(k1<k2)
        computeRight();
      else
        computeLeft();
      
    }
    else
    {
      computeLeft();
    }

  }
  else
  {
    if(c2=='*'||c2=='/')
    {
      computeRight();
    }
    else
    {
      if(c1=='+')
        k1 = number[0] + number[1];
      else
        k1 = number[0] - number[1];
      
      if(c2=='+')
        k2 = number[number.size()-2] + number[number.size()-1];
      else
        k2 = number[number.size()-2] - number[number.size()-1];

      if(k1<k2)
        computeRight();
      else
        computeLeft();
    }
  }
}

void computeLeft()
{
  long long k;
  switch(oper[0])
  {
    case '*':
      k = number[0] * number[1];
      break;
    case '/':
      k = number[0] / number[1];
      break;
    case '+':
      k = number[0] + number[1];
      break;
    case '-':
      k = number[0] - number[1];
      break;
    default:
      break;
  }
  
  number.pop_front();
  number.pop_front();
  number.push_front(k);
  oper.pop_front();
}

void computeRight()
{
  long long k;
  int left = number.size()-2;
  int right = number.size()-1;
  switch(oper[oper.size()-1])
  {
    case '*':
      k = number[left] * number[right];
      break;
    case '/':
      k = number[left] / number[right];
      break;
    case '+':
      k = number[left] + number[right];
      break;
    case '-':
      k = number[left] - number[right];
      break;
    default:
      break;
  }

  number.pop_back();
  number.pop_back();
  number.push_back(k);
  oper.pop_back();
}