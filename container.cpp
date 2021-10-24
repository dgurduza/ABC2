//------------------------------------------------------------------------------
// container_Constr.cpp - �������� ������� ��������� ����������
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// ����������� ����������
Container::Container() : len{ 0 } { }

//------------------------------------------------------------------------------
// ���������� ����������
Container::~Container() {
    Clear();
}
//------------------------------------------------------------------------------
// ������� ����������
void Container::Clear() {
    for (int i = 0; i < len; i++) {
        delete storage[i];
    }
    len = 0;
}

//------------------------------------------------------------------------------
// ���� ����������� ���������� �� ���������� ������
void Container::In(FILE* fl) {
    while (!feof(fl)) {
        if ((storage[len] = Well_of_wisdom::StaticIn(fl)) != 0) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// ��������� ���� ����������� ����������
void Container::InRnd(int size) {
    while (len < size) {
        if ((storage[len] = Well_of_wisdom::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// ����� ����������� ���������� � ��������� �����.
void Container::Out(FILE* file) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (storage[i] != nullptr) {
            fprintf(file, "%u %s", i, ": ");
            storage[i]->Out(file);
            ++count;
        }
    }
    fprintf(file, "%s %u %s", "Container contains ", count, " elements.\n");
}

//------------------------------------------------------------------------------
// ���������� �������� ��������������� ��������� � ����������.
double Container::ArithmeticMeanOfQuotients() {
    double sum = 0.0;
    int i;
    for (i = 0; i < len; ++i) {
        sum += storage[i]->Quotient();
    }
    return (double)sum / i;
}
//------------------------------------------------------------------------------
// �������� ��������� � ����������������� �������.
int Container::DeletingNullElements() {
    int indexer = 0;
    int new_len = len;
    double mean = ArithmeticMeanOfQuotients();
    for (int i = 0; i < len; ++i) {
        if (storage[i]->Quotient() < mean) {
            storage[i] = nullptr;
            --new_len;
        }
    }
    return new_len;
}

