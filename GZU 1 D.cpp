D - Number Sequence

A number sequence is defined as follows: 

f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7. 

Given A, B, and n, you are to calculate the value of f(n). 
Input
The input consists of multiple test cases. Each test case contains 3 integers A, B and n on a single line (1 <= A, B <= 1000, 1 <= n <= 100,000,000). Three zeros signal the end of input and this test case is not to be processed. 
Output
For each test case, print the value of f(n) on a single line. 
Sample Input
1 1 3
1 2 10
0 0 0
Sample Output
2
5

分析：首先看数据范围，n的上限到了一亿，有点吓人，直接递归肯定是不行的，就算不炸也肯定会超时。再看给出的递归公式，有个mod7，可以猜测当数据足够大时，可能会出现周期性循环回到起点1。于是，我写了个递归来找周期，测试了很多的数据，这个出现偶然性的可能太大了。当然，可以使用程序自身找周期。

#include<iostream>
using namespace std;

const int maxn = 2000+10;
int f[maxn];

int recurse(int a, int b, int n)
{
    f[0] = 1;
    f[1] = 1;
    int t = 0;
    for(int i = 2; i <= n; i++){
        f[i] = (a * f[i-1] + b * f[i-2]) % 7;
         t++;
        if(f[i] == 1 && f[i-1] == 1)//当出现两个连续的1时，输出的一个1前的i
            cout << t <<' ';
        else continue;
    }
    cout << endl << f[n-1] << endl;
    return 0;
}

int main()
{
    int a, b, n;
    while(cin >> a >> b >> n){
        recurse(a, b, n);
        cout<<endl;
    }

    return 0;
}

发现在数据中,出现的为6的倍数，当测试数据较大，42，48出现的次数较多，测试多组数据比较发现，48为一个周期。接下的程序就比较好写了,n mod 周期 再进行运算就变小了，百分之百不超时。

#include<cstdio>
using namespace std;

const int maxn = 2000 + 10;
int f[maxn] = {0};

int main()
{
    int a, b, n;
    while(scanf("%d %d %d", &a, &b ,&n) != EOF){
        if((a == 0 && b == 0 && n == 0))
            break;
        else{
                while(n > 48)
                   n %=48;
                f[1] = 1;
                f[2] = 1;
                for(int i = 3; i <= n; i++)
                    f[i] = (a * f[i-1] + b * f[i-2]) % 7;

        }
        printf("%d\n", f[n]);
    }
   return 0;
}

 
