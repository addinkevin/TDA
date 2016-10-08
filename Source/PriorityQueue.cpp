//
// Created by kevin on 10/7/16.
//

#include "../Headers/PriorityQueue.h"


PriorityQueue::PriorityQueue() {
    this->init();
}

PriorityQueue::~PriorityQueue() {
    delete this->priorityQueue;
}

std::pair<int, double> PriorityQueue::top() {
    return this->priorityQueue->top();
}

std::pair<int, double> PriorityQueue::pop() {
    std::pair<int,double> pairObject = this->priorityQueue->top();
    this->priorityQueue->pop();
    return pairObject;
}

void PriorityQueue::push(int vertex, double priority) {
    this->priorityQueue->push(std::pair<int,double>(vertex, priority));
}

void PriorityQueue::init() {
    this->priorityQueue = new PriorityQueueType(ComparePair());
}

bool PriorityQueue::empty() {
    return this->priorityQueue->empty();
}

