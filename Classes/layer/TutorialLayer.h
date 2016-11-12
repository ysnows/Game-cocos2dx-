//
//  TutorialLayer.h
//  Game
//
//  Created by 咸光金 on 2016/10/27.
//
//

#ifndef TutorialLayer_h
#define TutorialLayer_h

#include <stdio.h>

#include "cocos2d.h"
USING_NS_CC;

#include "editor-support/cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "FqaLayer.h"

#include "network/HttpClient.h"
using namespace network;

#include "network/SocketIO.h"

#include "ODSocket.h"



using namespace ui;
using namespace cocostudio;
using namespace cocostudio::timeline;


class TutorialLayer :public Layer ,public SocketIO::SIODelegate {

public:
    CREATE_FUNC(TutorialLayer);
    virtual bool init();
    static Scene * createScene();

    virtual void onEnter();
    virtual void onExit();

    void onCreateGameLayer();

    void onClick(Ref *sender);

    void initThings();
    
    

public:
    
    void addCards();
    
    //SocketIO
    virtual void onConnect(cocos2d::network::SIOClient* client);
    virtual void onMessage(cocos2d::network::SIOClient* client, const std::string& data);
    virtual void onClose(cocos2d::network::SIOClient* client);
    virtual void onError(cocos2d::network::SIOClient* client, const std::string& data);
    void testevent(cocos2d::network::SIOClient *client, const std::string& data);
    
    
    void connectServer();
    void receiveData();
    
    
public:
    Size visibleSize;
    Director *director;
    Vec2 visibleOrigin;
    Node *_rootLayer;
    Layout *_rootLayout;
    
protected:
    Sprite* _cardSprite[16];
    
    ImageView *img_1;
    ImageView *img_2;
    ImageView *img_3;
    ImageView *img_4;
    
    SIOClient *client;
    
    ODSocket socket;
    
};



#endif /* TutorialLayer_hpp */
