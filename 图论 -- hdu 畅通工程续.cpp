ͼ��

hdu ��ͨ������

ĳʡ�Դ�ʵ���˺ܶ���ĳ�ͨ���̼ƻ��������޽��˺ܶ�·������·����Ҳ���ã�ÿ��Ҫ��һ��������һ������ʱ����������ֵ�·��������ѡ�񣬶�ĳЩ����Ҫ����һЩ�������ߵľ���Ҫ�̺ܶࡣ�������˺����š� 

���ڣ���֪�����յ㣬��������Ҫ����㵽�յ㣬�����Ҫ���߶��پ��롣
Input
����Ŀ�����������ݣ��봦���ļ������� 
ÿ�����ݵ�һ�а�������������N��M(0<N<200,0<M<1000)���ֱ�������г������Ŀ�����޽��ĵ�·����Ŀ������ֱ���0��N-1��š� 
��������M�е�·��Ϣ��ÿһ������������A,B,X(0<=A,B<N,A!=B,0<X<10000),��ʾ����A�ͳ���B֮����һ������ΪX��˫���·�� 
�ٽ���һ������������S,T(0<=S,T<N)���ֱ���������յ㡣
Output
����ÿ�����ݣ�����һ������������Ҫ���ߵľ��롣��������ڴ�S��T��·�ߣ������-1. 
Sample Input
3 3
0 1 1
0 2 3
1 2 1
0 2
3 1
0 1 1
1 2
Sample Output
2
-1

������������ͼ����Ȩ��Ϊ��������֮��ĵ�·���ȡ���������ͼ�����ö�̬�滮��˼�룬Floyd�㷨������ѭ��kij���ҳ����յ�״̬



#include<cstdio>
#include<cstring>
using namespace std;

#define INF 0x3f3f3f
const int maxn = 200 + 10;
int G[maxn][maxn];
int n,m;

int Floyd(int s, int e)
{
     for(int k = 0; k < n; k++)
          for(int i = 0; i < n; i++)
             for(int j = 0; j < n; j++)
                     G[i][j] =min( G[i][j],G[i][k] + G[k][j]);//����
     if(G[s][e] != INF) return G[s][e];
     else  return -1;
}

void init(){
     for(int i = 0; i < n; i++)
          for(int j = 0; j < n; j++){
            if(i== j) G[i][j] = 0;
            else G[i][j] = INF;
          }
}

int main()
{
     while(scanf("%d%d", &n,&m) != EOF){
          init();
          int a, b,x;
          while(m--){
               scanf("%d%d%d", &a, &b, &x);
               if(x < G[a][b]) G[a][b] = G[b][a] = x;//˫��
          }
          int s,e;
          scanf("%d%d",&s,&e);
          int ans = Floyd(s,e);
          printf("%d\n", ans);
     }
     return 0;
}






















