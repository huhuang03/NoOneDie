//
//  GameController.cpp
//  NoOneDie
//
//  Created by Tonghu_Yi on 8/10/14.
//
//

#include "GameController.h"
#include "Edge.h"
#include "Block.h"

GameController* GameController::createWithHeight(cocos2d::Layer *layer, float height) {
    GameController * _ins = new GameController();
    _ins->_layer = layer;
    _ins->_height = height;
    _ins->init();
    _ins->autorelease();
//    _ins->init();
    return _ins;
}

void GameController::init() {
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    hero = Hero::create();
    hero->setPosition(Vec2(50, _height + hero->getContentSize().height / 2));
    _layer -> addChild(hero);
    
    Edge * edge = Edge::create();
    edge->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + _height));
    _layer -> addChild(edge);
    
    
    //add ground
    cocos2d::Sprite *sprite = cocos2d::Sprite::create();
    Size groundSize = Size(visibleSize.width, 2);
//    sprite->setContentSize(groundSize);
    sprite->setTextureRect(Rect(0, 0, groundSize.width, groundSize.height));
    sprite->setPosition(Vec2(groundSize.width/2, groundSize.height / 2 + _height));
    sprite->setColor(Color3B(0, 0, 0));
    _layer->addChild(sprite);
}

void GameController::resetFrame() {
    _currenFrame = 0;
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    
    _nextFrameCount = rand() % 200 + 100;
}

void GameController::update() {
//    log("<<<1update, %d, %d", _currenFrame, _nextFrameCount);
    _currenFrame++;
    if (_currenFrame >= _nextFrameCount) {
        resetFrame();
        addBlock();
    }
}

void GameController::addBlock() {
    Block *block = Block::create();
    block->setPositionY(_height + block->getContentSize().height / 2);
    _layer->addChild(block);
}

bool GameController::contains(cocos2d::Vec2 vec) {
    return hero->getBoundingBox().getMinY() < vec.y;
}

void GameController::jump() {
    hero->getPhysicsBody()->setVelocity(Vec2(0, 400));
}

bool GameController::isInGround() {
    log("bottom: %d" ,(int)hero->getBoundingBox().getMinY());
    return (int)hero->getBoundingBox().getMinY() == _height;
}
