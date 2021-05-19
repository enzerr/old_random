#include<bits/stdc++.h>
using namespace std;
const int maxn = 200005;

vector<int> adj[maxn];
int sub[maxn];

void dfs(int a){
	for(auto x : adj[a]){
		dfs(x);
		sub[a] += sub[x]+1;
	}
}

int main(){
	int n; cin >> n;
	for(int i = 1; i < n; i++){
		int a; cin >> a;
		adj[a].push_back(i+1);
		//adj[i].push_back(a);
	}

	dfs(1);

	for(int i = 1; i <= n; i++){
		cout << sub[i] << " ";
	}
	cout << '\n';
}