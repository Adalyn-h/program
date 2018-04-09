C - Let the Balloon Rise 

Contest time again! How excited it is to see balloons floating around. But to tell you a secret, the judges' favorite time is guessing the most popular problem. When the contest is over, they will count the balloons of each color and find the result.

This year, they decide to leave this lovely job to you. 
Input
Input contains multiple test cases. Each test case starts with a number N (0 < N <= 1000) -- the total number of balloons distributed. The next N lines contain one color each. The color of a balloon is a string of up to 15 lower-case letters. 

A test case with N = 0 terminates the input and this test case is not to be processed. 
Output
For each case, print the color of balloon for the most popular problem on a single line. It is guaranteed that there is a unique solution for each test case. 
Sample Input
5
green
red
blue
red
red
3
pink
orange
pink
0
Sample Output
red
pink


分析：这道题就是个字符串的统计，我的思想同统计一列数中出现次数最多的元素相同。在c++中，可用vector进行字符串的操作，效果类似二维字符数组。定义一个计数数组，将其每个单元置0。输入字符串后，从第一个字符串开始，与其后的每一个字符串进行比较，若相同，对应的计数单元增加1,时间复杂度O(n^2)。然后，遍历计数数组，找出其中最大的次数，对应的字符串即为所求字符串。

代码：
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

const int maxn=2000+10;
int cnt[maxn];
vector<string>v;
string s;

int main()
{
    int n;
    while(scanf("%d",&n) != EOF){
        memset(cnt, 0, sizeof(cnt));
        v.clear();
        if(n == 0)
            break;
        else{
            for(int i = 0;i < n; i++){
                cin>>s;
               v.push_back(s);
            }
            for(int i = 0; i < n-1; i++)
                for(int j = i+1; j < n; j++){
                    if(v[i] == v[j])
                        cnt[i]++;
                }
            int maxc = cnt[0];
            for(int i = 1; i < n; i++){
                if(maxc < cnt[i])
                    maxc = cnt[i];
            }
            for(int i = 0; i < n; i++){
                if(maxc == cnt[i])
                   cout << v[i] << endl;
            }
        }

    }
    return 0;
}

