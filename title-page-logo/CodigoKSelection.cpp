/* Busca la posicion del elemento mas chico, buscando a partir de initPosition */
int Utils::getPositionOfSmallerValue(vector<int>* array,int initPosition){
    int smallerPosition = initPosition;
    int smallerValue = array->at(initPosition);
    for(int auxPosition = (initPosition+1); auxPosition < array->size(); auxPosition++){
        if(array->at(auxPosition) < smallerValue){
            smallerPosition = auxPosition;
            smallerValue = array->at(auxPosition);
        }
    }
    return smallerPosition;
}

/* Swap entre initPosition y smallerPosition */
void Utils::changeSmallerWithInitial(vector<int>* array, int initPosition, int smallerPosition){
    int initValue = array->at(initPosition);
    int smallerValue = array->at(smallerPosition);

    array->at(initPosition) = smallerValue;
    array->at(smallerPosition) = initValue;
}

int Utils::kSelection(vector<int>* array,int k){
	for(int indexArray=0; (indexArray<array->size() && indexArray <= k); indexArray++){
		int position = getPositionOfSmallerValue(array, indexArray);
		changeSmallerWithInitial(array, indexArray, position);
	}
	return array->at(k);
}