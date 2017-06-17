#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1000005
#define R 78500
int factor[N];
int bit[2][R + 5];
int reversed_num[R + 5];

int top = 1;
int num,cnt;
int query(int b, int i) {
    int ret = 0;
    while (i > 0) {
        ret += bit[b][i];
        i -= i & -i;
    }
    return ret;
}
void update(int b, int i, int val) {
    while (i <= R) {
        bit[b][i] += val;
        i += i & -i;
    }
}
int factor_sum(int i) {
    int sum = 0;
    int j = 2;
    while (i >= N) {
        while (i % j == 0) {
            i /= j;
            sum++;
        }
        j++;
    }
    while (i > 1) {
        sum++;
        i /= factor[i];
    }
    return sum;
}
int reverse(int i) {
    int seven = 7;
    int tmp = 0;
    while (seven--) {
        tmp = tmp * 10 + i % 10;
        i /= 10;
    }
    return tmp;
}
void init() {
    for(int i=0;i<N;i++) factor[i]=0;
    int i,j;
    factor[0] = factor[1] = -1;
    for (i = 2; i * i < N; i++)
        if (!factor[i])
            for (j = i * i; j < N; j += i)
                factor[j] = i;
    for (i = 2; i < N; i++)
    	if(factor[i]==0) factor[i]=i;

        cnt=num = 0;
    for (int i = 0; i < 1000000; i++)
        if (factor[i] == i) {
            reversed_num[cnt + 1] = reverse(i);
            cnt++;
        }
    top = cnt;
    sort(reversed_num + 1, reversed_num + cnt + 1);
    for (int i = 0; i < R; i++)
        bit[0][i] = bit[1][i] = 0;
    for (int i = 1; i <= cnt; i++) {
        update(0, i, factor_sum(reversed_num[i]));
        update(1, i, 1);
    }
}

int bitset1(int t) {
    int l = 1, h = top;
    while (h > l) {
        int m = (l + h) / 2;
        if (reversed_num[m] >= t)
            h = m;
        else
            l = m + 1;
    }
    return h;
}
int bitset2(int t) {
    int l = 1;
    int h = top;
    while (h > l) {
        int m = (l + h) / 2;
        if (query(1, m) >= t)
            h = m;
        else
            l = m+ 1;
    }
    return h;
}
int main() {
    init();
    char str[10];
    int n;
    while (scanf("%s %d", str, &n) != EOF)
        if (str[0] == 'd')
            {

            int k = bitset1(n);
            update(0, k, -1 * factor_sum(n));
            update(1, k, -1);
            }
        else {
            
            printf("%d\n", query(0, bitset2(n + 1)));
        }
    return 0;
}
