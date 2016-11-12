/*
 * Parser.cpp
 *
 *  Created on: 12 de nov. de 2016
 *      Author: jorlando
 */

#include "../Headers/Parser.h"

Parser::Parser() {
}


void loadConfigOfStage(Stage* stage, int lineConfig, string* line){
	//cout << "ENTRE AL CONFIG" <<endl;
 switch(lineConfig){
	 case 0:
		 stage->name = *line;
		 break;
	 case 1:
		 stage->qtyNode = atoi(line->substr(line->find(" ")+1).c_str());
		 break;
	 case 2:
		 string capacityBagStr = line->substr(line->find(" ")+1);
		 stage->capacityBag = atoi(capacityBagStr.c_str());
		 break;
 }
}

void processLine(list<Stage>* listStage, Stage* stage, int* lineConfig, string* line){
	//cout << "ENTRE AL PROCESS" << *lineConfig<<endl;
	if(*lineConfig >= 0 && *lineConfig < 5){
		loadConfigOfStage(stage, *(lineConfig), line);
	} else if (*lineConfig >= 5){
		stage->loadNode(line);
		if(stage->isFull()){
			(*listStage).push_back(*stage);
			*stage = *(new Stage());
			//Es -3 porque el archivo tiene una linea con --- y otra vacia entre cada uno de los Stage
			*(lineConfig) = -3;
			cout << "(*listStage) " << (*listStage).size()<<endl;
		}
	}
	*(lineConfig) = *(lineConfig)+1;
}

list<Stage> Parser::getListOfStages(string path){
	list<Stage> listStage;
	ifstream inputFile;
	inputFile.open(path.c_str());
	if (inputFile.is_open()) {
		int lineConfig = 0;
		Stage* stage = new Stage();
		string line;
		 while (std::getline(inputFile, line)) {
			 //cout << "LINEA " << line << endl;
			 processLine(&listStage, stage, &lineConfig, &line);
		 }
	}
	inputFile.close();
	cout << "SALGO " << listStage.size()<< endl;
	return listStage;
}

Parser::~Parser() {
	// TODO Auto-generated destructor stub
}
