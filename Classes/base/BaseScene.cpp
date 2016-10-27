//
//  BaseScene.cpp
//  Game
//
//  Created by 咸光金 on 2016/10/26.
//
//

#include "BaseScene.h"

BaseScene::BaseScene(bool bPortrait):_rootLayer(nullptr){
    log("BaseScene()");
    Scene::init();
    director=Director::getInstance();
    visibleSize=director->getVisibleSize();
    visibleOrigin=director->getVisibleOrigin();
}


BaseScene::~BaseScene(void){
    
    
}


void BaseScene::onEnter(){
    log("Base OnEnter");
    Scene::onEnter();
}



void BaseScene::onExit(){
    log("Base OnExit");
    if (_rootLayer!=nullptr) {
        _rootLayer->removeFromParent();
    }
    TextureCache::getInstance()->removeAllTextures();
    Scene::onExit();
}

