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
// Пословица.
class Proverbs : public Well_of_wisdom {
private:
    char *country; // Страна пословицы.
    char *proverb;
public:
    // Деструктор.
    virtual ~Proverbs() {}
    // Ввод параметров пословицы из файла.
    virtual void In(FILE* fl);

    // Случайный ввод параметров пословицы.
    virtual void InRnd();

    // Вывод параметров пословицы в форматируемый поток.
    virtual void Out(FILE* file);

    // Вычисление частного от количества знаков препинания в пословице на длину этой пословицы.
    virtual double Quotient();
};

#endif //__proverbs__
