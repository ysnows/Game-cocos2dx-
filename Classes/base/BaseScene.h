//
//  BaseScene.h
//  Game
//
//  Created by 咸光金 on 2016/10/26.
//
//

#ifndef BaseScene_h
#define BaseScene_h

#include <stdio.h>

#include "cocos2d.h"
USING_NS_CC;

class BaseScene:public Scene {
    
public:
    BaseScene(bool bPortrait=false);
    ~BaseScene(void);
    
    virtual void onEnter();
    virtual void onExit();
    
    virtual void runThisScene()=0;
    
public:
    Size visibleSize;
    Vec2 visibleOrigin;
    Director *director;
    Node *_rootLayer;
};

#endif /* BaseScene_hpp */
