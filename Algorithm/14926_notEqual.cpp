#include<iostream>

using namespace std;
int graph[500][500];

void init(int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			graph[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < i; j++){
			graph[i][j] = 1;
			graph[j][i] = 1;
		}
	}
	graph[n-1][0] = 0;
	graph[0][n - 1] = 0; 
}


void find(int n, int size){
	printf("a%d ", n);
	int i = 0;
	for (; i < size; i++){
		if (graph[n-1][i] == 1){
			graph[n-1][i] = 0;
			graph[i][n-1] = 0;

			find(i + 1, size);
			break;
		}
	}
}

int main(){
	int size;
	scanf("%d", &size);
	init(size);
	find(1, size);
	printf("a1");
	return 0;
}