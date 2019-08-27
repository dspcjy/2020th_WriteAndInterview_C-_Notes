#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/*
小明和小红采用密码加密通信，每次通信有固定的明文长度n和加密次数k。
比如：密码二进制明文是1001010，加密次数是4，则每次将密文右移1位与明文做异或操作，总共位移3次（k=4, 所以k - 1 = 3）
输入：
7 4 // n k
1110100110 //密文
输出：
1001010 //明文

解释：
1001010---
-1001010--
--1001010-
---1001010
加密次数为4，故对于明文右移4-1=3轮，每轮与当前密文进行一次异或，故1001010对应密文为1110100110

思路（100/100分）：一道标准的异或数学题，不知道该怎么归类，有一点考数学的感觉，看几眼就能看出规律了直接上代码
简单讲一下思路：
首先密文和明文第1位是一样的，看一下上方样例里的解释就懂了。
然后考虑第2到k-1位，可以发现这一段的每一位都是由前一位密文的异或结果再与当前位明文异或得到的。
接下来考虑第k到n-1位，观察规律可以发现这一段的每一位都是由前一位密文与第i-k位明文异或得到的结果再与当前位明文异或得到的。
如何消除异或影响大家应该都能理解，因此只要把参与异或的部分再与密文异或一下即可得到明文。
*/

int main_12123445(void)
{
	int n, k, tmp;
	string s, ans = "";
	cin >> n >> k;
	cin >> s;
	ans += s[0]; // 首先密文和明文第0位是一样的
	for (int i = 1; i < k; i++) // 前k-1个
	{
		tmp = (int)(s[i] - '0') ^ (int)(s[i - 1] - '0'); // 只要把参与异或的部分再与密文异或一下即可得到明文。
		ans += (tmp + '0');
	}
	for (int i = k; i < n; i++) // 后n-k个
	{
		ans += (int)(s[i] - '0') ^ (int)(s[i - 1] - '0') ^ (int)(ans[i - k] - '0') + '0';
	}
	cout << ans;
	return 0;
}