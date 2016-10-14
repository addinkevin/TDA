
#ifndef TDA_PRIORITYQUEUE_H
#define TDA_PRIORITYQUEUE_H


#include <utility>
#include <vector>
#include <queue>

class ComparePair {
public:
    bool operator()(std::pair<int,double> left, std::pair<int,double> right) {
        return left.second > right.second;
    };
};

typedef std::priority_queue<std::pair<int,double>,std::vector<std::pair<int,int > >,ComparePair> PriorityQueueType;

class PriorityQueue {
private:
    PriorityQueueType* priorityQueue;
    void init();
public:
    PriorityQueue();
    ~PriorityQueue();

    void push(int vertex, double priority);
    std::pair<int,double> pop();
    std::pair<int,double> top();

    bool empty();
};


#endif //TDA_PRIORITYQUEUE_H
