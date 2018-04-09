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


�������������Ǹ��ַ�����ͳ�ƣ��ҵ�˼��ͬͳ��һ�����г��ִ�������Ԫ����ͬ����c++�У�����vector�����ַ����Ĳ�����Ч�����ƶ�ά�ַ����顣����һ���������飬����ÿ����Ԫ��0�������ַ����󣬴ӵ�һ���ַ�����ʼ��������ÿһ���ַ������бȽϣ�����ͬ����Ӧ�ļ�����Ԫ����1,ʱ�临�Ӷ�O(n^2)��Ȼ�󣬱����������飬�ҳ��������Ĵ�������Ӧ���ַ�����Ϊ�����ַ�����

���룺
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

