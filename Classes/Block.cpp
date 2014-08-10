//
//  Block.cpp
//  NoOneDie
//
//  Created by Tonghu_Yi on 8/10/14.
//
//

#include "Block.h"

bool Block::init() {
    Sprite::init();
    Size size = Size(rand() % 20 + 5, rand() % 30 + 10);
    Size visibleSize = Director::getInstance()->getVisibleSize();
    setPhysicsBody(PhysicsBody::createBox(size));
    setTextureRect(Rect(0, 0, size.width, size.height));
    setColor(Color3B(0, 0 , 0));
    
    setContentSize(size);
    
//    setPositionX(visibleSize.width + size.width / 2);
    setPositionX(visibleSize.width);
    getPhysicsBody()->setDynamic(false);
    
    scheduleUpdate();
    getPhysicsBody()->setContactTestBitmask(2);
    return true;
}

void Block::update(float dt) {
    setPositionX(getPositionX() - 3);
    if (getPositionX() < 0) {
        unscheduleUpdate();
        removeFromParent();
    }
}