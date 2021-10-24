//------------------------------------------------------------------------------
// Aphorisms.cpp
//------------------------------------------------------------------------------
#include "string.h"
#include "aphorisms.h"

//------------------------------------------------------------------------------
// ���� ���������� �������� �� �����.
void Aphorisms::In(FILE* fl) {
    fscanf(fl,"%s%s",&aphorism,&author);
}

// ��������� ���� ���������� ��������.
void Aphorisms::InRnd() {
    aphorism = Well_of_wisdom::rnd3.GetPhrase();
    author = Well_of_wisdom::rnd3.GetWord();
}

//------------------------------------------------------------------------------
// ����� ���������� �������� � ������������� �����.
void Aphorisms::Out(FILE* file) {
    fprintf(file, "%s %s %s %s %s",
        "It is aphorism: ", aphorism, "\nName of the author of the aphorism: ", author, "\n");
}

//------------------------------------------------------------------------------
// ���������� �������� �� ���������� ������ ���������� � �������� �� ����� ����� ��������.
double Aphorisms::Quotient() {
    int num = 0;
    for (int i = 0; i < strlen(aphorism); ++i) {
        if (aphorism[i] == '!' || aphorism[i] == '\"' || aphorism[i] == '#'
            || aphorism[i] == '$' || aphorism[i] == '%' || aphorism[i] == '&' || aphorism[i] == '\''
            || aphorism[i] == '(' || aphorism[i] == ')' || aphorism[i] == '*' || aphorism[i] == '+'
            || aphorism[i] == ',' || aphorism[i] == '-' || aphorism[i] == '.' || aphorism[i] == ':'
            || aphorism[i] == ';' || aphorism[i] == '?') {
            ++num;
        }
    }
    int i = strlen(aphorism);
    double n = (double)num / i;
    return n;
}

