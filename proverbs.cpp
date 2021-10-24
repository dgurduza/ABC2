//------------------------------------------------------------------------------
// proverbs.cpp
//------------------------------------------------------------------------------
#include "string.h"
#include "proverbs.h"
#include <fstream>

//------------------------------------------------------------------------------
// ¬вод параметров пословицы из файла.
void Proverbs::In(FILE* fl) { 
    fscanf(fl, "%s%s", &proverb, &country);
}

// —лучайный ввод параметров пословицы.
void Proverbs::InRnd() {
    country = Well_of_wisdom::rnd3.GetWord();
    proverb = Well_of_wisdom::rnd3.GetPhrase();
}

//------------------------------------------------------------------------------
// ¬ывод параметров пословицы в форматируемый поток.
void Proverbs::Out(FILE* file) {
    fprintf(file, "%s %s %s %s %s",
        "It is proverb: ", proverb, "\nIt is proverb country: ", country, "\n");
}

//------------------------------------------------------------------------------
// ¬ычисление частного от количества знаков препинани€ в пословице на длину этой пословицы.
double Proverbs::Quotient() {
    int num = 0;
    for (int i = 0; i < strlen(proverb); ++i) {
        if (proverb[i] == '!' || proverb[i] == '\"' || proverb[i] == '#'
            || proverb[i] == '$' || proverb[i] == '%' || proverb[i] == '&' || proverb[i] == '\''
            || proverb[i] == '(' || proverb[i] == ')' || proverb[i] == '*' || proverb[i] == '+'
            || proverb[i] == ',' || proverb[i] == '-' || proverb[i] == '.' || proverb[i] == ':'
            || proverb[i] == ';' || proverb[i] == '?') {
            ++num;
        }
    }
    int i = strlen(proverb);
    double n = (double)num / i;
    return n;
}
