��ֻ����
����չŷ�����
������
��ֻ����ͬ����һԲ����׷������ʼֻ�뵽ȡ����Ҫ��ŷ������㷨���轫��ֻ����֮��Ĺ�ϵ����һ�¡��������Ϊt��׷������Ϊd����������ʱ�У�
x + mt + d = y + nt��d = kl��
x - y + (n-m)t = -d;
x - yΪ��������m-n)t + kl = -��x-y����

���룺
#include <iostream>
using namespace std;
typedef long long ll;

ll a, b,x,y, m, n, L;
ll exgcd( ll a, ll b, ll &x, ll &y ) 
{
     ll ans temp;
    if ( b == 0 ) {
        x = 1;
        y = 0;
        return a;
    }
    ans =  exgcd(b, a%b, x, y);
    temp = x;
    x = y;
    y = temp-a/b*y;
    return ans;
}

ll solve( ll a, ll b, ll c ) 
{
    ll d = exgcd(a, b, x, y);
    if ( c % d ) return -1;
    x = x * c / d;
    y = y * c / d;
    x = (x % b + b) % b;
    return x;
}
int main() {
    while(cin >> a >> b >> m >> n >> L){
    if ( solv(n-m, L, a-b) != -1 )
        cout << solve(n-m, L, a-b) << endl;
    else 
        cout << "Impossible" << endl;
    }
    return 0; 
} 