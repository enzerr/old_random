#include<bits/stdc++.h>
using namespace std;







int main(){
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({c, b});
		adj[b].push_back({c, a});
	}

	
}