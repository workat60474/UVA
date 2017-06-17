#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#define N 1000005 
long long sum[N << 2], value[N << 2];  
int lc(int i){return 2*i;}
int rc(int i){return 2*i+1;}

  
void push_down(int l, int r, int i)  
{  
    if(value[i])  
    {  
        sum[lc(i)] += (long long)l * value[i];  
        sum[rc(i)] += (long long)r * value[i];  
        value[lc(i)] += value[i];  
        value[rc(i)] += value[i];  
        value[i] = 0;  
    }  
    return;  
}  
  
void build(int l, int r, int i)  
{  
    value[i] = 0;  
    if(l == r)  
    {  
        scanf("%lld", &sum[i]);  
        return;  
    }  
    int m= (l + r) >> 1;  
    build(l, m, lc(i) );  
    build(m+ 1, r, rc(i));  
    sum[i] = sum[lc(i)] + sum[rc(i)];  
    return;  
}  
  
void update(int l, int r, int i ,int x1, int x2,int n)  
{  
    if(x1 <= l && r <= x2)  
    {  
        sum[i] += (r - l + 1) * n;  
        value[i] += n;  
        return;  
    }  
    int m = (l + r) >> 1;  
    push_down(m - l + 1, r - m, i);  
    if(x1<= m)  
        update(l, m, lc(i),x1,x2,n );  
    if(x2> m)  
        update(m+ 1, r, rc(i),x1,x2,n);  
    sum[i] = sum[lc(i)] + sum[rc(i)];   
    return;  
}  
  
long long query(int l, int r, int i,int x1, int x2 )  
{  
    if(x1 <= l && r <= x2)  
        return sum[i];  
    int m = (l + r) /2;  
    push_down(m- l + 1, r - m, i);  
    long long ans = 0;  
    if(x1 <= m)  
        ans += query(l, m, lc(i),x1,x2 );  
    if(x2 > m)  
        ans += query(m+ 1, r, rc(i),x1,x2);  
    return ans;  
}  
  
int main()  
{  
    int n, m;  
    int a,b,c;
    scanf("%d %d", &n, &m);  
    build(1, n, 1);  
    while(m --)  
    {  
        char str[2];  
        scanf("%s", str);  
        if(str[0] == 'C')  
        {  
            
            scanf("%d %d %d", &a, &b, &c);  
            update(1, n, 1,a,b,c);  
        }  
        else   
        {  
             scanf("%d %d", &a, &b);  
            printf("%lld\n", query(1, n, 1,a,b)); 
            
        }  
    }  
}  