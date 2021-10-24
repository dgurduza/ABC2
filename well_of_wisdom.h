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
// Класс, объединяющий все виды фраз.
class Well_of_wisdom {
protected:
    static Random rnd3;
public:
    virtual ~Well_of_wisdom() {}

    // Ввод обобщенной фразы.
    virtual void In(FILE* fl) = 0;

    static Well_of_wisdom* StaticIn(FILE* fl);

    // Случайный ввод обобщенной фразы.
    virtual void InRnd() = 0;

    static Well_of_wisdom* StaticInRnd();

    // Вывод обобщенной фразы.
    virtual void Out(FILE* file) = 0;

    // Вычисление частного от количества знаков препинания на длину строки.
    virtual double Quotient() = 0;
};

#endif