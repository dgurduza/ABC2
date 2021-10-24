//------------------------------------------------------------------------------
// riddles.cpp
//------------------------------------------------------------------------------
#include "string.h"
#include "riddles.h"
#include <fstream>

//------------------------------------------------------------------------------
// ���� ���������� ������� �� �����.
void Riddles::In(FILE* fl) {
    fscanf(fl,"%s%s", &riddle,&answer);
}

// ��������� ���� ���������� �������.
void Riddles::InRnd() {
    answer = Well_of_wisdom::rnd3.GetWord();
    riddle = Well_of_wisdom::rnd3.GetPhrase();
}

//------------------------------------------------------------------------------
// ����� ���������� ������� � ������������� �����.
void Riddles::Out(FILE* file) {
    fprintf(file, "%s %s %s %s %s",
        "It is riddle: ", riddle, "\nIt is answer to the riddle: ", answer, "\n");
}

//------------------------------------------------------------------------------
// ���������� �������� �� ���������� ������ ���������� � ������� �� ����� ���� �������.
double Riddles::Quotient() {
    int num = 0;
    for (int i = 0; i < strlen(riddle); ++i) {
        if (riddle[i] == '!' || riddle[i] == '\"' || riddle[i] == '#'
            || riddle[i] == '$' || riddle[i] == '%' || riddle[i] == '&' || riddle[i] == '\''
            || riddle[i] == '(' || riddle[i] == ')' || riddle[i] == '*' || riddle[i] == '+'
            || riddle[i] == ',' || riddle[i] == '-' || riddle[i] == '.' || riddle[i] == ':'
            || riddle[i] == ';' || riddle[i] == '?') {
            ++num;
        }
    }
    int i = strlen(riddle);
    double n = (double)num / i;
    return n;
}
