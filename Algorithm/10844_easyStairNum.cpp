#include<iostream>
#include<algorithm>
#define mod 1000000000

using namespace std;

int dp[101][10];

void initDP(){
    for(int i = 0 ; i < 101 ; i++){
        for(int j = 0 ; j <10 ; j++)
            dp[i][j] = -1;
    }
    for(int i = 0 ; i <10 ; i++){
        dp[1][i] = 1;
    }
    dp[1][0] = 0;
}

int calDP(int n, int m){
    if(dp[n][m] >= 0) return dp[n][m];
    else{
        if(m>0 && m<9)
            dp[n][m] = (calDP(n-1, m-1) + calDP(n-1, m+1))%mod;
        else if(m == 0)
            dp[n][m] = calDP(n-1, m+1)%mod;
        else
            dp[n][m] = calDP(n-1, m-1)%mod;
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
