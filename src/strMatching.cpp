#include "strMatching.h"

vector<int> GetNext(string &p) // 由模式串生成next数组
{
	int pLen = p.size();
	vector<int> next(pLen, 0);
	next[0] = -1; // 设置next[0]
	int k = -1;
	int j = 0; // j遍历p，k记录p[j]之前与p开头相同字符个数
	while (j < pLen - 1)
	{
		// p[k]表示前缀，p[j]表示后缀
		if (k == -1 || p[j] == p[k]) // k为-1或比较字符相等时
		{
			++k;
			++j;		 // j、k移动到下一个字符
			next[j] = k; // 设置next[j]为k
		}
		else // 找不到可匹配的子串
		{
			k = next[k]; // k回退
		}
	}
	return next;
}

bool KmpSearch(string &s, string &p)
{
	int i = 0;
	int j = 0;
	int sLen = s.size();
	int pLen = p.size();
	vector<int> next = GetNext(p);
	while (i < sLen && j < pLen)
	{
		// 如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			// 如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]
			// next[j]即为j所对应的next值
			j = next[j];
		}
	}
	if (j == pLen)
		return true;
	else
		return false;
}

string longltoString(long long l) // 将long long转换为string
{
	string result;
	stringstream ss;
	ss << l;	  // 将long long类型的学生学号写入流中
	ss >> result; // 从流中转换
	return result;
}