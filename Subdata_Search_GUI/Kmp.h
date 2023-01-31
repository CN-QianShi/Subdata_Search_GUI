#pragma once
#include <fstream>

class Kmp
{
private:
    std::ifstream* pfin = nullptr;
    int fileLen;
    int offset;

    // scrStr�������ڴ�
    char* srcStr = nullptr;
    int srcLen;
    // matchStr��kmpNext�����ڴ�
    char* matchStr = nullptr;
    int matchLen;
    int* kmpNext = nullptr;
    int i, j;

    void generateNext(char*, int);
    int strSearching(int, int);
    int streamSearching(int, int);

public:
    // ����ģʽ����ԭ�������ҵ�һ������
    int run(char*, char*, int, int);
    // ͨ���Ѷ����ģʽ������ԭ������
    int run(char*, int);
    // ��������ģʽ����ԭ���е�����
    int run();

    // ����ģʽ����ԭ�������ҵ�һ������
    int frun(std::ifstream*, char*, int, int m_offset = 0, int m_fileLen = INT_MAX);
    // ͨ���Ѷ����ģʽ������ԭ������
    int frun(std::ifstream*, int m_offset = 0, int m_fileLen = INT_MAX);
    // ��������ģʽ����ԭ���е�����
    int frun();

    Kmp(const Kmp&);
    Kmp(char* match, int m_matchLen) { generateNext(match, m_matchLen); };
    ~Kmp()
    {
        if (kmpNext)
        {
            delete[] kmpNext;
            kmpNext = NULL;
        }
        if (matchStr)
        {
            delete[] matchStr;
            matchStr = NULL;
        }
    };
};

