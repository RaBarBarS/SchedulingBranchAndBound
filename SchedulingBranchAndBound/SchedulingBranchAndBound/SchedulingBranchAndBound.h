#ifndef SCHEDULINGBRANCHANDBOUND_H
#define SCHEDULINGBRANCHANDBOUND_H

#include <vector>


//#define DATA_FORMAT 't'
#define DATA_FORMAT 'b'

typedef enum {
    t_idle = 0,
    t_task = 1,
    t_maintenance = 2,
} ActionType;

typedef struct {
    ActionType action_type;
    unsigned int action_nr;
    unsigned int start_time;
    unsigned int duration_time;
    unsigned int end_time;
} Action;

typedef struct {
    unsigned int nr_of_tasks;
    unsigned int nr_of_shops;

    std::vector<std::vector<unsigned int>> tasks;
    std::vector<unsigned int> repair_time;
    std::vector<unsigned int> max_work_time;

    unsigned int best_solution_time;
    std::vector<std::vector<Action>> actions;
} FlowShop;

typedef struct {
    std::vector<std::vector<Action>> actions;
    std::vector<unsigned int> last_repair_end;
    std::vector<unsigned int> tasks_made;
    unsigned int solution_time;
} ActualSolution;


#endif //SCHEDULINGBRANCHANDBOUND_H
