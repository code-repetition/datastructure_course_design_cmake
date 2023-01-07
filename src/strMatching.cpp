#include "strMatching.h"

vector<int> GetNext(string &p) // ��ģʽ������next����
{
	int pLen = p.size();
	vector<int> next(pLen, 0);
	next[0] = -1; // ����next[0]
	int k = -1;
	int j = 0; // j����p��k��¼p[j]֮ǰ��p��ͷ��ͬ�ַ�����
	while (j < pLen - 1)
	{
		// p[k]��ʾǰ׺��p[j]��ʾ��׺
		if (k == -1 || p[j] == p[k]) // kΪ-1��Ƚ��ַ����ʱ
		{
			++k;
			++j;		 // j��k�ƶ�����һ���ַ�
			next[j] = k; // ����next[j]Ϊk
		}
		else // �Ҳ�����ƥ����Ӵ�
		{
			k = next[k]; // k����
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
		// ���j = -1�����ߵ�ǰ�ַ�ƥ��ɹ�����S[i] == P[j]��������i++��j++
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			// ���j != -1���ҵ�ǰ�ַ�ƥ��ʧ�ܣ���S[i] != P[j]�������� i ���䣬j = next[j]
			// next[j]��Ϊj����Ӧ��nextֵ
			j = next[j];
		}
	}
	if (j == pLen)
		return true;
	else
		return false;
}

string longltoString(long long l) // ��long longת��Ϊstring
{
	string result;
	stringstream ss;
	ss << l;	  // ��long long���͵�ѧ��ѧ��д������
	ss >> result; // ������ת��
	return result;
}