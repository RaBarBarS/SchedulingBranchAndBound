// SchedulingBranchAndBound.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "SchedulingBranchAndBound.h"
// Kto wpad� na pomys� tak dlugiej nazwy pliku ?????? :/
// Tutaj to kij, ale header do tego ma 2 km


// TODO okre�li� struktur� podawanych danych i danych, kt�re chcemy otrzyma�

// TODO drugi algorytm do por�wnania Johnson??? / brute

void rewrite_table(Task* table1, Task* table2, int nr_of_items) {
    for (int i = 0; i < nr_of_items; i++) {
        table2[i] = table1[i];
    }
}

int main() {
    int n = 0; // Number of tasks
    Task* first_task; // Pointer to original first task

    // TODO Wczyta� dane i sprawdzi� ich poprawno��

    Task* task_current[n]; // Table for pointers for exact tasks of currently calculated solution
    Task* task_best[n]; // Table for pointers for exact tasks of best calculated solution

    // Odpali� algorytm g�ra d�

    // Jaki� wykresik albo insze g�wno
    // Zapis wyniku do pliku

    return 0;
}