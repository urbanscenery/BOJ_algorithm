#include<iostream>

using namespace std;

long long dp[35];

void init(){
	fill_n(dp, 35, -1);
	dp[0] = 1;
}

long long calDP(int n){
	if(dp[n]>0) return dp[n];
	else{
		long long temp = 0;
		for(int i = 0 ; i<n ; i++){
			temp += calDP(i)*calDP(n-i-1);
		}
		dp[n] = temp;
		return dp[n];
	}
}

int main(){
	int k;
	init();
	scanf("%d", &k);
	printf("%lld\n", calDP(k));
	return 0;
}