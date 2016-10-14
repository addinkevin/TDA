bool Utils::verificador(vector<int>* array,int candidate,int k){
    int leftCount = 0;
    int frequency = 0;
    for (int i = 0; i < array->size(); i++) {
        if (array->at(i) < candidate) {
            leftCount++;
        } else if (array->at(i) == candidate) {
            frequency++;
        }
    }

    return leftCount <= k && k <= leftCount + frequency - 1;

}

int Utils::bruteForce(vector<int>* array,int k){
	for(int i=0; i < array->size(); i++){
		if(verificador(array,array->at(i),k))
			return array->at(i);
	}
	return -1;
}
