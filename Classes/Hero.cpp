//
//  Hero.cpp
//  NoOneDie
//
//  Created by Tonghu_Yi on 8/9/14.
//
//

#include "Hero.h"
#include "FlashTool.h"

bool Hero::init() {
    Sprite::init();
    runAction(RepeatForever::create(FlashTool::readJsonSpriteSheet("Hero.json", 0.2f)));
    PhysicsMaterial *pysic = new PhysicsMaterial();
    pysic->restitution = 0;
    setPhysicsBody(PhysicsBody::createBox(Size(44, 52), *pysic));
    
    setContentSize(Size(44, 52));
    getPhysicsBody()->setRotationEnable(false);
    getPhysicsBody()->setContactTestBitmask(2);
    return true;
}