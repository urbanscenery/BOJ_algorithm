#include<iostream>

using namespace std;

unsigned int num[1048576];

void init(){
	fill_n(num, 1048576, 0);
}

int main(){
	int temp = 0;
	init();

	while(scanf("%d", &temp) > 0){
		int i = temp/32;
		int j = temp%32;
		int k = 1 << j;
		if(!(num[i]&k)){
			num[i] = num[i]|k;
			printf("%d ", temp);
		}
	}

	return 0;
}