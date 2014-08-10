//
//  GameOverScene.h
//  NoOneDie
//
//  Created by Tonghu_Yi on 8/10/14.
//
//

#ifndef __NoOneDie__GameOverScene__
#define __NoOneDie__GameOverScene__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class GameOverScene: public LayerColor{
public:
    virtual bool init(){
        LayerColor::initWithColor(Color4B::WHITE);
        Size visibleSize = Director::getInstance()->getVisibleSize();
        
        Label *l = Label::create();
        l->setSystemFontSize(40);
        l->setString("Game Over!!");
        l->setColor(Color3B::BLACK);
        l->setTextColor(Color4B::BLACK);
        l->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
        log("here");
        addChild(l);
        return true;
    };
    
    CREATE_FUNC(GameOverScene);
    
    static Scene * createScene() {
        Scene *s = Scene::create();
        Layer *layer = GameOverScene::create();
        s->addChild(layer);
        return s;
    }
};


#endif /* defined(__NoOneDie__GameOverScene__) */
