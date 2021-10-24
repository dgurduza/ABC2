//------------------------------------------------------------------------------
// well_of_wisdom.cpp 
//------------------------------------------------------------------------------

#include "aphorisms.h"
#include "proverbs.h"
#include "riddles.h"
#include "well_of_wisdom.h"
#include <fstream>

Random Well_of_wisdom::rnd3;

//------------------------------------------------------------------------------
// ¬вод параметров обобщенной фигуры из файла
Well_of_wisdom* Well_of_wisdom::StaticIn(FILE* fl) {
    int k;
    fscanf(fl,"%i", &k);
    Well_of_wisdom* sp = nullptr;
    switch (k) {
    case 1:
        sp = new Aphorisms;
        break;
    case 2:
        sp = new Proverbs;
        break;
    case 3:
        sp = new Riddles;
        break;
    }
    sp->In(fl);
    return sp;
}

// —лучайный ввод обобщенной фигуры
Well_of_wisdom* Well_of_wisdom::StaticInRnd() {
    auto k = Well_of_wisdom::rnd3.Get();
    Well_of_wisdom* sp = nullptr;
    switch (k) {
    case 1:
        sp = new Aphorisms;
        break;
    case 2:
        sp = new Proverbs;
        break;
    case 3:
        sp = new Riddles;
        break;
    }
    sp->InRnd();
    return sp;
}