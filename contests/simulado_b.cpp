#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+ 5;

vector<int> adj[maxn], lol;


int main(){
	int n; cin >> n;
	for(int i = 1; i < n; i++){
		int a; cin >> a;
		adj[a].push_back(i+1);
	}
	
	for(int i = 1; i <= n; i++){
		if(adj[i].size() > 0){
			lol.push_back(i);
		}
	}
	
	for(int i = 0; i < lol.size(); i++){
		int leaf = 0;
		int l = lol[i];

		for(auto x : adj[l]){
			if(adj[x].size() == 0){
				leaf++;
			}
		}
		if(leaf < 3){
			cout << "No\n";
			return 0;
		}
	}

	cout << "Yes\n";
}