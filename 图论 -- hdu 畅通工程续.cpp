图论

hdu 畅通工程续

某省自从实行了很多年的畅通工程计划后，终于修建了很多路。不过路多了也不好，每次要从一个城镇到另一个城镇时，都有许多种道路方案可以选择，而某些方案要比另一些方案行走的距离要短很多。这让行人很困扰。 

现在，已知起点和终点，请你计算出要从起点到终点，最短需要行走多少距离。
Input
本题目包含多组数据，请处理到文件结束。 
每组数据第一行包含两个正整数N和M(0<N<200,0<M<1000)，分别代表现有城镇的数目和已修建的道路的数目。城镇分别以0～N-1编号。 
接下来是M行道路信息。每一行有三个整数A,B,X(0<=A,B<N,A!=B,0<X<10000),表示城镇A和城镇B之间有一条长度为X的双向道路。 
再接下一行有两个整数S,T(0<=S,T<N)，分别代表起点和终点。
Output
对于每组数据，请在一行里输出最短需要行走的距离。如果不存在从S到T的路线，就输出-1. 
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

分析：建无向图，边权即为两个城镇之间的道路长度。从起点遍历图，采用动态规划的思想，Floyd算法，三重循环kij，找出最终的状态



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
                     G[i][j] =min( G[i][j],G[i][k] + G[k][j]);//更新
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
               if(x < G[a][b]) G[a][b] = G[b][a] = x;//双向
          }
          int s,e;
          scanf("%d%d",&s,&e);
          int ans = Floyd(s,e);
          printf("%d\n", ans);
     }
     return 0;
}






















