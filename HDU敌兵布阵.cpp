H - �б�����

Input
��һ��һ������T����ʾ��T�����ݡ� 
ÿ�����ݵ�һ��һ��������N��N<=50000��,��ʾ������N������Ӫ�أ���������N��������,��i��������ai�����i������Ӫ���￪ʼʱ��ai���ˣ�1<=ai<=50���� 
������ÿ����һ�����������4����ʽ�� 
(1) Add i j,i��jΪ������,��ʾ��i��Ӫ������j���ˣ�j������30�� 
(2)Sub i j ,i��jΪ������,��ʾ��i��Ӫ�ؼ���j���ˣ�j������30��; 
(3)Query i j ,i��jΪ������,i<=j����ʾѯ�ʵ�i����j��Ӫ�ص�������; 
(4)End ��ʾ����������������ÿ������������; 
ÿ�����������40000������ 
Output
�Ե�i������,���������Case i:���ͻس�, 
����ÿ��Queryѯ�ʣ����һ���������س�,��ʾѯ�ʵĶ��е�������,�����������int���ڡ� 
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

����������һ���߶����ĵ����ѯ���⡣

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define lson x<<1 //�궨�����Ҷ���
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
