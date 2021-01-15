#include <iostream>
#include <fstream>

#include "SchedulingBranchAndBound.h"
// Kto wpad� na pomys� tak dlugiej nazwy pliku ?????? :(
// Tutaj to kij, ale header do tego ma 2 km

using namespace std;


// TODO okre�li� struktur� podawanych danych i danych, kt�re chcemy otrzyma�

// TODO drugi algorytm do por�wnania Johnson??? / brute

void rewriteTable(Task *table1, Task *table2, int nr_of_items) {
    for (int i = 0; i < nr_of_items; i++) {
        table2[i] = table1[i];
    }
}

#if DATA_FORMAT == 't'
void readFile(ifstream &filename, Task *firstTask, FlowShop *flowShop) {
    string word; // Można to do intów prypisywać, ale sprawdzam, czy ktoś nie postanowił jakiegoś syfu podać
    unsigned int i = 0;
    int value;

    // TODO przerobi? to na pobieranie linii i obs?ug? jej

    while (filename >> word) {
        // Searching for comment lines starting with '#'
        if (word[0] == '#') {
            getline(filename, word);
//            filename.ignore(1,'\n');
            continue;
        }

        value = stoi(word);

        switch (i) {
            case 0:
                flowShop->repair_time[0] = value;
                break;
            case 1:
                flowShop->repair_time[1] = value;
                break;
            case 2:
                flowShop->max_working_time[0] = value;
                break;
            case 3:
                flowShop->max_working_time[1] = value;
            default:
                break;
        }
        i++;
    }
}

#else

#endif

int main(int argc, char *argv[]) {

    string path_to_input = "data/input.txt";
    string path_to_output = "data/output.txt";

    // Read of passed arguments
    for (int i = 1; i < argc; i++) {
        switch (i) {
            case 1:
                path_to_input = argv[i];
                break;
            case 2:
                path_to_output = argv[i];
                break;
            default:
                break;
        }
    }

    int n = 0; // Number of tasks
    Task *first_task = nullptr; // Pointer to original first task
    FlowShop flow_shop; // Structure with all needed information about flow shop

    // TODO Wczyta? dane i sprawdzi? ich poprawno??
    ifstream input_file(path_to_input);
    readFile(input_file, first_task, &flow_shop);
    input_file.close();

    Task *task_current[n]; // Table for pointers for exact tasks of currently calculated solution
    Task *task_best[n]; // Table for pointers for exact tasks of best calculated solution

    // Odpali� algorytm g�ra d�?

    // Jaki� wykresik albo insze g�wno
    // Zapis wyniku do pliku

    return 0;
}