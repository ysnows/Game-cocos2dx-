    //
//  FqaLayer.cpp
//  Game
//
//  Created by 咸光金 on 2016/10/27.
//
//

#include "FqaLayer.h"


//#include "vld.h"
//本部分学习时主要把握一点：多语言内容在标签控件中显示的技巧。
//借助于定义于globals.h中的a2u函数把可能的中文ASCII内容转换成UTF-8格式，最终为ANDROID所正确显示。
//当然，在本部分中，为了简化起见，我直接使用了最简单的ENGLISH内容。对于这些串中有中文内容时，a2u函数便派上用场
//看起来，Label控件的使用细节需要进一步分析//
const string questions[13] =
{
    "What should I do when I am stuck on a level?",
    "Why do cards sometimes move to the Home Cells automatically?",
    "What is a 'Flurry'?",
    "Is there a way to highlight less cards to move?",
    "Why can I move big stacks of cards only some of the time?",
    "What is the arch of roses?",
    "How can I complete levels faster?",
    "What are the objects and characters above the rose arch?",
    "My Power-Up does not work anymore, what is going on?",
    "What are the yellow flashing cards that appear sometimes?",
    "What are missions?",
    "How can I complete a mission faster?",
    "Can I replay levels?"
};
const string answers[13] =
{
    "1.Try using a Power-Up to create a move.\n2.Try clicking the Hint button found in the lower left\n corner of the screen.\n3.At anytime you may request a different deal by clicking the\n Menu button and selecting New Deal.",
    "This is an auto-complete feature that places cards\n in the Home Cells for you.",
    "A Flurry records the longest _String of cards moved with the\n auto-complete feature.\nBigger Flurries reward you with higher Scores; you can observe\n this by watching the Scores that appear above the Home Cells\n during an auto-complete.\n To get bigger Flrries, organize your Columns, organize your\n Columns before putting cards in the Home Cells.",
    "Use the RIGHT mouse button to click on the card\n you wish to highlight.",
    "If you can't move a stack of cards it's generally because\n your FreeCells are full.\nThe size of a card stack you can move is determined by\n the number of empty FreeCells and empty Columns.\nWith the Caterpillar Power-Up you can move a stack of ANY size,\neven if your FreeCells are full.",
    "The Wonder-Meter is the arch of roses at the bottom\n of the screen.\n To complete a level, you must fill the Wonder-Meter with\n Red roses.\n Roses are turned Red by scoring points.",
    "Earning high Scores each deal will fill the Wonder-Meter\n with Red roses faster.\n1.Arrange your Columns for larger Flurries.\n2.Complete Mad Hatter events when they occur.\n3.On levels that have Wonder-Cards, collect as many as possible.\n4.Use your Power-Ups to help you with the above mentioned tips.",
    "There are seven Power-Ups to purchase by collecting Hearts.\nEach Power-Up has a special ability that helps\n complete deals.Visit theStore to learn more.",
    "All Power-Ups have a limited number of uses.\nFinding 'Drink Me' potions and teapots refill these uses.\nYou can also visit the Store and buy a Refill with your Hearts.",
    "Wonder-Cards flash yellow and award an extra Score when moved to \na Home Cell.\nWonder-Cards appear one at a time, with the next card appearing\n after the first has been moved to a Home Cell.\nWonder-Cards The more\nWonder-Cards you collect, the higher the Score you receive.",
    "There are six missions to complete. They are unlocked by playing\nStory Mode. Each mission requires you to find three 'Mission Pieces'.\n Mission Pieces are hidden behind random Columns, appearing only\n after the Column has been cleared. Mission Pieces are rare but can be found on ANY deal, including Story Mode, Quick-Play, Challenge,\nClassic and Custom levels.",
    "Earn enough Hearts to buy the Jabberwocky Power-Up and it's\nupgrades. This increases the chance that a mission piece\n will appear on any given deal.",
    "Yes, levels can be replayed by selecting 'Quick-Play'.\n This is a good way to get any bonuses you might have missed."
};
//先不考虑这种信息//
const string tipsAndtricks[14] =
{
    "Still not sure how to play? Click the Play Tutorial button found on the\nbottom right corner of this screen",
    "If you are stuck, try using the Hint button located on the bottom left\n corner of the game screen",
    "Move your Aces to the Home Cells first, then the 2's the 3's and so\n on.",
    "Instead of moving cards to the Home Cells first, focus on organizing/n the Columns. You'll get bigger Flurry Scores.",
    "When Wonder-Cards appear in a level, try moving them to the Home\n Cells as soon as possible.\n4.Use This will cause more Wonder-Cards to\n appear, with bigger Scores each time.",
    "Complete the Mad Hatter events when they occur for extra Score and Hearts.",
    "If you are stuck, trying going back a few moves with the Pocket Watch\n to try alternate strategies.",
    "Use the Fan to bring Aces (or other needed cards) to the front of a/n Column.",
    "Place the Lizard's Wild-Card on a Column so that any card or stack of\n cards can be moved there.",
    "Use the Caterpillar to move big stacks of cards when your FreeCells\n are full.",
    "Use the Dodo to grab Aces, (or other needed cards), when they are at the back of a Column.",
    "Bring the Cheshire Cat out for an extra spot to stack your cards. He's\n like a Column that you can move!",
    "Use the Stop Watch to create longer Flurries.\n1.Click the Stop Watch to undo a move that causes a flurry.\n2.Now see if you can organize more of the cards; use your\nPower-Ups for the best results.\n3.Repeat the move that sets off the Flurry and watch your scores\n soar.\n Flurries help you finish levels faster.",
    "Use your Power-Ups to collect more Wonder-Cards.\n1.Use the Fan to bring Wonder-Cards to the front of the Column.\n2.Use your Power-Ups to focus on placing Wonder-Cards in the\nHome Cells before other cards.\nIt is possible to complete a level with just one deal, if you collect enough Wonder-Cards."
};


int currentNum=0;

void FqaLayer::initThings() {
    
    
    
    


}




void FqaLayer::onCreateGameLayer(){
  _rootLayer=CSLoader::createNode("FAQUILayer.csb");
  if (_rootLayer==nullptr) {
       return;
   }
   addChild(_rootLayer);
    
    _rootLayout=static_cast<Layout *>(_rootLayer->getChildByName("Panel_Back"));
    
     text_q=static_cast<Text *>(_rootLayout->getChildByName("TextArea_Q"));
     text_a=static_cast<Text *>(_rootLayout->getChildByName("TextArea_A"));
     text_number=static_cast<Text *>(_rootLayout->getChildByName("Label_Number"));
    
     setPageContent(currentNum);
    
    
    auto btn_tutorial=static_cast<Button *>(_rootLayout->getChildByName("Button_Tut"));
    btn_tutorial->addClickEventListener([this](Ref *sender){
        director->replaceScene(TransitionPageTurn::create(1.0f, TutorialLayer::createScene(),false));
    });
    
    
    auto btn_ret=dynamic_cast<Button *>(_rootLayout->getChildByName("Button_Ret"));
    btn_ret->addClickEventListener([this](Ref *sender){
        director->replaceScene(TransitionPageTurn::create(1.0f, FirstScene::createScene(),true));
    });
    
    
    auto btn_forward=static_cast<Button *>(_rootLayout->getChildByName("Button_Forward"));
    btn_forward->addClickEventListener([this](Ref *sender){
        currentNum++;
        if (currentNum>13) {
            return ;
        }
        setPageContent(currentNum);
    });
    
    auto btn_back=static_cast<Button *>(_rootLayout->getChildByName("Button_Back"));
    btn_back->addClickEventListener([this](Ref *sender){
        
        currentNum--;
        if (currentNum<0) {
            return ;
        }
         setPageContent(currentNum);
    });
    
}


void FqaLayer::setPageContent(int currentNum){
    text_number->setString(__String::createWithFormat("%d",currentNum+1)->getCString());
    text_q->setString(questions[currentNum]);
    text_a->setString(answers[currentNum]);
}


void FqaLayer::onClick(Ref *sender){
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


bool FqaLayer::init(){
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
