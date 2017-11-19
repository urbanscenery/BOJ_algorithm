#include<iostream>

using namespace std;

int countN[1001];

int main() {
	fill_n(countN, 1001, 0);
	int m;
	scanf("%d", &m);
	double temp;
	while (scanf("%lf", &temp) != EOF) {
		int plz = int(temp * m) / 1;
		countN[plz] = countN[plz] + 1;
	}
	for (int i = 0; i < m; i++) {
		printf("%d ", countN[i]);
	}
	return 0;
}
