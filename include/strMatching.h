#pragma once
#ifndef STRMATCHING_H_
#define STRMATCHING_H_
#include <sstream>
#include <vector>

using std::string;
using std::stringstream;
using std::vector;

vector<int> GetNext(string &p); // 匹配子串的next数组生成函数

bool KmpSearch(string &s, string &p); // 字符串匹配算法kmp

string longltoString(long long); // 使用stringstream对long long类型进行转换，long long->string

#endif
