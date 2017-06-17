#include <cstdio>
#include <algorithm>
#include <iostream>
#include<cstring>
#define MX 111111
#define N 111111
using namespace std;
int val[N], sum[N<< 2], tmp[111], tmp2[111];

void build(int l, int r, int i)
{
    if (l == r)
    {
        scanf("%d", &val[l]);
        sum[i] = val[l];
        return;
    }
    int m = (l + r) >> 1;
    build(l,m,2*i);
    build(m+1,r,2*i+1);
   sum[i] = min(sum[2*i], sum[1+2*i]);
}
void update(int x, int v, int l, int r, int i)
{
    if (l == r)
    {
        val[l] = sum[i] = v;
        return;
    }
    int m = (l + r)/2;
    if (x <= m)
        update(x, v, l,m,2*i);
    else update(x, v,m+1,r,2*i+1);
    sum[i] = min(sum[2*i], sum[1+2*i]);
}
int query(int X1, int X2, int l, int r, int i)
{
    if (X1 <= l && r <= X2)
        return sum[i];
    int total = MX, m = (l + r)/2;
    if (X1 <= m)
        total = min(total, query(X1, X2,l,m,2*i));
    if (m < X2)
        total = min(total, query(X1, X2,m+1,r,2*i+1));
    return total;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    build(1, n, 1);
    char op[111];
    while (m--)
    {
        scanf("%s", op);
        int k = 0, len = strlen(op);
        tmp[0] = 0;
        for (int i = 6; i < len; ++i)
            if (isdigit(op[i]))
                tmp[k] = tmp[k] * 10 + op[i] - '0';
            else tmp[++k] = 0;
        if (op[0] == 's')
          {  

            for (int i = 0; i < k; ++i)
                tmp2[i] = val[tmp[i]];
            for (int i = 0; i < k; ++i)
                update(tmp[i], tmp2[(i + 1) % k], 1, n, 1);
        }
        else
        {
                int ans=query(tmp[0], tmp[1], 1, n, 1);
            printf("%d\n",ans);
        }
    }
    return 0;
}
