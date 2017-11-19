#include<iostream>

using namespace std;

int main(){
	int s, t, d;

	scanf("%d %d %d", &s, &t, &d);
	int hour = d / (2 * s);
	printf("%d", t*hour);
	return 0;
}