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
std::vector<std::vector<int>> BestSolution;  //keeps best found solution///WARTO PRZEMY�LE� CZY NIE U�Y� WSKA�NIKA, BO PRZEPISYWANIE JEST CZASOCH�ONNE
int BestScore = 0;  //keeps score of the beast solution

//funkcja licz�ca score
int countScore() {
    //waiting time<0, 0<=task<30000, 30000=break //takie warto�ci reprezentuj� poszczegolne elementy 30000, bo tyle zada� nie da si� uszeregowa� dok�adnie wi�c mo�emy sobie t� liczb� zarezerwowa� na przerw�
}

//funkcja zamieniaj�ca najlepsze rozwi�zanie na obecne(obecne zostaje najlepszym)
void setActualAsBest() {

}

//sprawdzanie czy nasze obecne (niepe�ne rozwi�zanie) po dodaniu brakuj�cych zada� i adekwatnej liczby przerw do brakuj�cych zada� nie ma score wi�kszego ni� najlepsze dot�d (pewnie da sie po�aczy� z t� wy�ej)
bool isItPromisingSolution() {

}

//schedule second machine
void scheduleSecondMachine() {

}

//sprawdzanie poprawno�ci uszeregowania (mo�na zrobi� dwie wersje ca�o�� uszeregowania i tylko do ostatniej przerwy czy tam dw�ch w g��b bo reszta i tak by�a sprawdzana)
bool isItScheduledWithRulesOnFirst() {

}

//sprawdzanie poprawno�ci uszeregowania (mo�na zrobi� dwie wersje ca�o�� uszeregowania i tylko do ostatniej przerwy czy tam dw�ch w g��b bo reszta i tak by�a sprawdzana)
bool isItScheduledWithRulesOnBoth() {

}

void readFromFile() {

}

void writeToFile() {

}

//recursive function
bool Scheduling(int task) {//szereguje tylko pierwsz�, druga jest dostosowywana p�niej, czyli dwie du�e funkcje najprwdopodobniej///DO PRZEMY�LENIA CZY NA PEWNO REKURENCJA
    std::vector<int> alreadyCheckedTasks;

    //dodaj to co przes�ane'task'
    //sprwd� czy dodany element nie psuje zasad szeregowania na maszynie
        //je�li tak, to return false
    //sprwad� czy rozwi�zanie jest obiecuj�ce
    //spr co by�o dodane ostatnio zadanie czy przerwa (nale�y mi�dzy ka�dymi zadaniami spr�bowa� przerw�)
    //dodaj kolejny element: scheduling(element)
        //je�li zwr�ci� si� false to sprawd� czy by�y jeszcze jakie� nie wypr�bowane zadania 
            //je�li nie to te� zwr�� false sygnalizuj�� �lep� drog�
        

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
