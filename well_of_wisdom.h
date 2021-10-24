#ifndef __well_of_wisdom__
#define __well_of_wisdom__

//------------------------------------------------------------------------------
// well_of_wisdom.h 
//------------------------------------------------------------------------------

using namespace std;

#include "rnd.h"
#include <stdio.h>
#include <fstream>

//------------------------------------------------------------------------------
// �����, ������������ ��� ���� ����.
class Well_of_wisdom {
protected:
    static Random rnd3;
public:
    virtual ~Well_of_wisdom() {}

    // ���� ���������� �����.
    virtual void In(FILE* fl) = 0;

    static Well_of_wisdom* StaticIn(FILE* fl);

    // ��������� ���� ���������� �����.
    virtual void InRnd() = 0;

    static Well_of_wisdom* StaticInRnd();

    // ����� ���������� �����.
    virtual void Out(FILE* file) = 0;

    // ���������� �������� �� ���������� ������ ���������� �� ����� ������.
    virtual double Quotient() = 0;
};

#endif