#include<iostream>
#include<algorithm>

using namespace std;

int dp[1001];
int arr[1001];

void init(){
    fill_n(dp, 1001, -1);
    fill_n(arr, 1001, 0);
    dp[0] = 0;
    dp[1] = 1;
}

int calDP(int n){
    if(dp[n] > 0) return dp[n];
    else{
        int temp = 0;
        for(int i = 1; i < n ; i++){
            if(arr[n] < arr[i]){
                temp = max(temp, calDP(i));
            }
        }
        dp[n] = temp +1;
        return dp[n];
    }
}


int main(){
    //왜 init을 안썼는데 맞는거지????
    init();
    int k;
    scanf("%d", &k);
    for(int i = 1 ; i <= k ; i++){
        scanf("%d", &arr[i]);
    }
    int longest = 0;
    for(int i = 1; i<=k ; i++){
        longest = max(longest, calDP(i));
    }
    printf("%d\n", longest);
    return 0;
}
