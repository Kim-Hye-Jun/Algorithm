#include <iostream>
typedef long long ll;
using namespace std;

bool check(ll);
ll coin2(ll n);
ll coin1(ll n);
void init();
int dp[101];
int main()
{
    init();
    ll T, N;
    ll k, t;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        ll ret = 0;
        while (N != 0)
        {
            if (check(N))
            {
                k = coin2(N);
                t = N / k;
                N -= t * k;
                ret += dp[t];
            }
            else
            {
                k = coin1(N);
                t = N / k;
                N %= k;
                ret += t;
            }
        }
        cout << ret << "\n";
    }

}

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    dp[0] = 0;
    dp[1] = 1;
    dp[10] = 1;
    dp[25] = 1;
    dp[100] = 1;

    for (int i = 2; i <= 99; i++)
    {
        dp[i] = dp[i - 1] + 1;
        if (i >= 25)
        {
            dp[i] = min(dp[i], dp[i - 25] + 1);
            dp[i] = min(dp[i], dp[i - 10] + 1);
        }
        else if (i >= 10)
            dp[i] = min(dp[i], dp[i - 10] + 1);
    }
}
bool check(ll n)
{
    if (100 > n)
    {
        if (n >= 25)
            return true;
        else
            return false;
    }
    return check(n / 100);
}
ll coin2(ll n)
{
    ll k = 1;
    while (n / 25 >= 100)
    {
        n /= 100;
        k *= 100;
    }

    return k;

}
ll coin1(ll n)
{
    ll k = 1;
    while (n >= 10)
    {
        n /= 10;
        k *= 10;
    }
    return k;
}
