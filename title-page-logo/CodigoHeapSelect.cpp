int Utils::heapSelect(vector<int>* array, int k) {
    std::vector<int> heapK(array->begin(), array->begin()+k+1);
    std::make_heap(heapK.begin(), heapK.end()); // Heapify de los k primeros elementos.

    for (int i = k+1 ; i < array->size(); i++) {
        if (heapK.at(0) > array->at(i)) {
            std::pop_heap(heapK.begin(), heapK.end());
            heapK.pop_back();
            heapK.push_back(array->at(i));
            std::push_heap(heapK.begin(), heapK.end());
        }
    }

    return heapK.at(0);
}