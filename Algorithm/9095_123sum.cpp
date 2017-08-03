#include<iostream>
#include<algorithm>

using namespace std;

int dp[11];


int cal(int n){
    if(dp[n] >= 0) return dp[n];
    else{
        dp[n] = cal(n-1) + cal(n-2) + cal(n-3);
        return dp[n];
    }
}

int main(){
    fill_n(dp, 11, -1);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k ; i++){
        int n;
        scanf("%d", &n);
        printf("%d\n", cal(n));
    }

    return 0;
}
