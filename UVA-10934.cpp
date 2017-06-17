#include <cstdio>
typedef long long ll;
int main() {
    int i, j;
    ll dp[101][64], n, k;
    for(i = 1; i <= 100; i++) {
        for(j = 1; j < 64; j++) {
            if(j == 1)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j-1]+dp[i][j-1]+1;
        }
    }
    while(scanf("%lld %lld", &k, &n) == 2 && k) {
        for(i = 1; i < 64; i++) {
            if(dp[k][i] >= n)
                break;
        }
        if(i > 63)
            printf("More than 63 trials needed.\n");
        else
            printf("%d\n", i);
    }
    return 0;
}
