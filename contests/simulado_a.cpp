#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
int parity[2], v[maxn];

int main(){
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> v[i];
		if(v[i]%2 == 1) parity[1]++;
		else parity[0]++;
	}
	if(parity[1] == 1){
		for(int i = 1; i <= n; i++){
			if(v[i]%2 == 1){
				cout << i << '\n';
				return 0;
			}
		}
	} else{
		for(int i = 1; i <= n; i++){
			if(v[i]%2 == 0){
				cout << i << '\n';
				return 0;
			}
		}
	}
}