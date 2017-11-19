#include<iostream>

using namespace std;

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int w, x, y, z;
    w = (a+b)%c;
    x = (a%c + b%c)%c;
    y = (a*b)%c;
    z = (a%c * b%c)%c;
    printf("%d\n%d\n%d\n%d\n", w, x, y, z);
    return 0;
}
