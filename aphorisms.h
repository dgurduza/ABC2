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
// Афоризм.
class Aphorisms : public Well_of_wisdom {
private:
    char *author; // Автор.
    char *aphorism;
public:
    // Деструктор.
    virtual ~Aphorisms() {}
    // Ввод параметров афоризма из файла.
    virtual void In(FILE* fl);

    // Случайный ввод параметров афоризма.
    virtual void InRnd();

    // Вывод параметров афоризма в форматируемый поток.
    virtual void Out(FILE* file);

    // Вычисление частного от количество знаков препинания в афоризме на длину афоризма.
    virtual double Quotient();
};

#endif //__aphorisms__
