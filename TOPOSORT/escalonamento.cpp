#include<bits/stdc++.h>
using namespace std;
const int maxn = 50010;




int main(){
	int n, m; cin >> n >> m;
	vector<int> v[maxn], ans, grau(n, 0), mark(n, 0);
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0 ; i < m; i++){
		int a, b; cin >> a >> b;

		v[a].push_back(b);
		grau[b] += 1;
	}

	for(int i = 0; i < n; i++){
		if(grau[i] == 0){
			pq.push(i);
		}
	}

	while(!pq.empty()){
		int f = pq.top();
		pq.pop();
		ans.push_back(f);
		mark[f] = 1;
		for(auto x : v[f]){
			grau[x]--;
			if(grau[x] == 0){
				pq.push(x);
			}
		}
	}

	for(auto x : mark){
		if(x == 0){
			cout << "*\n";
			return 0;
		}
	}

	for(int i = 0; i < n; i++){
		cout << ans[i] << '\n';
	}
}