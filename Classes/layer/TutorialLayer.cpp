//
//  TutorialLayer.cpp
//  Game
//
//  Created by 咸光金 on 2016/10/27.
//
//

#include "TutorialLayer.h"


void TutorialLayer::initThings() {


}

void TutorialLayer::onCreateGameLayer(){
  _rootLayer=CSLoader::createNode("<#filename#>");
  if (_rootLayer==nullptr) {
       return;
   }
   addChild(_rootLayer);
   _rootLayout=static_cast<Layout *>(_rootLayer->getChildByName("<#Panel_Back#>"));
   


}


void TutorialLayer::onClick(Ref *sender){
  <#ViewType#> *view=dynamic_cast<<#ViewType#>  *>(sender);

  if (view==nullptr) {
      return;
  } 
  switch (view->getTag()) {
      case 1:
      <#expression#>

          break;

      default:
          break;
  } 

}


bool TutorialLayer::init(){
    if (!Layer::init()) {
        return false;
    }
    director=Director::getInstance();
    visibleSize=director->getVisibleSize();
    visibleOrigin=director->getVisibleOrigin();
    _rootLayer=nullptr;
    _rootLayout=nullptr;
    initThings();

    return true;
}


Scene * TutorialLayer::createScene(){
    Scene *scene=Scene::create();
    auto layer=TutorialLayer::create();
    scene->addChild(layer);

    return scene;
}


void TutorialLayer::onEnter(){
  Layer::onEnter();
  onCreateGameLayer();

}



void TutorialLayer::onExit(){
  Layer::onExit();


}
