#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int h[maxn], dp[maxn];

int main(){
    int n; memset(dp, 0x3f, sizeof dp);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    dp[n-2] = abs(h[n-2] - h[n-1]);
    dp[n-3] = abs(h[n-3] - h[n-1]);
    for(int i = n-4; i >= 0; i--)
        dp[i] = min(abs(h[i]-h[i+1])+dp[i+1], abs(h[i]-h[i+2])+dp[i+2]);
    cout << dp[0] << '\n';
}