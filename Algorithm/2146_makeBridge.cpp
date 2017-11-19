#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
int island[101][101][2];

void init(){
    for(int i = 0 ; i < 101 ; i++){
        for(int j = 0 ; j < 101 ; j++){
            island[i][j][0] = -1;
            island[i][j][1] = 0;
        }
    }
}

int main(){
    init();
    int k = 0;
    scanf("%d", &k);
    for(int i = 1 ; i < k+1 ; i++){
        for(int j = 1 ; j < k+1; j++){
            scanf("%d", &island[i][j][1]);
        }
    }
    for(int i = 1 ; i < k+1 ; i++){
        for(int j = 1 ; j < k+1; j++){
            printf("%d ", island[i][j][1]);
        }
        printf("\n");
    }
    return 0;
}
