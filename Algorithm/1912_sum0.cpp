#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100001], dp[100001], result = -987654321;

int main() {
   cin >> n;

   for (int i = 1; i <= n; i++) {
      cin >> arr[i];
   }

   dp[0] = 0;
   result = arr[1];

   for (int i = 1; i <= n; i++) {
      if (arr[i] + dp[i - 1] > 0)
         dp[i] = arr[i] + dp[i - 1];
      else
         dp[i] = arr[i];
      result = max(result, dp[i]);
   }

   cout << result << endl;

   return 0;
}
