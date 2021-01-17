#include <iostream>
#include <fstream>
#include <chrono>
#include <algorithm>

#include "SchedulingBranchAndBound.h"
// Kto wpad³ na pomys³ tak dlugiej nazwy pliku ?????? :(
// Tutaj to kij, ale header do tego ma 2 km

using namespace std;


// TODO okreœliæ strukturê podawanych danych i danych, które chcemy otrzymaæ

// TODO drugi algorytm do porównania Johnson??? / brute

//void rewriteTable(old_Task *table1, old_Task *table2, int nr_of_items) {
//    for (int i = 0; i < nr_of_items; i++) {
//        table2[i] = table1[i];
//    }
//}

#if DATA_FORMAT == 'b' // tylko dla dwóch maszyn

int readValue(ifstream &filename) {
    string word;
    int value;

    while (getline(filename, word)) {
        if (!word.empty()) {
            break;
        }
    }

    // TODO zabezpieczyć przed złymi danymi
    value = stoi(word);
    return value;
}

void readFile(ifstream &filename, FlowShop *flow_shop) {
    flow_shop->nr_of_shops = 2;
    flow_shop->nr_of_tasks = readValue(filename);

    for (unsigned int i = 0; i < flow_shop->nr_of_shops; i++) {
        flow_shop->tasks.emplace_back(vector<unsigned int>());
        for (unsigned int j = 0; j < flow_shop->nr_of_tasks; j++) {
            flow_shop->tasks[i].push_back(readValue(filename));
        }
    }

    for (unsigned int i = 0; i < flow_shop->nr_of_shops; i++) {
        flow_shop->repair_time.push_back(readValue(filename));
        flow_shop->max_work_time.push_back(readValue(filename));
    }
}

#elif DATA_FORMAT == 't' // Inny format - uniwersalny
// TODO dopisa? w?asny format
#endif

void printSolution2File(ofstream &filename, vector<vector<Action>> actions, unsigned int time) {
    filename << "Cmax: " << time << endl;
    for (unsigned int i = 0; i < actions.size(); i++) {
        filename << "M" << i << ": ";
        for (unsigned int j = 0; j < actions[i].size(); j++) {
            switch (actions[i][j].action_type) {
                case t_task:
                    filename << actions[i][j].action_nr << "/";
                    break;
                case t_idle:
                    filename << "i/";
                    break;
                case t_maintenance:
                    filename << "m/";
                    break;
                default:
                    filename << "e/";
                    break;
            }
            filename << actions[i][j].duration_time << ", ";
        }
        filename << endl;
    }
}

int addTaskMaking(FlowShop *flow_shop, ActualSolution *actual_solution, unsigned int task_nr) {
    Action action;

    for (unsigned int i = 0; i < flow_shop->nr_of_shops; i++) {
        unsigned int task_time = flow_shop->tasks[i][task_nr]; // Czas trwania zadania
        unsigned int end_time = actual_solution->actions[i].back().end_time; // Czas w którym kończy pracę poprzednie zadanie

        unsigned int starting_time = end_time; // Czas w którym potencjalnie możemy zacząć zadanie uwzględniając wcześniejsze maszyny
        if (i > 0) {
            // Sprawdz czy to zadanie nie konczy się na maszynie i-1 wszesciej niz poprzednie zadanie na tej maszynie
            if (actual_solution->actions[i - 1].back().end_time > starting_time) {
                starting_time = actual_solution->actions[i - 1].back().end_time;
            }
        }

        // Czy potrzebny jest maintenance
        if (actual_solution->last_repair_end[i] + flow_shop->max_work_time[i] <
            starting_time + task_time) {

            // Jeśli przerwa jest większa niż wynosi naprawa to będzie idle
            if (starting_time - end_time > flow_shop->repair_time[i]) {
                action.action_type = t_idle;
                action.action_nr = 0;
                action.start_time = actual_solution->actions[i].back().end_time;
                action.end_time = starting_time - flow_shop->repair_time[i];
                action.duration_time = action.end_time - action.start_time;
                actual_solution->actions[i].push_back(action);
            }

            action.action_type = t_maintenance;
            action.action_nr = 0;
            action.start_time = actual_solution->actions[i].back().end_time;
            action.duration_time = flow_shop->repair_time[i];
            action.end_time = action.start_time + action.duration_time;
            actual_solution->actions[i].push_back(action);

            actual_solution->last_repair_end[i] = action.end_time;
        }

        action.action_type = t_task;
        action.action_nr = task_nr;
        action.start_time = actual_solution->actions[i].back().end_time;
        action.duration_time = task_time;
        action.end_time = action.start_time + action.duration_time;
        actual_solution->actions[i].push_back(action);

    }
    actual_solution->tasks_made.push_back(task_nr);
    actual_solution->solution_time = actual_solution->actions.back().back().end_time;
    return 0;
}

unsigned int bruteCheckAll(FlowShop *flow_shop, ActualSolution *actual_solution) {
    // Check if we have checked last element
    if (actual_solution->tasks_made.size() == flow_shop->nr_of_tasks) {
        // Check if we found better solution
        if (actual_solution->solution_time < flow_shop->best_solution_time) {
            flow_shop->best_solution_time = actual_solution->solution_time;
            flow_shop->actions = actual_solution->actions;
        }
        return 0;
    }

    for (unsigned int i = 0; i < flow_shop->nr_of_tasks; i++) {
        if (find(actual_solution->tasks_made.begin(), actual_solution->tasks_made.end(), i) ==
            actual_solution->tasks_made.end()) {
            // Element not found
            ActualSolution new_solution = *actual_solution;
            addTaskMaking(flow_shop, &new_solution, i);
            bruteCheckAll(flow_shop, &new_solution);
        }
    }
    return 0;
}

// To w sumie jest niepotrzebne
unsigned int estimateWorstSolution(FlowShop *flow_shop) {
    unsigned int solution_time = 0;
    for (unsigned int i = 0; i < flow_shop->nr_of_shops; i++) {
        for (unsigned int j = 0; j < flow_shop->nr_of_tasks; j++) {
            solution_time += flow_shop->tasks[i][j];
            solution_time += flow_shop->repair_time[i];
        }
    }
    return solution_time;
}

ActualSolution getClearSolution(unsigned int nr_of_shops) {
    ActualSolution solution;
    for (unsigned int i = 0; i < nr_of_shops; i++) {
        solution.actions.emplace_back(vector<Action>());
        Action action;
        action.action_type = t_idle;
        action.action_nr = 0;
        action.start_time = 0;
        action.duration_time = 0;
        action.end_time = 0;
        solution.actions[i].push_back(action);
        solution.last_repair_end.push_back(0);
    }
    solution.solution_time = 0;
    return solution;
}

int main(int argc, char *argv[]) {
    string path_to_input = "../data/input.txt";
    string path_to_output = "../data/output.txt";

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

    FlowShop flow_shop; // Structure with all needed information about flow shop

    ifstream input_file(path_to_input);
    // Check if we can open file
    if (!input_file.is_open()) {
        cout << "Nie można otworzyć pliku" << endl;
        return 1;
    }

    readFile(input_file, &flow_shop);
    input_file.close();

    // Count initial time of making tasks
    // Policz pierwsze rozwiązanie z brzegu
    ActualSolution first_solution = getClearSolution(flow_shop.nr_of_shops);
    for (unsigned int i = 0; i < flow_shop.nr_of_tasks; i++) {
        addTaskMaking(&flow_shop, &first_solution, i);
    }
    flow_shop.best_solution_time = first_solution.solution_time;
    flow_shop.actions = first_solution.actions;


    ActualSolution clear_solution = getClearSolution(flow_shop.nr_of_shops);
    auto start_time = chrono::high_resolution_clock::now();
    bruteCheckAll(&flow_shop, &clear_solution);
    auto end_time = chrono::high_resolution_clock::now();

    ofstream output_file(path_to_output);
    printSolution2File(output_file, flow_shop.actions, flow_shop.best_solution_time);
    output_file << "Time: "
                << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count()
                << " µs" << endl;
    output_file.close();
    return 0;
}