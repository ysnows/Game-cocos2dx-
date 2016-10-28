//
//  SplashScene.cpp
//  Game
//
//  Created by 咸光金 on 2016/10/26.
//
//

#include "SplashScene.h"



SplashScene::SplashScene(bool bPortrait){
    
    
}

void SplashScene::switchToTargetScene(float dt){
    director->replaceScene(TransitionFlipX::create(1.0f, TutorialLayer::createScene()));
}

 void SplashScene::runThisScene(){
     director->runWithScene(this);
     
     _rootLayer=CSLoader::createNode("SplashUILayer.csb");
     addChild(_rootLayer);
     
     ActionTimeline *action=CSLoader::createTimeline("SplashUILayer.csb");
     _rootLayer->runAction(action);
     action->gotoFrameAndPlay(0);
     
     
     
     Node *node=CSLoader::createNode("SplashAnimationSkeleton.csb");
     addChild(node);
     node->setPosition(visibleSize/2);
     
     
     switchToTargetScene(1.0f);
     
     
     
//     auto actionB=CSLoader::createTimeline("SplashAnimationSkeleton.csb");
//     node->runAction(actionB);
//     actionB->gotoFrameAndPlay(0,false);
     
//     actionB->setFrameEventCallFunc(CC_CALLBACK_1(SplashScene::onFrameEvent, this));
     
}

void SplashScene::callback0(){
    auto mushRoom=_rootLayer->getChildByName("Mushroom_Point");
    auto emitter=new ParticleSystemQuad();
    emitter->autorelease();
    std::string fileName="Particles/flower_blue.plist";
    emitter->initWithFile(fileName.c_str());

    addChild(emitter,10);
    
    emitter->setPosition(mushRoom->getPosition());
    emitter->setAutoRemoveOnFinish(true);
    
    scheduleOnce((SEL_SCHEDULE)&SplashScene::switchToTargetScene, 1.0f);
    
    
    
}



void SplashScene::onFrameEvent(Frame *frame){
    
    EventFrame *eFrame=dynamic_cast<EventFrame *>(frame);
    if (!eFrame) {
        return;
    }
    
    std::string str=eFrame->getEvent();
    
    if (str=="lastFrame") {
        //播放蝴蝶进入的动画
        auto node=CSLoader::createNode("ButterflyArmature_01.csb");
        addChild(node);
        node->setPosition(Vec2(visibleSize.width-100,0));
        
        auto actionA=CSLoader::createTimeline("ButterflyArmature_01.csb");
        node->runAction(actionA);
        actionA->gotoFrameAndPlay(0,true);
        
        auto mushRoom= _rootLayer->getChildByName("Mushroom_Point");
        
        auto sequence=Sequence::create(MoveTo::create(2.0f, mushRoom->getPosition()), CallFunc::create(CC_CALLBACK_0(SplashScene::callback0, this)),NULL);
        
        node->runAction(sequence);
        
        
        
    }
}

