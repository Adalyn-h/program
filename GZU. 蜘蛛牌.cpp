C - 蜘蛛牌 
                                         2018-04-17 0:10
蜘蛛牌是windows xp操作系统自带的一款纸牌游戏，游戏规则是这样的：只能
将牌拖到比她大一的牌上面（A最小，K最大），如果拖动的牌上有按顺序排好
的牌时，那么这些牌也跟着一起移动，游戏的目的是将所有的牌按同一花色从
小到大排好，为了简单起见，我们的游戏只有同一花色的10张牌，从A到10,
且随机的在一行上展开，编号从1到10，把第i号上的牌移到第j号牌上，移动
距离为abs(i-j)，现在你要做的是求出完成游戏的最小移动距离。 
Input
第一个输入数据是T，表示数据的组数。 
每组数据有一行，10个输入数据，数据的范围是[1,10]，分别表示A到10，我们
保证每组数据都是合法的。
Output
对应每组数据输出最小移动距离。
Sample Input
1
1 2 3 4 5 6 7 8 9 10
Sample Output
9

分析：这道题我开始想的是对数字的编号id进行搜索，id对应的数字满足条件即往下走，自我感觉思路清晰，写代码的时候就卡了。没有处理好“对应”这个关系，判断条件和递归的参数之间，对接不上。然后我改为对数操作，对应的id进行运算就要顺手一点了。深度搜索

代码：
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

const int maxn = 100 + 10;
int id[maxn];
int visited[maxn];
int dis,step;

void dfs(int x)
{
      for(int i = 1; i <= 10; i++){
            if(!visited[i]){
                  for(int j = i+1; j <= 10; j++) {
                          if(!visited[j]){
                               step += fabs(id[i]-id[j]);
                               if(dis > step){
                                      visited[i] = 1;
                                          dfs(x + 1);
                                          visited[i] = 0;
                                }
                                step -= fabs(id[j]-id[i]);
                                break;
                           }

                  }

            }
      }
      if(x == 10) {
            dis = step;return;}
}

int main()
{
     int t;
     scanf("%d", &t);
     while(t--){
         int x;
         for(int i = 1; i <= 10; i++){
              scanf("%d",&x);
              id[x] = i;
         }
         memset(visited, 0, sizeof(visited));
         dis = 0x3f3f3f;
         step = 0;
         dfs(1);
         printf("%d\n", dis);
     }
     return 0;
}
