#include<iostream>
#include<algorithm>

using namespace std;

class tile{
private:
    int dp[1001];
public:
    void initDP(){
        fill_n(dp, 1001, -1);
        dp[0] = 1;
        dp[1] = 1;
    }
    int cal(int n);
};

int tile::cal(int n){
    if(n<2) return dp[n];
    else{
        if(dp[n]<0){
            dp[n] = (cal(n-1) + cal(n-2)) % 10007;
        }
        return dp[n];
    }
}


int main(){
    int a;
    tile A;
    scanf("%d", &a);
    if(a == 0){
        printf("0\n");
        return 0;
    }
    A.initDP();
    printf("%d\n", A.cal(a));
    return 0;
}
