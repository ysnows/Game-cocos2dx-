//
//  TutorialLayer.cpp
//  Game
//
//  Created by 咸光金 on 2016/10/27.
//
//

#include "TutorialLayer.h"


string guidText[] =
{
    "FreeCell is one of the famous solitaire games. \nThis game contains three areas: the column area at \nthe bottom,the free cell area at the upper left, and the \nhome cell area at the upper right area.",
    "Columns Area: A deck of cards, which is dealt face-up at beginning \nof the game.n Cards in the Columns can be moved between Columns only \nin descending order, (e.g. 4,3,2), and alternating colors, \n(e.g. red, back, red, black).",
    "Home Cells: Located in the upper-right corner of the screen. \nYou win the game by moving all of the cards to the Home Cells. \nAces must be moved to Home Cells first from the Columns. \nThen other cards of the same suit can be moved on top of \nthem in ascending order.",
    "Free Cells: Located in the upper-left corner of the screen. \nEach FreeCell can be used to temporarily hold any ONE card moved \nfrom the Columns. Cards in the FreeCells can be moved to \neither the Home Cells or back to the Columns.",
    "The object of FreeCell is to move all of the cards to \nthe Home Cells.",
    "Now you can continue to double-click indicated card to \nmove it Home (2 on 1).",
    "Yes, you can continue to double-click the indicated card \nto move it Home(3 on 2).",
    "Cards moved onto Columns must be the next lowest number, \nand the alternate color.",
    "Move cards from Column to Column to uncover cards that are \nable to move to the Home Cells.",
    "Now you can drag the 4 of Hearts onto the Home Cell.",//9
    "A stack of cards can be moved between Columns if they are in \ndescending order and alternating colors.",
    "Now continue to drag card 2 onto 3 as indicated.",//11
    "Empty Columns are useful as any card can be played on an \nempty Column.",//12
    ""
};
//文字提示双击的时候，双击下方的按钮是不管用的－－只能双击对应的扑克  2014.7.16//
string btnGuidText[]=
{
    "Continue",//0
    "Continue",
    "Continue",
    "Continue",
    "Double-click the indicated card",
    "Continue",
    "Continue",
    "Drag the card to the indicated Column",
    "Continue",
    "Drag the card to the indicated Home column",//9
    "Drag the series of cards to the indicated Column",//10
    "Continue",//11
    "Continue",//12
    ""
};
const char* pImageCards[16]={
    "Images/cards/di_1.png",
    "Images/cards/sp_3.png",
    "Images/cards/di_2.png",
    "Images/cards/sp_4.png",
    "Images/cards/sp_2.png",
    "Images/cards/cl_1.png",
    "Images/cards/he_4.png",
    "Images/cards/he_3.png",
    "Images/cards/sp_1.png",
    "Images/cards/cl_4.png",
    "Images/cards/cl_2.png",
    "Images/cards/he_2.png",
    "Images/cards/di_3.png",
    "Images/cards/di_4.png",
    "Images/cards/cl_3.png",
    "Images/cards/he_1.png"
};


void TutorialLayer::initThings() {


}

void TutorialLayer::onCreateGameLayer(){
  _rootLayer=CSLoader::createNode("TUTUILayer.csb");
  if (_rootLayer==nullptr) {
       return;
   }
   addChild(_rootLayer);
   _rootLayout=static_cast<Layout *>(_rootLayer->getChildByName("Panel_Back"));
 
    auto btn_ret=static_cast<Button *>(_rootLayout->getChildByName("Button_Ret"));
    btn_ret->addClickEventListener([this](Ref *sender){
//        director->replaceScene(TransitionPageTurn::create(1.0f, FqaLayer::createScene(),true));
//        client->send("{'action':'exit'}");
//        string content="{\"action\":\"exit\"}";
//        auto count= socket.Send(content.c_str(), strlen(content.c_str()));
//        log("count:%d",count);
//        client->disconnect();
        
        
         socket.Send("login", 5);
        
        
//        std::vector<std::string> headers;
//        HttpRequest *request=new HttpRequest();
//        request->setUrl("http://localhost/public/api/user/getUserInfo");
//        headers.push_back("uid:1");
//        request->setHeaders(headers);
//        request->setRequestType(HttpRequest::Type::GET);
        
//        std::string postData;
//        postData="phone=18354450969&pwd=123456";
//        request->setRequestData(postData.c_str(),strlen(postData.c_str()));
        
//        request->setResponseCallback([](HttpClient* client, HttpResponse* response){
//            auto charData=  response->getResponseData();
//            std::string res;
//            for (int i=0; i<charData->size(); i++) {
//                res+=(* charData)[i];
//            }
//            printf("%s",res.c_str());
//            
//        });
//        HttpClient::getInstance()->send(request);
        
    });
    
//    client=SocketIO::connect("ws://127.0.0.1:3001", *this);
//    client->on("testEvent", CC_CALLBACK_2(TutorialLayer::testevent, this));
    
//  addCards();
    connectServer();
    
}



// Socker连接
void TutorialLayer::connectServer()
{
    // 初始化
    // ODSocket socket;
    socket.Init();
    socket.Create(AF_INET, SOCK_STREAM, 0);
    
    // 设置服务器的IP地址，端口号
    // 并连接服务器 Connect
    const char* ip = "127.0.0.1";
    int port = 3012;
    bool result = socket.Connect(ip, port);
    
    // 发送数据 Send
    string content="{\"action\":\"exit\"}";
    auto count= socket.Send(content.c_str(), strlen(content.c_str()));
    
    if (result) {
        CCLOG("connect to server success!");
        // 开启新线程，在子线程中，接收数据
        std::thread recvThread = std::thread(&TutorialLayer::receiveData, this);
        recvThread.detach(); // 从主线程分离
    }
    else {
        CCLOG("can not connect to server");
        return;
    }
}

// 接收数据
void TutorialLayer::receiveData()
{
    // 因为是强联网
    // 所以可以一直检测服务端是否有数据传来
    while (true) {
        // 接收数据 Recv
        char data[512] = "";
        int result = socket.Recv(data, 512, 0);
        // 与服务器的连接断开了
        if (result <= 0) break;
        CCLOG("%s", data);
    }
    // 关闭连接
    socket.Close();
}



void TutorialLayer::onClick(Ref *sender){
  Button *view=dynamic_cast<Button  *>(sender);

  if (view==nullptr) {
      return;
  }

  switch (view->getTag()) {
      case 1:

          break;

      default:
          break;
  }
}

void TutorialLayer::addCards(){
    
    for (int i=0; i<16; i++) {
        _cardSprite[i]=Sprite::create(pImageCards[i]);
        _cardSprite[i]->retain();
        _rootLayer->addChild(_cardSprite[i],48,2000+i);
        _cardSprite[i]->setPosition(Vec2(visibleSize.width/2,visibleSize.height-30));
    }
   
    
//    img_1=static_cast<ImageView *>(_rootLayout->getChildByName("Bottom_P_01"));
//    img_2=static_cast<ImageView *>(_rootLayout->getChildByName("Bottom_P_02"));
//    img_3=static_cast<ImageView *>(_rootLayout->getChildByName("Bottom_P_03"));
//    img_4=static_cast<ImageView *>(_rootLayout->getChildByName("Bottom_P_04"));
//    
//    img_4->getPosition();
    
//    float x[4]{img_1->getWorldPosition().x,img_2->getWorldPosition().x,img_3->getWorldPosition().x,img_4->getWorldPosition().x};
//    float y=img_1->getWorldPosition().y;
    
    
    
//    Vector<FiniteTimeAction *> actions;
//    int pos=0;
//    for (int i=0; i<4; i++) {
//        for (int j=0; j<4; j++) {
//            pos++;
//            log("%d",pos);
//            
////            auto actionMove=MoveTo::create(0.2f, Vec2(x[i],y));
//            
//            
//            
//            
//            
//            
//        }
//    }
    
    
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

void TutorialLayer::testevent(cocos2d::network::SIOClient *client, const std::string& data){
    log("OK %s ",data.c_str());
}

void TutorialLayer::onConnect(network::SIOClient* client)
{
    log("SocketIOTest::onConnect called");
}

void TutorialLayer::onMessage(network::SIOClient* client, const std::string& data)
{
    log("SocketIOTest::onMessage received: %s", data.c_str());
}

void TutorialLayer::onClose(network::SIOClient* client)
{
    log("SocketIOTest::onClose called");
}

void TutorialLayer::onError(network::SIOClient* client, const std::string& data)
{
    log("SocketIOTest::onError received: %s", data.c_str());
}


