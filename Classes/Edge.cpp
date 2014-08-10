//
//  Edge.cpp
//  NoOneDie
//
//  Created by Tonghu_Yi on 8/7/14.
//
//

#include "Edge.h"

bool Edge::init() {
    Node::init();
    const Size visibleSize = Director::getInstance()->getVisibleSize();
    setPhysicsBody(PhysicsBody::createEdgeBox(visibleSize));
    setContentSize(visibleSize);
    return true;
}