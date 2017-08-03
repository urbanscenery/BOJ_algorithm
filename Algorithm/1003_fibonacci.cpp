#include<iostream>

using namespace std;

class fibonacci{
private:
    int zero[41];
    int one[41];
public:
    fibonacci(){
        fill_n(zero, 41, -1);
        fill_n(one, 41, -1);
        zero[0] = 1;
        zero[1] = 0;
        one[0] = 0;
        one[1] = 1;
    }
    ~fibonacci(){};
    int calZero(int n);
    int calOne(int n);
};

int fibonacci::calZero(int n){
    if(n<2) return zero[n];
    else{
        if(zero[n]>0) return zero[n];
        else{
            zero[n] = calZero(n-1) + calZero(n-2);
            return zero[n];
        }
    }
}

int fibonacci::calOne(int n){
    if(n<2) return one[n];
    else{
        if(one[n]>0) return one[n];
        else{
            one[n] = calOne(n-1) + calOne(n-2);
            return one[n];
        }
    }
}

int main(){
    int t;
    int a;
    fibonacci A;
    scanf("%d", &t);
    for(int i = 0 ; i<t ; i++){
        scanf("%d", &a);
        printf("%d %d\n", A.calZero(a), A.calOne(a));
    }
    return 0;
}
