#include<bits/stdc++.h>
using namespace std;



long long dp[110000];


int main(){
    int n, w; cin >> n >> w;

    while(n--){
        int peso, value; cin >> peso >> value;
        for(int i = w-peso; i >= 0; i--){
            dp[i+peso] = max(dp[i+peso], dp[i] + value);
        }
        
    }
    long long ans = 0;
    for(auto v : dp) ans = max(ans, v);
    cout << ans << '\n';
}