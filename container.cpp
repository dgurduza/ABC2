//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Конструктор контейнера
Container::Container() : len{ 0 } { }

//------------------------------------------------------------------------------
// Деструктор контейнера
Container::~Container() {
    Clear();
}
//------------------------------------------------------------------------------
// Очистка контейнера
void Container::Clear() {
    for (int i = 0; i < len; i++) {
        delete storage[i];
    }
    len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void Container::In(FILE* fl) {
    while (!feof(fl)) {
        if ((storage[len] = Well_of_wisdom::StaticIn(fl)) != 0) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void Container::InRnd(int size) {
    while (len < size) {
        if ((storage[len] = Well_of_wisdom::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток.
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
// Вычисление среднего арифметического элементов в контейнере.
double Container::ArithmeticMeanOfQuotients() {
    double sum = 0.0;
    int i;
    for (i = 0; i < len; ++i) {
        sum += storage[i]->Quotient();
    }
    return (double)sum / i;
}
//------------------------------------------------------------------------------
// Удаление элементов с несоответствующим частным.
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

