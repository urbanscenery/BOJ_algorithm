#include<iostream>
#include<algorithm>

using namespace std;

class RGB{
private:
    int color[3][1002];
    int cost[3][1002];
public:
    void setColor(int red, int blue, int green, int i);
    int cal(int house);
};

void RGB::setColor(int red, int blue, int green, int i){
    color[0][i] = red;
    color[1][i] = blue;
    color[2][i] = green;
}
int RGB::cal(int house){
    cost[0][1] = color[0][1];
    cost[1][1] = color[1][1];
    cost[2][1] = color[2][1];
    for(int i = 2; i<=house ; i++){
        cost[0][i] = color[0][i]+min(cost[1][i-1],cost[2][i-1]);
        cost[1][i] = color[1][i]+min(cost[0][i-1],cost[2][i-1]);
        cost[2][i] = color[2][i]+min(cost[0][i-1],cost[1][i-1]);
    }
    int real = min(cost[0][house],min(cost[1][house],cost[2][house]));
    return real;
}

int main(){
    int house;
    RGB A;
    scanf("%d", &house);
    for(int i = 1 ; i<=house;i++){
        int r;
        int g;
        int b;
        scanf("%d %d %d", &r, &g, &b);
        A.setColor(r,g,b,i);
    }
    printf("%d\n", A.cal(house));
    return 0;
}
