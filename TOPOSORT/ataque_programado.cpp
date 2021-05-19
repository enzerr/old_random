#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;

int n, m, sold;
priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
greater<pair<int, pair<int, int>>> > pq;
vector<int> adj[maxn];
int mark[maxn], grau[maxn];
pair<int, pair<int, int>> bases[maxn];


void bfs(){

	for(int i = 1; i <= n; i++){
	   	if(grau[i] == 0) pq.push(bases[i]);
	   }

	   while(!pq.empty()){
	   	int f = pq.top().first;
	   	if(f >= sold) break;
	   	int s = pq.top().second.first;
	   	int y = pq.top().second.second;
	   	sold+=s;
	   	mark[y] = 1;
	   	pq.pop();

	   	for(int i = 0; i < adj[y].size(); i++){
	   		grau[adj[y][i]]--;
	   		if(grau[adj[y][i]] == 0){
	   			pq.push(bases[adj[y][i]]);
	   		}
	   	}
	   }
}

///////////////////////////////////////////////////////
int main(){
	while(cin >> n >> m >> sold){
		if(n == 0 && m == 0 && sold == 0){
			return 0;
		}
		while(!pq.empty()) pq.pop();
		for(int i = 1; i <= n; i++){
			bases[i].first = 0;
			bases[i].second.first = 0;
			grau[i] = 0;
			mark[i] = 0;
			adj[i].clear();
		}


	   for(int i = 1; i <= n; i++){
	        cin >> bases[i].first; // soldados inimigos
	        bases[i].second.second = i;
	   }
	   for(int i = 1; i <= n; i++){
	        cin >> bases[i].second.first; // refens
	   }

	   for(int i = 1; i <= m; i++){
	   	int a, b; cin >> a >> b;
	   	adj[a].push_back(b);
	   	grau[b]++;
	   }

	   bfs();

	   int nain = 0;
	   for(int i = 1; i <= n; i++){
	   	if(mark[i] == 0){
	   		cout << "impossivel\n";
	   		nain++;
	   		break;
	   	}
	   }
	   if(nain == 0){
	   	cout << "possivel\n";
	   }
	}
}