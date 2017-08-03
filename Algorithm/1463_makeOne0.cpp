#include<iostream>
#include<algorithm>

using namespace std;

class one{
private:
    int dp[1000001];
public:
    one(){
        fill_n(dp,1000001,-1);
        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 1;
    }
    ~one(){};
    int calN(int n);
};


int one::calN(int n){
    if(n<4) return dp[n];
    else{
        if((n%2)!=0){
            if((n%3)!=0){
                if(dp[n]<0) dp[n] = calN(n-1)+1;
                return dp[n];
            }
            else{
                if(dp[n]<0) dp[n] = min(calN(n-1), calN(n/3))+1;
                return dp[n];
            }
        }
        else if((n%3)!=0){
            if(dp[n]<0) dp[n] = min(calN(n-1), calN(n/2)) +1;
            return dp[n];
        }
        else{
            if(dp[n]<0) dp[n] = min(calN(n-1), min(calN(n/2), calN(n/3)))+1;
            return dp[n];
        }
    }
}

int main(){
    int a;
    one A;
    scanf("%d", &a);
    printf("%d\n", A.calN(a));
    return 0;
}
