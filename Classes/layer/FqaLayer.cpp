//
//  FqaLayer.cpp
//  Game
//
//  Created by 咸光金 on 2016/10/27.
//
//

#include "FqaLayer.h"


void FqaLayer::initThings() {


}

void FqaLayer::onCreateGameLayer(){
  _rootLayer=CSLoader::createNode("<#filename#>");
  if (_rootLayer==nullptr) {
       return;
   }
   addChild(_rootLayer);


}


void FqaLayer::onClick(Ref *sender){
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


bool FqaLayer::init(){
    if (!Layer::init()) {
        return false;
    }
    director=Director::getInstance();
    visibleSize=director->getVisibleSize();
    visibleOrigin=director->getVisibleOrigin();
    _rootLayer=nullptr;
    initThings();

    return true;
}


Scene * FqaLayer::createScene(){
    Scene *scene=Scene::create();
    auto layer=FqaLayer::create();
    scene->addChild(layer);

    return scene;
}


void FqaLayer::onEnter(){
  Layer::onEnter();
  onCreateGameLayer();

}



void FqaLayer::onExit(){
  Layer::onExit();


}
