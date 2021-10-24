#ifndef __riddles__
#define __riddles__

//------------------------------------------------------------------------------
// riddles.h
//------------------------------------------------------------------------------

#include <stdio.h>
using namespace std;

#include "rnd.h"
#include "Well_of_wisdom.h"

//------------------------------------------------------------------------------
// �������.
class Riddles : public Well_of_wisdom {
private:
    char *answer; // ����� �� �������.
    char *riddle; // �������.
public:
    // ����������.
    virtual ~Riddles() {}
    // ���� ���������� ������� �� �����.
    virtual void In(FILE* fl);

    // ��������� ���� ���������� �������.
    virtual void InRnd();

    // ����� ���������� ������� � ������������� �����.
    virtual void Out(FILE* file);

    // ���������� �������� �� ���������� ������ ���������� � ������� �� ����� ���� �������.
    virtual double Quotient();
};

#endif //__riddles__
