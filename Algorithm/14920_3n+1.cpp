#include<iostream>
using namespace std;

int arr[1000000];
void init(){
	fill_n(arr, 1000000, 0); 
}

int c(int n){
	if (arr[n] % 2 == 0){
		arr[n + 1] = arr[n] / 2;
	}
	else{
		arr[n + 1] = 3 * arr[n] + 1;
	}
	return arr[n + 1];
}
int main(){
	int n = 0;
	init();
	scanf("%d", &n);
	arr[1] = n;
	for (int i = 1;; i++){
		if (c(i) == 1){
			printf("%d\n", i+1);
			break;
		}
	}
	return 0;
}