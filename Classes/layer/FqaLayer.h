//
//  FqaLayer.h
//  Game
//
//  Created by 咸光金 on 2016/10/27.
//
//

#ifndef FqaLayer_h
#define FqaLayer_h

#include <stdio.h>

#include "cocos2d.h"
USING_NS_CC;

#include "editor-support/cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace ui;
using namespace cocostudio;
using namespace cocostudio::timeline;

using namespace std;



#include "TutorialLayer.h"

#include "FirstScene.h"


class FqaLayer :public Layer{

public:
    CREATE_FUNC(FqaLayer);
    virtual bool init();
    static Scene * createScene();

    virtual void onEnter();
    virtual void onExit();

    void onCreateGameLayer();

    void onClick(Ref *sender);

    void initThings();
    
    void setPageContent(int currentNum);
    
    

public:
    Size visibleSize;
    Director *director;
    Vec2 visibleOrigin;
    Node *_rootLayer;
    Layout *_rootLayout;
    
    
private:
    Text *text_q;
    Text *text_a;
    Text *text_number;

};



#endif /* FqaLayer_hpp */
