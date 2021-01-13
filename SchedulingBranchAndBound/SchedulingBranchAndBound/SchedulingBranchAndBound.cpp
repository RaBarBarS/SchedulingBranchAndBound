#include <iostream>

#include "SchedulingBranchAndBound.h"
// Kto wpadł na pomysł tak dlugiej nazwy pliku ?????? :/
// Tutaj to kij, ale header do tego ma 2 km


// TODO określić strukturę podawanych danych i danych, które chcemy otrzymać

// TODO drugi algorytm do porównania Johnson??? / brute

void rewrite_table(Task *table1, Task *table2, int nr_of_items) {
    for (int i = 0; i < nr_of_items; i++) {
        table2[i] = table1[i];
    }
}

int main() {
    int n = 0; // Number of tasks
    Task *first_task; // Pointer to original first task

    // TODO Wczytać dane i sprawdzić ich poprawność

    Task *task_current[n]; // Table for pointers for exact tasks of currently calculated solution
    Task *task_best[n]; // Table for pointers for exact tasks of best calculated solution

    // Odpalić algorytm góra dół

    // Jakiś wykresik albo insze gówno
    // Zapis wyniku do pliku

    return 0;
}
