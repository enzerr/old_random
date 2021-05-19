#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18 + 10;

int main(){
    int n, w; cin >> n >> w;
    vector<int> weight(n), value(n);
    int max_value = 0;
    for(int i = 0; i < n; i++){
        cin >> weight[i] >> value[i];
        max_value += value[i];
    }

    vector<long long> dp(max_value+1, INF);
    dp[0] = 0;
    for(int item = 0; item < n; item++){
        for(int i = max_value-value[item]; i >= 0; i--){
            dp[i + value[item]] = min(dp[i + value[item]], dp[i] + weight[item]);
        }
    }
    long long ans = 0;
    for(long long i = 0; i <= max_value; i++){
        if(dp[i] <= w) ans = max(ans, i);
    }
    cout << ans << '\n';
}