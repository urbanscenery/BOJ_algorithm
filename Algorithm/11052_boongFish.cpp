#include<iostream>
#include<algorithm>

using namespace std;

class boongFish{
private:
    int cost[1001];
    int dp[1001];

public:
    void init(int j, int cost);
    void initDP();
    int calCost(int a);
};


int boongFish::calCost(int a){
    if(a<2) return dp[a];
    else{
        if(dp[a]<0){
            int temp = 0;
            for(int i = 1; i<=a; i++){
                int temp2 = calCost(a-i)+cost[i];
                if(temp2>temp) temp = temp2;
            }
            dp[a] = temp;
        }
        return dp[a];
    }
}

void boongFish::init(int i, int c){
    cost[i] = c;
}

void boongFish::initDP(){
    fill_n(dp, 1001, -1);
    dp[0] = 0;
    dp[1] = cost[1];
}

int main(){
    boongFish A;
    int t;
    scanf("%d", &t);
    for(int i = 1 ; i<=t ; i++){
        int cost;
        scanf("%d", &cost);
        A.init(i, cost);
    }
    A.initDP();
    printf("%d\n", A.calCost(t));
    return 0;
}
