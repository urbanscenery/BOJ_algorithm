#include <vector>
#include <algorithm>

using namespace std;

int MOD = 20170805;
int dp[501][501];

void initDP(){
    for(int i = 0 ; i <501 ; i++){
        for(int j = 0 ; j< 501 ; j++){
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 1;
}

int calDP(int i , int j, const vector<vector<int>> city_map){
    if(dp[i][j]>= 0) return dp[i][j];
    else{
        if(city_map[i][j] == 0){
            dp[i][j] = (calDP(i-1,j) + calDP(i,j-1))%MOD;
            return dp[i][j];
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    initDP();
    int answer = 0;
    answer = calDP(m-1, n-1, city_map);
    return answer;
}
