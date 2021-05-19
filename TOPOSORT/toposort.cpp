#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;

vector<int> adj[maxn], ans;
priority_queue<int, vector<int>, greater<int>> pq;
int grau[maxn], mark[maxn];

int main(){
	int n, m; cin >> n >> m;
	memset(grau, 0, sizeof grau);
	memset(mark, 0, sizeof mark);

	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		grau[b]++;
	}

	for(int i = 1; i <=n; i++){
		if(!grau[i]) pq.push(i);
	}

	while(!pq.empty()){
		int w = pq.top();
		ans.push_back(w);
		mark[w] = 1;
		pq.pop();
		for(auto x : adj[w]){
			grau[x]--;
			if(!grau[x]){
				pq.push(x);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		if(!mark[i]){
			cout << "Sandro fails.\n";
			return 0;
		}
	}

	for(auto x : ans){
		cout << x << " ";
	}
	cout << '\n';
}