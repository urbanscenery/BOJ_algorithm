#include<iostream>
#include<algorithm>

using namespace std;

int arr[100001];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
	}
	int b = 200000001;
	for (int i = 1; i < n; i++){
		for (int j = i + 1; j <= n; j++){
			int temp = arr[i] + arr[j];
			if ((b < 0) && (temp < 0)){
				b = max(b, temp);
			}
			else if ((b > 0) && (temp < 0)){
				int x = -temp;
				if (min(b, x) == x){
					b = temp;
				}
			}
			else if ((b < 0) && (temp > 0)){
				int x = -b;
				if (min(x, temp) == temp){
					b = temp;
				}
			}
			else if ((b > 0) && (temp > 0)){
				b = min(b, temp);
			}
		}
	}
	printf("%d", b);
	return 0;
}