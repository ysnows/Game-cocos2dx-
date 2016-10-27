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



void FirstScene::initThings(){
    
     auto isFirstTime=UserDefault::getInstance()->getBoolForKey("isFirstTime",true);
    if (isFirstTime) {
        //初始化数据
        UserDefault::getInstance()->setBoolForKey("isFirstTime", false);
        log("first time");
        
        UserDefault::getInstance()->flush();
    }
    
    SQLiteDatabase db;
    std::string sqlPath;
    
    
#if(CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID||CC_TARGET_PLATFORM==CC_PLATFORM_IOS||CC_TARGET_PLATFORM==CC_PLATFORM_MAC)
//    
//    if (!isFileExist("Thimbelina.sqlite")) {
//        copyData("Thumbelina.sqlite");
//    }
//    
#endif
    
    sqlPath=FileUtils::getInstance()->getWritablePath()+"Thimbelina.sqlite";
    
    if (db.open(sqlPath.c_str())) {
        log("opened");
    }else{
        log("can not open");
    }
    
    
    
    
}



void FirstScene::onCreateGameLayer(){
  _rootLayer=CSLoader::createNode("FirstScene.csb");
    if (_rootLayer==nullptr) {
        return;
    }
   addChild(_rootLayer);

    
    //播放动画? 无效？
    
    ActionTimeline* flyAction = CSLoader::createTimeline("FlyGirlSkeleton.csb");
    _rootLayer->runAction(flyAction);
    flyAction->gotoFrameAndPlay(0);
    
    
    auto firstUiLayerNode= _rootLayer->getChildByName("FirstUILayer_Node");
    
    Layout * panel_back=static_cast<Layout *>( firstUiLayerNode->getChildByName("Panel_Back"));
    
    
    Button *btn_start=static_cast<Button *>(panel_back->getChildByName("Button_Start"));
    btn_start->addClickEventListener(CC_CALLBACK_1(FirstScene::onClick, this));
    
    auto btn_helper=static_cast<Button *>(panel_back->getChildByName("Button_Help"));
    btn_helper->addClickEventListener(CC_CALLBACK_1(FirstScene::onClick, this));
    
    
    
    
    //添加云彩动画
    auto s=Sprite::create("small_cloud.png");
    addChild(s);
    s->setOpacity(196);
    
    auto actionA=Place::create(Vec2(0,visibleSize.height-100));
    auto actionB=MoveBy::create(20, Vec2(visibleSize.width,0));
    
    auto sequenceA=Sequence::create(actionA,actionB, NULL);
    
    s->runAction(RepeatForever::create(sequenceA));
    
    //添加蝴蝶A
    
    auto butterFlyA=CSLoader::createNode("ButterflyArmature_01.csb");
    addChild(butterFlyA);
    
    butterFlyA->setPosition(Vec2(visibleSize.width-100,0));
    
    auto butterFlyAAction=CSLoader::createTimeline("ButterflyArmature_01.csb");
    butterFlyA->runAction(butterFlyAAction);
    butterFlyAAction->gotoFrameAndPlay(0);
    
    
    _ccBezierConfig bezierConfigA,bzierConfigB;
    bezierConfigA.controlPoint_1=Vec2(0,0);
    bezierConfigA.controlPoint_2=Vec2(100,100);
    bezierConfigA.endPosition=Vec2(122,122);
    auto butterFlyAActionB=BezierBy::create(10, bezierConfigA);
    
    butterFlyA->runAction(butterFlyAActionB);
    
    
}



void FirstScene::onClick(Ref *sender){
    Button *view=dynamic_cast<Button  *>(sender);

    if (view==nullptr) {
        return;
    }
    
    switch (view->getTag()) {
        case 52:
            
            director->replaceScene(TransitionPageTurn::create(1.0f, FqaLayer::createScene(),false));
            
            break;
            
        case 2:
            
            break;
            
        case 3:
            
            break;
            
        default:
            break;
    }
    
}



bool FirstScene::init(){
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




void FirstScene::onEnter(){
  Layer::onEnter();
  onCreateGameLayer();

}



void FirstScene::onExit(){
    Layer::onExit();

}
