#include <iostream>
// #include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

void input();
void solve();

int L,C;
// char arr[26];
vector<char> V;
char ret[15];

int main() {
  input();
  solve();
}

void input()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // memset(arr,0,sizeof(arr));

  cin >> L >> C;
  char c;
  for(int i=0;i<C;i++){
    cin >> c;
    V.push_back(c);
  }

  sort(V.begin(),V.end());

}

void solve()
{
  vector<int> k;
  for(int i=0;i<L;i++)
    k.push_back(0);
  for(int i=0;i<C-L;i++)
    k.push_back(1);
  sort(k.begin(),k.end());

  do{
    int consonant=0,vowel=0,idx=0;
    for(int i=0;i<k.size();i++){
      if(!k[i])
      {
        ret[idx++]=V[i];
        switch(V[i])
        {
          case 'a':
            vowel++;
            break;
          case 'e':
            vowel++;
            break;
          case 'i':
            vowel++;
            break;
          case 'o':
            vowel++;
            break;
          case 'u':
            vowel++;
            break;
          default:
            consonant++;
            break;
        }
      }

      
    }
    if(consonant>=2&&vowel>=1)
    {
      for(int i=0;i<L;i++){
        cout << ret[i];
      }
      cout << '\n';
    }
  }while(next_permutation(k.begin(),k.end()));
}