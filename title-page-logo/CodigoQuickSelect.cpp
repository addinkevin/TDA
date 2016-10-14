void Utils::swap(vector<int>* array, int i, int j) {
    int tmp = array->at(i);
    array->at(i) = array->at(j);
    array->at(j) = tmp;
}

int Utils::partition(vector<int>* array, int left, int right) {
    int pivotIndex = left + std::rand() % (right - left);
    int pivotValue = array->at(pivotIndex);

    swap(array,pivotIndex, right); // Move pivot to end
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if(array->at(i) < pivotValue) {
            swap(array, storeIndex, i);
            storeIndex++;
        }
    }
    swap(array, right, storeIndex); // Move pivot to its final place
    return storeIndex;
}

int Utils::_quickSelect(vector<int>* array,int left, int right, int k){
    if ( left == right )
    	return array->at(left);

    int pivotIndex = partition(array, left, right);

    if ( pivotIndex == k )
    	return array->at(pivotIndex);
    else if ( k < pivotIndex )
    	return _quickSelect(array, left, pivotIndex - 1, k);
    else
    	return _quickSelect(array, pivotIndex + 1, right, k);
}
int Utils::quickSelect(vector<int>* array, int k) {
    return _quickSelect(array, 0, array->size()-1, k);
}