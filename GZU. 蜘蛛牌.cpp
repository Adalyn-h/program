C - ֩���� 
                                         2018-04-17 0:10
֩������windows xp����ϵͳ�Դ���һ��ֽ����Ϸ����Ϸ�����������ģ�ֻ��
�����ϵ�������һ�������棨A��С��K��󣩣�����϶��������а�˳���ź�
����ʱ����ô��Щ��Ҳ����һ���ƶ�����Ϸ��Ŀ���ǽ����е��ư�ͬһ��ɫ��
С�����źã�Ϊ�˼���������ǵ���Ϸֻ��ͬһ��ɫ��10���ƣ���A��10,
���������һ����չ������Ŵ�1��10���ѵ�i���ϵ����Ƶ���j�����ϣ��ƶ�
����Ϊabs(i-j)��������Ҫ��������������Ϸ����С�ƶ����롣 
Input
��һ������������T����ʾ���ݵ������� 
ÿ��������һ�У�10���������ݣ����ݵķ�Χ��[1,10]���ֱ��ʾA��10������
��֤ÿ�����ݶ��ǺϷ��ġ�
Output
��Ӧÿ�����������С�ƶ����롣
Sample Input
1
1 2 3 4 5 6 7 8 9 10
Sample Output
9

������������ҿ�ʼ����Ƕ����ֵı��id����������id��Ӧ���������������������ߣ����Ҹо�˼·������д�����ʱ��Ϳ��ˡ�û�д���á���Ӧ�������ϵ���ж������͵ݹ�Ĳ���֮�䣬�ԽӲ��ϡ�Ȼ���Ҹ�Ϊ������������Ӧ��id���������Ҫ˳��һ���ˡ��������

���룺
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
