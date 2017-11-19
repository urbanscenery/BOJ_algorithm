#include<iostream>
#include<algorithm>

using namespace std;

long long dp[91][2];

void initDP(){
    for(int i = 0 ; i < 91 ; i++){
        dp[i][0] = -1;
        dp[i][1] = -1;
    }
    dp[1][0] = 0;
    dp[1][1] = 1;
}

long long calDP(int n, int m){
    if(dp[n][m] >= 0 ) return dp[n][m];
    else{
        if(m == 1){
            dp[n][m] = calDP(n-1,0);
        }
        else{
            dp[n][m] = calDP(n-1,0) + calDP(n-1, 1);
        }
        return dp[n][m];
    }
}

int main(){
    initDP();
    long long sum = 0;
    int n;
    scanf("%d", &n);

    sum += calDP(n,0);
    sum += calDP(n,1);
    printf("%lld\n", sum);
    return 0;
}
