#ifndef __proverbs__
#define __proverbs__

//------------------------------------------------------------------------------
// proverbs.h 
//------------------------------------------------------------------------------

#include <stdio.h>
using namespace std;

#include "rnd.h"
#include "Well_of_wisdom.h"

//------------------------------------------------------------------------------
// ���������.
class Proverbs : public Well_of_wisdom {
private:
    char *country; // ������ ���������.
    char *proverb;
public:
    // ����������.
    virtual ~Proverbs() {}
    // ���� ���������� ��������� �� �����.
    virtual void In(FILE* fl);

    // ��������� ���� ���������� ���������.
    virtual void InRnd();

    // ����� ���������� ��������� � ������������� �����.
    virtual void Out(FILE* file);

    // ���������� �������� �� ���������� ������ ���������� � ��������� �� ����� ���� ���������.
    virtual double Quotient();
};

#endif //__proverbs__
