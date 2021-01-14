// SchedulingBranchAndBound.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "SchedulingBranchAndBound.h"
// Kto wpad³ na pomys³ tak dlugiej nazwy pliku ?????? :/
// Tutaj to kij, ale header do tego ma 2 km


// TODO okreœliæ strukturê podawanych danych i danych, które chcemy otrzymaæ

// TODO drugi algorytm do porównania Johnson??? / brute

void rewrite_table(Task* table1, Task* table2, int nr_of_items) {
    for (int i = 0; i < nr_of_items; i++) {
        table2[i] = table1[i];
    }
}

int main() {
    int n = 0; // Number of tasks
    Task* first_task; // Pointer to original first task

    // TODO Wczytaæ dane i sprawdziæ ich poprawnoœæ

    Task* task_current[n]; // Table for pointers for exact tasks of currently calculated solution
    Task* task_best[n]; // Table for pointers for exact tasks of best calculated solution

    // Odpaliæ algorytm góra dó³

    // Jakiœ wykresik albo insze gówno
    // Zapis wyniku do pliku

    return 0;
}