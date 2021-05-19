#include<bits/stdc++.h>
using namespace std;

int dp[3010][3010];
pair<int, int> pai[3010][3010];

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    string a, b; cin >> a >> b;
    
    
    pai[0][0] = make_pair(-1,-1);

    for(int i = 0; i < (int)a.size(); i++){
        for(int j = 0; j < (int)b.size(); j++){
            if(a[i] == b[j]){
                if(dp[i][j] + 1 > dp[i+1][j+1]){
                    dp[i+1][j+1] = dp[i][j]+1;
                    pai[i+1][j+1] = make_pair(i, j);
                }
            }
            if(dp[i][j] > dp[i][j+1]){
                dp[i][j+1] = dp[i][j];
                pai[i][j+1] = make_pair(i, j);
            }
            if(dp[i][j] > dp[i+1][j]){
                dp[i+1][j] = dp[i][j];
                pai[i+1][j] = make_pair(i, j);
            }
            //dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
            //dp[i+1][j] = max(dp[i+1][j], dp[i][j]);

        }
    }
    int ans = 0, x, y;
    for(int i = 0; i <= (int)a.size(); i++){
        for(int j = 0; j <= (int)b.size(); j++){
            if(dp[i][j] > ans){
                ans = dp[i][j];
                x = i;
                y = j;
            }
        }
    }

    if(ans == 0){
        cout << '\n';
        return 0;
    }

    string s;
    while(x != 0 && y != 0){
        if(a[x-1] == b[y-1]) s+= a[x-1];
        int xx = x, yy = y;
        x = pai[xx][yy].first;
        y = pai[xx][yy].second;
    }
    reverse(s.begin(), s.end());
    cout << s << '\n';
}