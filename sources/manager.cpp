#include <iostream>
#include "../headers/manager.h"
#include "../headers/definition.h"

Manager * Manager::instance = nullptr;

Manager * Manager::getInstance(){
    if(instance == nullptr){
        instance = new Manager();
    }
    return instance;
}

void Manager::update(){
    if(!sceneIsDefine())
        return;
    cleanMatrice();
    
    /*Bloc*/
    for (int index = 0; index < bloc->list_bloc->size(); ++index){
        generalTable[bloc->list_bloc->at(index).first][bloc->list_bloc->at(index).second] = BLOC_DEF;
    }

    /*Car*/
    generalTable[car->getPosition().first][car->getPosition().second] = CAR_DEF;

    /*Chemin*/
    for (int index = 0; index < chemin->list_chemin->size(); ++index){
        generalTable[chemin->list_chemin->at(index).first][chemin->list_chemin->at(index).second] = CHEMIN_DEF;
    }

}

void Manager::cleanMatrice(){
    for (int x = 0; x < getSceneCarrer(); ++x){
        for (int y = 0; y < getSceneCarrer(); ++y){
            generalTable[x][y] = 0;
        }
    }
}

std::string Manager::toString(){
    return "";
}