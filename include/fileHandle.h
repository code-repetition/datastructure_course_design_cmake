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

int getDataNum(); // ���ڴ��ļ��л�ȡ��¼������������

void loadInfo(vector<Student> &stus); // ���ļ���ȡѧ����Ϣ

void globalSave(const vector<Student> &); // ��vectorֱ�����ļ��洢���������ڲ���,������

void spawnStatistics(); // �����ú���

#endif
