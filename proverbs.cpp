//------------------------------------------------------------------------------
// proverbs.cpp
//------------------------------------------------------------------------------
#include "string.h"
#include "proverbs.h"
#include <fstream>

//------------------------------------------------------------------------------
// ���� ���������� ��������� �� �����.
void Proverbs::In(FILE* fl) { 
    fscanf(fl, "%s%s", &proverb, &country);
}

// ��������� ���� ���������� ���������.
void Proverbs::InRnd() {
    country = Well_of_wisdom::rnd3.GetWord();
    proverb = Well_of_wisdom::rnd3.GetPhrase();
}

//------------------------------------------------------------------------------
// ����� ���������� ��������� � ������������� �����.
void Proverbs::Out(FILE* file) {
    fprintf(file, "%s %s %s %s %s",
        "It is proverb: ", proverb, "\nIt is proverb country: ", country, "\n");
}

//------------------------------------------------------------------------------
// ���������� �������� �� ���������� ������ ���������� � ��������� �� ����� ���� ���������.
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
