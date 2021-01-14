#include <iostream>
#include <fstream>
#include <vector> 
#include <string>
#include <time.h>
#include <ctime>
#include <stdio.h> 

//given problem
int ProblemSize = 0;
std::vector<std::vector<int>> Problem; //table 2xN, times for each task for each machine
int BreakLen = 0;
int MaxTimeWithoutBreak = 0;
//variables
bool LastAddedWasBreak = false; //keeps info if last added element to solution was a break
std::vector<std::vector<int>> CurrentSolution;   //keeps actualy build solution
std::vector<std::vector<int>> BestSolution;  //keeps best found solution///WARTO PRZEMYåLE∆ CZY NIE UØY∆ WSKAèNIKA, BO PRZEPISYWANIE JEST CZASOCH£ONNE
int BestScore = 0;  //keeps score of the beast solution

//funkcja liczπca score
int countScore() {
    //waiting time<0, 0<=task<30000, 30000=break //takie wartoúci reprezentujπ poszczegolne elementy 30000, bo tyle zadaÒ nie da siÍ uszeregowaÊ dok≥adnie wiÍc moøemy sobie tπ liczbÍ zarezerwowaÊ na przerwÍ
}

//funkcja zamieniajπca najlepsze rozwiπzanie na obecne(obecne zostaje najlepszym)
void setActualAsBest() {

}

//sprawdzanie czy nasze obecne (niepe≥ne rozwiπzanie) po dodaniu brakujπcych zadaÒ i adekwatnej liczby przerw do brakujπcych zadaÒ nie ma score wiÍkszego niø najlepsze dotπd (pewnie da sie po≥aczyÊ z tπ wyøej)
bool isItPromisingSolution() {

}

//schedule second machine
void scheduleSecondMachine() {

}

//sprawdzanie poprawnoúci uszeregowania (moøna zrobiÊ dwie wersje ca≥oúÊ uszeregowania i tylko do ostatniej przerwy czy tam dwÛch w g≥πb bo reszta i tak by≥a sprawdzana)
bool isItScheduledWithRulesOnFirst() {

}

//sprawdzanie poprawnoúci uszeregowania (moøna zrobiÊ dwie wersje ca≥oúÊ uszeregowania i tylko do ostatniej przerwy czy tam dwÛch w g≥πb bo reszta i tak by≥a sprawdzana)
bool isItScheduledWithRulesOnBoth() {

}

void readFromFile() {

}

void writeToFile() {

}

//recursive function
bool Scheduling(int task) {//szereguje tylko pierwszπ, druga jest dostosowywana pÛüniej, czyli dwie duøe funkcje najprwdopodobniej///DO PRZEMYåLENIA CZY NA PEWNO REKURENCJA
    std::vector<int> alreadyCheckedTasks;

    //dodaj to co przes≥ane'task'
    //sprwdü czy dodany element nie psuje zasad szeregowania na maszynie
        //jeúli tak, to return false
    //sprwadü czy rozwiπzanie jest obiecujπce
    //spr co by≥o dodane ostatnio zadanie czy przerwa (naleøy miÍdzy kaødymi zadaniami sprÛbowaÊ przerwÍ)
    //dodaj kolejny element: scheduling(element)
        //jeúli zwrÛci≥ siÍ false to sprawdü czy by≥y jeszcze jakieú nie wyprÛbowane zadania 
            //jeúli nie to teø zwrÛÊ false sygnalizujπÊ úlepπ drogÍ
        

}

#include "SchedulingBranchAndBound.h"
// Kto wpad≈Ç na pomys≈Ç tak dlugiej nazwy pliku ?????? :/
// Tutaj to kij, ale header do tego ma 2 km


// TODO okre≈õliƒá strukturƒô podawanych danych i danych, kt√≥re chcemy otrzymaƒá

// TODO drugi algorytm do por√≥wnania Johnson??? / brute

void rewrite_table(Task *table1, Task *table2, int nr_of_items) {
    for (int i = 0; i < nr_of_items; i++) {
        table2[i] = table1[i];
    }
}

int main() {
    int n = 0; // Number of tasks
    Task *first_task; // Pointer to original first task

    // TODO Wczytaƒá dane i sprawdziƒá ich poprawno≈õƒá

    Task *task_current[n]; // Table for pointers for exact tasks of currently calculated solution
    Task *task_best[n]; // Table for pointers for exact tasks of best calculated solution

    // Odpaliƒá algorytm g√≥ra d√≥≈Ç

    // Jaki≈õ wykresik albo insze g√≥wno
    // Zapis wyniku do pliku

    return 0;
}
