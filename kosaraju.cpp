#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;

vector<int> adj[maxn], adjr[maxn];
stack<int> stk;
int markr[maxn], mark[maxn];

void dfsr(int y){
	markr[y] = 1;
	//stk.push(y);
	for(auto x : adjr[y]){
		if(!markr[x]) dfsr(x);
	}
	stk.push(y);
}

void dfs(int y){
	mark[y] = 1;
	for(auto x : adj[y]){
		if(!mark[x]) dfs(x);
	}
}

int main(){
	int n, m; cin >> n >> m;

	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adjr[b].push_back(a);
	}
	int com = 0;
	for(int i = 1; i <= n; i++){
		if(!markr[i]) dfsr(i);
	}
	int a = stk.top();

	for(int i = 1; i <= n; i++){
		if(!mark[stk.top()]){
			com++;
			if(com == 2){
				cout << "NO\n" << a << " " << stk.top() << '\n';
				return 0;
			}

			dfs(stk.top());
		}
		stk.pop();
	}

	cout << "YES\n";
}