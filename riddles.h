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
// Загадка.
class Riddles : public Well_of_wisdom {
private:
    char *answer; // Ответ на загадку.
    char *riddle; // Загадка.
public:
    // Деструктор.
    virtual ~Riddles() {}
    // Ввод параметров загадки из файла.
    virtual void In(FILE* fl);

    // Случайный ввод параметров загадки.
    virtual void InRnd();

    // Вывод параметров загадки в форматируемый поток.
    virtual void Out(FILE* file);

    // Вычисление частного от количества знаков препинания в загадке на длину этой загадки.
    virtual double Quotient();
};

#endif //__riddles__
