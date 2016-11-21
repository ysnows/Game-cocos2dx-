//
//  SplashScene.h
//  Game
//
//  Created by 咸光金 on 2016/10/26.
//
//

#ifndef SplashScene_h
#define SplashScene_h

#include <stdio.h>

#include "cocos2d.h"
USING_NS_CC;


#include "editor-support/cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace ui;
using namespace cocostudio;
using namespace cocostudio::timeline;



#include "../base/BaseScene.h"

#include "FirstScene.h"

#include "SocketTestLayer.h"


class SplashScene:public BaseScene {
    
public:
    SplashScene(bool bPortrait);
    
    void switchToTargetScene(float dt);
    
    virtual void runThisScene();
    
    void callback0();
    
    
protected:
    void onFrameEvent(Frame *frame);
    
};

#endif /* SplashScene_hpp */
