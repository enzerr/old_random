#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;



int main(){
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		vector<int> grau(n+1), mark(n+1);
		vector<vector<int>> adj(n+1);
		queue<int> fila;

		for(int i = 0; i < m; i++){
			int a, b; cin >> a >> b;
			adj[a].push_back(b);
			grau[b]++;
		}
		for(int i = 1; i <= n; i++){
			if(!grau[i]) fila.push(i);
		}
		while(!fila.empty()){
			int f = fila.front();
			mark[f] = 1;
			fila.pop();

			for(auto x : adj[f]){
				grau[x]--;
				if(!grau[x]) fila.push(x);
			}
		}
		int nein = 0;
		for(int i = 1; i <= n; i++){
			if(!mark[i]){
				cout << "SIM\n";
				nein++;
				break;
			}
		}

		if(!nein) cout << "NAO\n";
	}
}