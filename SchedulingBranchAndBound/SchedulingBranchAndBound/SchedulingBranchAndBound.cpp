// SchedulingBranchAndBound.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
