//
//  FirstScene.h
//  Game
//
//  Created by 咸光金 on 2016/10/26.
//
//

#ifndef FirstScene_h
#define FirstScene_h

#include <stdio.h>

#include "cocos2d.h"
USING_NS_CC;

#include "editor-support/cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace ui;
using namespace cocostudio;
using namespace cocostudio::timeline;

#include "../SQLiteDatabase/SQLiteDatabase.h"

//#include "../helper/FileHelper.h"

#include "FqaLayer.h"

class FirstScene :public Layer {

public:
    CREATE_FUNC(FirstScene);
    virtual bool init();
    static Scene * createScene();

    virtual void onEnter();
    virtual void onExit();
    
    void onCreateGameLayer();
    
    void onClick(Ref *sender);
    
    void initThings();
    
    
public:
    Size visibleSize;
    Director *director;
    Vec2 visibleOrigin;
    Node *_rootLayer;

};



#endif /* FirstScene_hpp */
