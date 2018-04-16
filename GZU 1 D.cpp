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

���������ȿ����ݷ�Χ��n�����޵���һ�ڣ��е����ˣ�ֱ�ӵݹ�϶��ǲ��еģ����㲻ըҲ�϶��ᳬʱ���ٿ������ĵݹ鹫ʽ���и�mod7�����Բ²⵱�����㹻��ʱ�����ܻ����������ѭ���ص����1�����ǣ���д�˸��ݹ��������ڣ������˺ܶ�����ݣ��������żȻ�ԵĿ���̫���ˡ���Ȼ������ʹ�ó������������ڡ�

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
        if(f[i] == 1 && f[i-1] == 1)//����������������1ʱ�������һ��1ǰ��i
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

������������,���ֵ�Ϊ6�ı��������������ݽϴ�42��48���ֵĴ����϶࣬���Զ������ݱȽϷ��֣�48Ϊһ�����ڡ����µĳ���ͱȽϺ�д��,n mod ���� �ٽ�������ͱ�С�ˣ��ٷ�֮�ٲ���ʱ��

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

 
