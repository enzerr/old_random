#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int h[maxn], dp[maxn];

int main(){
    int n, k; memset(dp, 0x3f, sizeof dp);
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> h[i];
    dp[0] = 0;

    for(int i = 1; i < k; i++){
        dp[i] = abs(h[i] - h[0]);
    }
    for(int i = k; i < n; i++) {
        for(int j = 1; j <= k; j++){
            dp[i] = min(dp[i], abs(h[i]-h[i-j])+dp[i-j]);
        }
    }
    cout << dp[n-1] << '\n';
}