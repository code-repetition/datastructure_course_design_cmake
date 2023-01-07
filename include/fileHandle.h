#pragma once
#ifndef FILEHANDLE_H
#define FILEHANDLE_H
#include <fstream>
#include <sstream>
#include <vector>
#include "Student.h"

using std::ifstream;
using std::stringstream;
using std::vector;

int getDataNum(); // 用于从文件中获取记录个数，已弃用

void loadInfo(vector<Student> &stus); // 从文件读取学生信息

void globalSave(const vector<Student> &); // 从vector直接向文件存储，初期用于测试,已弃用

void spawnStatistics(); // 已弃用函数

#endif
