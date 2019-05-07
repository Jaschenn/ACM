// ---------------------------------------------------------------------------- 一些头文件
#define _CRT_SBCURE_NO_DEPRECATE
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

const int maxn = 110;
const int INF = 0x3f3f3f3f;

// ---------------------------------------------------------------------------- 全排列函数
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int num[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    do
    {
        cout    << num[0] << " " << num[1] << " " << num[2] << " " << num[3] << " " << num[4] << " "
            << num[5] << " " << num[6] << " " << num[7] << endl;
    }
    while ( next_permutation( num, num + 8 ) ); /* 全排列函数 */

    return(0);
}
// ---------------------------------------------------------------------------- 有条件的全排列
/*
    |求1到n的全排列, 有条件|
    |16/11/05ztx, thanks to wangqiqi|
*/

void Pern(int list[], int k, int n) {   //  k表示前k个数不动仅移动后面n-k位数
    if (k == n - 1) {
        for (int i = 0; i < n; i++) {
            printf("%d", list[i]);
        }
        printf("\n");
    }else {
        for (int i = k; i < n; i++) {   //  输出的是满足移动条件所有全排列
            swap(list[k], list[i]);
            Pern(list, k + 1, n);
            swap(list[k], list[i]);
        }
    }
}

// ---------------------------------------------------------------------------- 快速筛选素数
/*
    |埃式筛法|
    |快速筛选素数|
    |16/11/05ztx|
*/

int prime[maxn];  
bool is_prime[maxn];

int sieve(int n){
    int p = 0;
    for(int i = 0; i <= n; ++i)
        is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i){   //  注意数组大小是n
        if(is_prime[i]){
            prime[p++] = i;
            for(int j = i + i; j <= n; j += i)  //  轻剪枝，j必定是i的倍数
                is_prime[j] = false;
        }
    }
    return p;   //  返回素数个数
}

// ---------------------------------------------------------------------------- 快速幂
/*
    |快速幂|
    |16/11/05ztx|
*/

typedef long long LL;   //  视数据大小的情况而定

LL powerMod(LL x, LL n, LL m)
{
    LL res = 1;
    while (n > 0){
        if  (n & 1) //  判断是否为奇数，若是则true
            res = (res * x) % m;
        x = (x * x) % m;
        n >>= 1;    //  相当于n /= 2;
    }
    return res;
}
// ---------------------------------------------------------------------------- 大数操作 start

// ---------------------------------------------------------------------------- 大数加法
/*
    |大数模拟加法|
    |用string模拟|
    |16/11/05ztx, thanks to caojiji|
*/

string add1(string s1, string s2)
{
    if (s1 == "" && s2 == "")   return "0";
    if (s1 == "")   return s2;
    if (s2 == "")   return s1;
    string maxx = s1, minn = s2;
    if (s1.length() < s2.length()){
        maxx = s2;
        minn = s1;
    }
    int a = maxx.length() - 1, b = minn.length() - 1;
    for (int i = b; i >= 0; --i){
        maxx[a--] += minn[i] - '0'; //  a一直在减 ， 额外还要减个'0'
    }
    for (int i = maxx.length()-1; i > 0;--i){
        if (maxx[i] > '9'){
            maxx[i] -= 10;//注意这个是减10
            maxx[i - 1]++;
        }
    }
    if (maxx[0] > '9'){
        maxx[0] -= 10;
        maxx = '1' + maxx;
    }
    return maxx;
}
// ---------------------------------------------------------------------------- 大数阶乘
/*
    |大数模拟阶乘|
    |用数组模拟|
    |16/12/02ztx|
*/

#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

const int maxn = 100010;

int num[maxn], len;

/*
    在mult函数中，形参部分：len每次调用函数都会发生改变，n表示每次要乘以的数，最终返回的是结果的长度
    tip: 阶乘都是先求之前的(n-1)!来求n!
    初始化Init函数很重要，不要落下
*/

void Init() {
    len = 1;
    num[0] = 1;
}

int mult(int num[], int len, int n) {
    LL tmp = 0;
    for(LL i = 0; i < len; ++i) {
         tmp = tmp + num[i] * n;    //从最低位开始，等号左边的tmp表示当前位，右边的tmp表示进位（之前进的位）
         num[i] = tmp % 10; //  保存在对应的数组位置，即去掉进位后的一位数
         tmp = tmp / 10;    //  取整用于再次循环,与n和下一个位置的乘积相加
    }
    while(tmp) {    //  之后的进位处理
         num[len++] = tmp % 10;
         tmp = tmp / 10;
    }
    return len;
}

int main() {
    Init();
    int n;
    n = 1977; // 求的阶乘数
    for(int i = 2; i <= n; ++i) {
        len = mult(num, len, i);
    }
    for(int i = len - 1; i >= 0; --i)
        printf("%d",num[i]);    //  从最高位依次输出,数据比较多采用printf输出
    printf("\n");
    return 0;
}

// ---------------------------------------------------------------------------- GCD 辗转相除（欧几里得） 求最大公约数
/*
    |辗转相除法|
    |欧几里得算法|
    |求最大公约数|
    |16/11/05ztx|
*/

int gcd(int big, int small)
{
    if (small > big) swap(big, small);
    int temp;
    while (small != 0){ //  辗转相除法
        if (small > big) swap(big, small);
        temp = big % small;
        big = small;
        small = temp;
    }
    return(big);
}

// ---------------------------------------------------------------------------- LCM 辗转相除 最小公倍数
/*
    |辗转相除法|
    |欧几里得算法|
    |求最小公倍数|
    |16/11/05ztx|
*/

int gcd(int big, int small)
{
    if (small > big) swap(big, small);
    int temp;
    while (small != 0){ //  辗转相除法
        if (small > big) swap(big, small);
        temp = big % small;
        big = small;
        small = temp;
    }
    return(big);
}
//// ---------------------------------------------------------------------------- 大数操作 end

// ---------------------------------------------------------------------------- 二分查找
/*
    |二分搜索|
    |要求：先排序|
    |16/11/05ztx, thanks to wangxiaocai|
*/

//  left为最开始元素, right是末尾元素的下一个数，x是要找的数
int bsearch(int *A, int left, int right, int x){
    int m;
    while (left < right){
        m = left + (right - left) / 2;
        if (A[m] >= x)  right = m;   else left = m + 1;    
        // 如果要替换为 upper_bound, 改为:if (A[m] <= v) x = m+1; else y = m;     
    }
    return left;
}

/*
    最后left == right  

    如果没有找到135577找6，返回7  

    如果找有多少的x，可以用lower_bound查找一遍，upper_bound查找一遍，下标相减  

    C++自带的lower_bound(a,a+n,x)返回数组中最后一个x的下一个数的地址 

    upper_bound(a,a+n,x)返回数组中第一个x的地址

    如果a+n内没有找到x或x的下一个地址，返回a+n的地址  

    lower_bound(a,a+n,x）-upper_bound(a,a+n,x)返回数组中x的个数
*/ 
