#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int graph[1001][1001];
int finished[1001];
int n,
    m,
    start;
queue<int> Q;

void init(){
    for(int i = 0 ; i < 1001 ; i += 1){
        for(int j = 0 ; j < 1001 ; j += 1){
            graph[i][j] = -1;
        }
    }
    for(int i = 0 ; i < m ; i += 1){
        int x,
            y;
        scanf("%d %d", &x, &y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    fill_n(finished, 1001, -1);
}

void DFS(int nodeNum){
    finished[nodeNum] = 1;
    printf("%d ", nodeNum);
    for(int i = 1 ; i <= n ; i += 1){
        if((graph[nodeNum][i] > 0) && (finished[i] < 0)){
            DFS(i);
        }
    }
}





void BFS(int start){
    Q.push(start);
    finished[start] = 1;
    while(!Q.empty()){
        int nodeNum = Q.front();
        printf("%d ", nodeNum);
        Q.pop();
        for(int i = 1 ; i <= n ; i+=1){
            if((graph[nodeNum][i] > 0) && (finished[i] < 0)){
                finished[i] = 1;
                Q.push(i);
            }
        }
    }
}





int main(){
    scanf("%d %d %d", &n, &m, &start);
    init();
    DFS(start);
    printf("\n");
    fill_n(finished, 1001, -1);
    BFS(start);
    printf("\n");
    return 0;
}
