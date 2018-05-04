HDU just hook
The input consists of several test cases. The first line of the input is the number of the cases. There are no more than 10 cases. 
For each case, the first line contains an integer N, 1<=N<=100,000, which is the number of the sticks of Pudge’s meat hook and second line contains an integer Q, 0<=Q<=100,000, which is the number of the operations. 
Next Q lines, each line contains three integers X, Y, 1<=X<=Y<=N, Z, 1<=Z<=3, which defines an operation: change the sticks numbered from X to Y into the metal kind Z, where Z=1 represents the cupreous kind, Z=2 represents the silver kind and Z=3 represents the golden kind. 
Output
For each case, print a number in a line representing the total value of the hook after the operations. Use the format in the example. 
Sample Input
1
10
2
1 5 2
5 9 3
Sample Output
Case 1: The total value of the hook is 24.


线段树的区间更新。在单点更新的基础上，把维护对象换成一段，标记延迟。


代码：
#include<cstdio>
using namespace std;

#define lson x << 1
#define rson x << 1 | 1
const int maxn = 100000 + 5;
int tree[maxn<<2];
int lab[maxn<<2];
int t,n,m;

void pushdown(int x, int len)
{
     if(lab[x]){
          lab[lson] = lab[rson] = lab[x];
          tree[lson] = lab[x] * (len - (len >> 1));
          tree[rson] = lab[x] * (len>>1);
          lab[x] = 0;
     }
}

void build(int x, int l, int r)
{
     lab[x] = 0;tree[x] = 1;
     if(l == r) return;
     int mid = (l + r) >> 1;
     build(lson, l, mid);
     build(rson, mid+1, r);
     tree[x] = tree[lson] + tree[rson];
}

void update( int x, int l, int r, int a, int b, int val)
{
     if(a <= l && b >= r){lab[x] = val; tree[x] = val * (r - l + 1); return;}
     pushdown(x, r-l+1);
     int mid = (l + r) >> 1;
     if(a <= mid) update(lson, l, mid,a, b, val);
     if(b > mid) update(rson, mid+1,r,a, b, val);
     tree[x] = tree[lson] + tree[rson];
}

int main()
{
     scanf("%d", &t);
     for(int i = 1; i <= t; i++){
          scanf("%d%d", &n, &m);
          build(1,1,n);
          int a,b,c;
          while(m--){
               scanf("%d%d%d", &a, &b, &c);
               update(1,1,n,a,b,c);
          }
          printf("Case %d: The total value of the hook is %d.\n",i , tree[1]);
     }
     return 0;
}
