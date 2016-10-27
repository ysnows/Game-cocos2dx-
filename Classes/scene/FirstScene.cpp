//
//  FirstScene.cpp
//  Game
//
//  Created by 咸光金 on 2016/10/26.
//
//

#include "FirstScene.h"

Scene * FirstScene::createScene(){
    Scene *scene=Scene::create();
    auto layer=FirstScene::create();
    scene->addChild(layer);

    return scene;
}



bool FirstScene::init(){
    if (!Layer::init()) {
        return false;
    }
    director=Director::getInstance();
    visibleSize=director->getVisibleSize();
    visibleOrigin=director->getVisibleOrigin();
    _rootLayer=nullptr;

    return true;
}


void FirstScene::onCreateGameLayer(){
  _rootLayer=CSLoader::createNode("<#filename#>");
   addChild(_rootLayer);


}



void FirstScene::onEnter(){
  onCreateGameLayer();

}



void FirstScene::onExit();
