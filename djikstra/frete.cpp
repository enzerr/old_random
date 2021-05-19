#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int INF = 1e9;

vector<pair<int, int>> adj[maxn];
vector<int> dist(maxn, INF);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int cont = 0;

void djikstra(){
	pq.push({0, 1});
	dist[1] = 0;
	while(!pq.empty()){
		//if(cont > 20) break;
		//cont++;
		
		int y = pq.top().second; //i
		//cout << y << "\n";
		pq.pop();

		for(auto x : adj[y]){
			int w = x.first;  //peso
			int z = x.second; //j
			if(z == y) continue;
			//cout << z << " ";

			if(dist[z] > dist[y] + w){
				dist[z] = dist[y] + w;
				pq.push(x);
			}
		}
		//cout << '\n';
	}
}

int main(){
	int n, m ; cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({c, b});
		adj[b].push_back({c, a});
	}
	djikstra();
	cout << dist[n] << '\n';
}