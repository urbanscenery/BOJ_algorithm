#include<iostream>
#include<algorithm>

using namespace std;

int dp[301][3];
//dp[n][0] : 계단값
//dp[n][1] : dp계산값
//dp[n][2] : 뛴 연속계단수

void init(){
    dp[0][1] = 0;
    dp[1][1] = dp[1][0];
    dp[1][2] = 1;
    int temp = 1;
    dp[2][1] = max(dp[0][1], dp[1][1]) + dp[2][0];
    if(dp[1][1] > dp[0][1]){
        temp++;
    }
    dp[2][2] = temp;
}


int main(){
    int k;
    for(int i = 0 ; i < 301 ; i++){
        dp[i][0] = 0;
        dp[i][1] = -1;
        dp[i][2] = 0;
    }
    scanf("%d", &k);
    for(int i = 1 ; i <=k ;i++){
        scanf("%d", &dp[i][0]);
    }
    init();
    for(int n = 3; n<=k ; n++){
        if(dp[n-1][2]==2){
            if(dp[n-2][0]>dp[n-1][0]){
                dp[n][1] = dp[n-2][1] + dp[n][0];
                dp[n][2] = 1;
            }
            else{
                dp[n][1] = dp[n-3][1] + dp[n-1][0] + dp[n][0];
                dp[n][2] = 2;
            }
        }
        else{
            int temp = 1;
            dp[n][1] = max(dp[n-2][1], dp[n-1][1]) + dp[n][0];
            if(dp[n-1][1] > dp[n-2][1]){
                temp++;
            }
            dp[n][2] = temp;
        }
    }

    printf("%d\n", dp[k][1]);

    for(int i = 1 ; i <= k ; i++){
        printf("%d %d\n", dp[i][1] ,dp[i][2]);
    }
    return 0;
}
