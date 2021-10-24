//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию, 
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h> // для функций rand() и srand()
#include <time.h>   // для функции time()
#include <string.h>
#include <fstream>
#include "container.h"

void errMessage1() {
    printf("incorrect command line!\n %s %s %s %s", "  Waited:\n", "     command -f infile outfile01 outfile02\n",
        "  Or:\n", "     command -n number outfile01 outfile02\n");
}

void errMessage2() {
    printf("incorrect qualifier value!\n %s %s %s %s", "  Waited:\n", "     command -f infile outfile01 outfile02\n",
        "  Or:\n", "     command -n number outfile01 outfile02\n");
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    clock_t start = clock();
    if (argc != 5) {
        errMessage1();
        return 1;
    }

    printf("Start\n");
    Container c;

    ////cout << "argv[1] = " << argv[1] << "\n";
    if (!strcmp(argv[1], "-f")) {
        FILE* fl = fopen(argv[2], "r");
        c.In(fl);
        fclose(fl);
    }
    else if (!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            printf("incorrect numer of phrases = %u %s", size, ". Set 0 < number <= 10000\n");
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных строк.
        c.InRnd(size);
    }
    else {
        errMessage2();
        return 2;
    }

    // Вывод содержимого контейнера в файл
    FILE* file1 = fopen(argv[3], "w+");
    fprintf(file1, "%s", "Filled container:\n");
    c.Out(file1);
    fclose(file1);

    // The 2nd part of task
    FILE* file2 = fopen(argv[4], "a+");
    fprintf(file2, "%s %d %s ", "New container size after deleting= ", c.DeletingNullElements(), "\n");
    c.Out(file2);
    fclose(file2);
    //printf("Time taken: %.2f ms\n", (double)(clock() - start) / CLOCKS_PER_SEC * 1000);
    printf("Stop\n");
    return 0;
}