#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int temp = 0;
    int result = -10000;
    int k;
    scanf("%d", &k);
    for(int i = 0 ; i < k ; i++){
        int num;
        scanf("%d", &num);
        temp += num;
        result = max(result, temp);
        if(temp < 0) temp = 0;
    }
    printf("%d\n", result);
    return 0;
}
