#ifndef SCHEDULINGBRANCHANDBOUND_SCHEDULINGBRANCHANDBOUND_H
#define SCHEDULINGBRANCHANDBOUND_SCHEDULINGBRANCHANDBOUND_H

// TODO Przewalić to na jakieś ładne klasy jak na cpp przystało, a nie jak barbarzyńca w c



typedef struct Task {
    unsigned int m1_time;
    unsigned int m2_time;
    int time_diff;
    Task *next_task;
} Task;


#endif //SCHEDULINGBRANCHANDBOUND_SCHEDULINGBRANCHANDBOUND_H
