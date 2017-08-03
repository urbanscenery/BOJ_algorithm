#include<iostream>
#include<algorithm>
#include<string>
#define mod 1000000

using namespace std;

class password{
private:
    int num[5001];
    int dp[5001];
public:
    password(){
        fill_n(num,5001,-1);
        fill_n(dp,5001,-1);
        dp[0] = 1;
        dp[1] = 1;
    }
    int cal(int n);
    void setNum(int a, int i);
};

int password::cal(int n){
    if(n<2) return dp[n];
    else{
        if(num[n]==0){
            if(dp[n]<0)
                dp[n] = cal(n-1) % mod;
            return dp[n];
        }
        else if((num[n-1]==1)||(num[n-1]==2&&num[n]<7)){
            if(dp[n]<0){
                if(num[n+1] == 0){
                    dp[n] = cal(n-1) % mod;
                }
                else{
                    dp[n] = (cal(n-1) + cal(n-2)) % mod;
                }
            }
            return dp[n];
        }
        else{
            if(dp[n]<0) dp[n] = cal(n-1) % mod;
            return dp[n];
        }
    }
}

void password::setNum(int a, int i){
    num[i] = a;
}

int main(){
    int temp=100;
    password A;

    char arr[5001];
    string s;
    scanf("%s", arr);
    s = arr;
    int size = s.size();

    if( s == "0"){
        cout << "0" << endl;
        return 0;
    }
    for(int j = 1 ; j <= size ; j++){
        A.setNum(arr[j-1]-'0', j);
    }
/*
    while(temp!=EOF){
        scanf("%1d", &temp);
        A.setNum(temp, i);
        i++;
    }*/
    printf("%d\n", A.cal(size));
    return 0;
}
