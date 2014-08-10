//
//  GameController.h
//  NoOneDie
//
//  Created by Tonghu_Yi on 8/10/14.
//
//

#ifndef __NoOneDie__GameController__
#define __NoOneDie__GameController__

#include <iostream>
#include <cocos2d.h>
#include "Hero.h"

class GameController: public cocos2d::Ref {
private:
    float _height;
    int _currenFrame;
    int _nextFrameCount;
    cocos2d::Layer * _layer;
    Hero *hero;

    virtual void resetFrame();
    virtual void addBlock();
    
public:
    static GameController * createWithHeight(cocos2d::Layer *layer, float height);
    virtual void init();
    virtual void update();
    bool contains(cocos2d::Vec2 vec);
    void jump();
    bool isInGround();
};

#endif /* defined(__NoOneDie__GameController__) */
