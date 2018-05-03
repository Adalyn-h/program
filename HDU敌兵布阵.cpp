H - 敌兵布阵

Input
第一行一个整数T，表示有T组数据。 
每组数据第一行一个正整数N（N<=50000）,表示敌人有N个工兵营地，接下来有N个正整数,第i个正整数ai代表第i个工兵营地里开始时有ai个人（1<=ai<=50）。 
接下来每行有一条命令，命令有4种形式： 
(1) Add i j,i和j为正整数,表示第i个营地增加j个人（j不超过30） 
(2)Sub i j ,i和j为正整数,表示第i个营地减少j个人（j不超过30）; 
(3)Query i j ,i和j为正整数,i<=j，表示询问第i到第j个营地的总人数; 
(4)End 表示结束，这条命令在每组数据最后出现; 
每组数据最多有40000条命令 
Output
对第i组数据,首先输出“Case i:”和回车, 
对于每个Query询问，输出一个整数并回车,表示询问的段中的总人数,这个数保持在int以内。 
Sample Input
1
10
1 2 3 4 5 6 7 8 9 10
Query 1 3
Add 3 6
Query 2 7
Sub 10 2
Add 6 3
Query 3 10
End 
Sample Output
Case 1:
6
33
59

分析：这是一道线段树的单点查询问题。

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define lson x<<1 //宏定义左右儿子
#define rson x<<1|1
const int maxn = 50000 + 10;
int tree[maxn<<2];
int arr[maxn];

void build(int x,int l,int r)
{
     if(l == r){
          tree[x] = arr[l];return;
     }
     int mid = (l + r)/2;
     build(lson, l, mid);
     build(rson,mid+1, r);
     tree[x] = tree[lson] + tree[rson];
}

void update(int x,int l,int r,int pos,int val)
{
     if(l == r){tree[x] += val; return;}
     int mid = (l + r)/2;
     if(pos <= mid) update(lson, l, mid, pos, val);
     if(pos > mid) update(rson,mid+1,r,pos,val);
     tree[x] = tree[lson] + tree[rson];
}

int ask(int x, int l, int r, int a, int b)
{
     if(a <= l && b >= r) return tree[x];
     int mid = (l + r)/2;
     int ans = 0;
     if(a <= mid) ans += ask(lson,l,mid,a,b);
     if(b > mid) ans += ask(rson,mid+1,r,a,b);
     return ans;
}

int main()
{
     int t,n,a,b;
     char ch[10];
     scanf("%d", &t);
     for(int i = 1; i <= t; i++){
          printf("Case %d:\n",i);
          scanf("%d",&n);
          for(int j = 1; j <= n; j++)
               scanf("%d",&arr[j]);
          build(1,1,n);
          while(scanf("%s",ch) != EOF){
               if(ch[0] == 'E') break;
               scanf("%d%d",&a,&b);
               if(ch[0] == 'Q')
                    printf("%d\n",ask(1,1,n,a,b));
               if(ch[0] =='A')
                    update(1,1,n,a,b);
               if(ch[0] == 'S')
                    update(1,1,n,a,-b);
          }
     }
     return 0;
}
