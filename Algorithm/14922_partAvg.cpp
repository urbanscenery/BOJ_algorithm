#include<iostream>
#include<algorithm>

using namespace std;

unsigned int arr[2000000];

int main(){
	int k;
	int answer = -1;
	scanf("%d", &k);
	for (int i = 0; i < k; i++){
		scanf("%d", &arr[i]);
	}
	double temp = 100000000;
	for (int i = 0; i < k-1; i++){
		double a = double(arr[i] + arr[i + 1]) / 2;
		if (min(temp, a) == a){
			if (temp != a){
				temp = a;
				answer = i;
			}
		}
	}
	printf("%d", answer);
	return 0;

}