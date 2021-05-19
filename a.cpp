#include<bits/stdc++.h>
using namespace std;
const int maxn = 

vector<int> adj;
int dist[maxn], pai[maxn], gene[maxn];


void bfs(int a){
	if(dist[a] > maxd){
		maxd = dist[a];
		maxid = a;
	}
	mark[a] = 1;
	for(auto x : adj[a]){
		if(x == pai[a]) continue;
		pai[x] = a;
		dist[x] = dist[a] + 1;
		bfs(x);
	}
}

gene(int a){
	gene[a] = 1;
	if(pai[a] == a) continue;
	gene(pai[a]);
}

int solve(int a, int b){

}

int main(){
	int maxd, maxid;


	int n; cin >> n;
	for(int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		adj[a].pushback(b);
		adj[b].pushback(a);
	}

	int v; cin >> v;
	for(int i = 0; i < v; i++){
		int a, b; cin >> a >> b;
		bfs(a, b);
		gene(maxid);
		cout << solve(a, b) << '\n';
	}
}