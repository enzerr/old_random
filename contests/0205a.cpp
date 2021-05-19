#include<bits/stdc++.h>
using namespace std;




int main(){
	int t; cin >> t;
	while(t--){
		int arr[105];
		int sum = 0;
		int n, x; cin >> n >> x;
		for(int i = 0; i < n; i++){
			cin >> arr[i];
			sum += arr[i];
		}

		if(sum != x) cout << "YES\n";
		else{
			cout << "NO\n";
			continue;
		}
		if(x > sum){
			for(int i = 0; i < n; i++){
				cout << arr[i] << " ";
			}
			cout << '\n';
			continue;
		}
		if(x < sum){
			int add = 0;
			for(int i = 0; i < n; i++){
				if((add + arr[i]) == x){
					cout << arr[i+1] << " " << arr[i] << " ";
					add += arr[i+1] + arr[i];
					i++;
				} else{
					cout << arr[i] << " ";
					add += arr[i];
				}
			}
			cout <<'\n';
		}


	}
}