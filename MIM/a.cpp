#include<bits/stdc++.h>
using namespace std;
int n, x;

vector<long long> arr, arr1, arr11, arr2, arr22;

void masks1(){
	for(int mask = 0; mask < (1<<arr1.size()); mask++){
		long long sum = 0;
		for(int i = 0; i < arr1.size(); i++){
			if(mask & (1<<i)){
				sum += arr1[i];
			}
		}
		arr11.push_back(sum);
	}
}

void masks2(){
	for(int mask = 0; mask < (1<<arr2.size()); mask++){
		long long sum = 0;
		for(int i = 0; i < arr2.size(); i++){
			if(mask & (1<<i)){
				sum += arr2[i];
			}
		}
		arr22.push_back(sum);
	}
}

int main(){
	cin >> n >> x;
	for(int i = 0; i < n; i++){
		int a; cin >> a;
		arr.push_back(a);
	}

	sort(arr.begin(), arr.begin());

	for(int i = 0; i < n/2; i++){
		arr1.push_back(arr[i]);
	}
	for(int i = n/2; i < n; i++){
		arr2.push_back(arr[i]);
	}

	masks1();
	masks2();
	sort(arr11.begin(), arr11.end());
	sort(arr22.begin(), arr22.end());

	long long ans = 0;
	for(int i = 0; i < arr11.size(); i++){
		ans += upper_bound(arr22.begin(), arr22.end(), x-arr11[i]) - lower_bound(arr22.begin(), arr22.end(), x-arr11[i]);
	}

	cout << ans << '\n';
}