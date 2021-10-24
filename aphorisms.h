#ifndef __aphorisms__
#define __aphorisms__

//------------------------------------------------------------------------------
// aphorisms.h
//------------------------------------------------------------------------------

#include <stdio.h>
using namespace std;

#include "rnd.h"
#include "Well_of_wisdom.h"
#include <fstream>

//------------------------------------------------------------------------------
// �������.
class Aphorisms : public Well_of_wisdom {
private:
    char *author; // �����.
    char *aphorism;
public:
    // ����������.
    virtual ~Aphorisms() {}
    // ���� ���������� �������� �� �����.
    virtual void In(FILE* fl);

    // ��������� ���� ���������� ��������.
    virtual void InRnd();

    // ����� ���������� �������� � ������������� �����.
    virtual void Out(FILE* file);

    // ���������� �������� �� ���������� ������ ���������� � �������� �� ����� ��������.
    virtual double Quotient();
};

#endif //__aphorisms__
