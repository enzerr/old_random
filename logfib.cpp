#include<bits/stdc++.h>
using namespace std;
const long long MAX = 1e18, MOD = 1e9 + 7;

long long a[2][2] = {{1, 1}, {1, 0}};
long long mat_ans[2][2] = {{1, 1}, {1, 0}};

void upd(){
	long long b[2][2];
	memset(b, 0, sizeof b);
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				b[i][j] += (a[i][k] * a[k][j])%MOD;
				b[i][j] %= MOD;
			}
		}
	}

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			a[i][j] = b[i][j];	
		}
	}
}

void updm(){
	long long b[2][2];
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++)
			b[i][j] = mat_ans[i][j];	
	}
	memset(b, 0, sizeof b);
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				b[i][j] += (mat_ans[i][k] * a[k][j])%MOD;
				b[i][j] %= MOD;
			}
		}
	}

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++)
			mat_ans[i][j] = b[i][j];	
	}
}
int main(){
	long long n; cin >> n;
	n-=3;
	if(n < 0) {cout << 1 << '\n'; return 0;}
	long long ans = 0;
	while(n > 0){
		if(n&1) updm();
		upd();
		n/=2;
	}

	ans = (mat_ans[0][0] + mat_ans[0][1])%MOD;
	cout << ans << '\n';
}