#include "../Headers/Parser.h"

Parser::Parser() {
}


void loadConfigOfStage(Stage* stage, int lineConfig, string* line){
	switch(lineConfig){
		case 0:
            stage->name = *line;
            break;
		case 1:
			stage->qtyNode = atoi(line->substr(line->find(" ")+1).c_str());
			break;
		case 2:
			stage->capacityBag = atoi(line->substr(line->find(" ")+1).c_str());
			break;
        case 3:
            stage->optimo = atoi(line->substr(line->find(" ")+1).c_str());
			break;
        default:
            break;
	 }
}

void processLine(vector<Stage>* listStage, Stage* stage, int* lineConfig, string* line){
	if(*lineConfig >= 0 && *lineConfig < 5){
		loadConfigOfStage(stage, *(lineConfig), line);
	} else if (*lineConfig >= 5){
		stage->loadNode(line);
		if(stage->isFull()){
			listStage->push_back(*stage);
			*stage = Stage();
			//Es -3 porque el archivo tiene una linea con --- y otra vacia entre cada uno de los Stage
			*(lineConfig) = -3;
		}
	}
	*(lineConfig) = *(lineConfig)+1;
}

vector<Stage>* Parser::getListOfStages(string path){
	vector<Stage>* listStage = new vector<Stage>();
	ifstream inputFile;
	inputFile.open(path.c_str());
	if (inputFile.is_open()) {
		int lineConfig = 0;
		Stage stage = Stage();
		string line;
		int j = 0;
        while (std::getline(inputFile, line)) {
            processLine(listStage, &stage, &lineConfig, &line);
		}
	}
	inputFile.close();
	return listStage;
}

Parser::~Parser() {
}
