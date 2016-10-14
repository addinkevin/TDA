int Utils::orderAndSelect(vector<int> *array, int k) {
    std::sort(array->begin(),array->end());
    return array->at(k);
}