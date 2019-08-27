#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

/*
一个字符串S是偶串当且仅当S中的每一个字符都出现了偶数次。
如字符串”aabccb”是一个偶串，因为字符a,b,c都出现了两次。
而字符串”abbcc”不是偶串，因为字符a出现了一次。
现在给出一个长度为n的字符串T=t1,t2,t3,…,tn。字符串的子串为其中任意连续一段。
T长度为1的子串有n个，长度为2的子串有n-1个，以此类推，T一共有n(n+1)/2个子串。
给定T，你能算出它有多少个子串是偶串吗？

输入
输入一个字符串T，T中只有小写字母。T的长度不超过100000。
输出
输出一个数，T的所有子串中偶串的个数。

样例输入
abbc
样例输出
1

解题思路
参考官方思路。这题一看就较为复杂，暴力算法检索所有子串，判断为否为偶串时间复杂度太高。
先从简单的问题入手，如果给你一个子串，怎么样判断是否为偶串呢？其实我们并不在乎字母具体出现次数，
只要知道出现的奇偶就可以。那这样的话，我们可以考虑用26bit的数来代表一个子串的字母出现次数奇偶的状态，
每一位对于着26个字母里的位数。统计结果如果为零（即都为偶数个）则是偶串。
对于字符串中随意一段子串呢，若起始点分别为L，R。
F代表从0点开始的状态函数(理论上2^25种)，则当F（R）=F（L-1）时，
即R，L-1点处的状态相同时（异或判断），这[L,R]是偶串。这样的话，我们可以遍历字符串，
记录不同状态出现的次数（状态太多使用map）。统计完后，对于不同状态出现的次数（假设为n次），
那么这种状态下的偶串次数可以轻易得到1+2+…+（n-1）。
其实，在代码编写中可以把偶串计算次数融合到状态统计过程中去。

重点是：用26位表示不同状态，状态对于偶串的影响，以及计算状态后偶串数量。编码不难，思路重要。
*/

int main1502431515316654134515410235102(void)
{
	string data;
	cin >> data;
	map<int, int> mp;
	mp[0] = 1;//初始状态，26个字母全为偶数次状态为1
	int status = 0;
	long long res = 0;
	for (int i = 0; i < data.size(); i++) 
	{
		int x = data[i] - 'a';
		int y = (1 << x); // 将1左移x位，所以是'a'时，'a'其实对应的是状态1.
		status ^= y; // 按位异或
		// 若key（status）不存在,则会插入<key, 0>
		res += mp[status];//这句很好，每种状态下的偶串累加。思考时可以把这行代码省略，想通后累加部分通过这句实现。
		mp[status]++;//统计不同状态出现的次数
	}
	cout << res << endl;

	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}