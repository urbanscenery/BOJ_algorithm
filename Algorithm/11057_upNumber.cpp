#include<iostream>
#include<algorithm>
#define mod 10007;

using namespace std;

int dp[1001][10];

void initDP(){
    for(int i = 0 ; i <1001 ; i++){
        for(int j = 0 ; j <10 ; j++)
            dp[i][j] = -1;
    }
    for(int i = 0; i < 10 ; i++){
        dp[1][i] = 1;
    }
}

int calDP(int n , int m){
    if(dp[n][m] > 0) return dp[n][m];
    else{
        dp[n][m] = 0;
        for(int i = 0 ; i <= m ; i++){
            dp[n][m] += calDP(n-1, i) % mod;
        }
        return dp[n][m];
    }
}

int main(){
    initDP();
    int sum = 0;
    int n;
    scanf("%d", &n);

    for(int i = 0 ; i < 10 ; i++){
        sum += calDP(n, i);
        sum = sum %mod;
    }
    printf("%d\n", sum);
    return 0;
}
