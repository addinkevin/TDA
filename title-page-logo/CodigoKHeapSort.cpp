int Utils::kHeapSort(vector<int>* array, int k) {
    std::make_heap(array->begin(), array->end(), std::greater<int>()); // Heapify

    int extraccion;
    // K extracciones
    for (int i = 0; i < k + 1 ; i++) {
        std::pop_heap(array->begin(), array->end(), std::greater<int>());
        extraccion = array->back();
        array->pop_back();
    }

    return extraccion;
}
