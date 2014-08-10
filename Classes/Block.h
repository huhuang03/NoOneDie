//
//  Block.h
//  NoOneDie
//
//  Created by Tonghu_Yi on 8/10/14.
//
//

#ifndef __NoOneDie__Block__
#define __NoOneDie__Block__

#include <iostream>
#include <cocos2d.h>

USING_NS_CC;

class Block :public Sprite {
public:
    virtual bool init();
    CREATE_FUNC(Block);
    virtual void update(float dt);
    
};

#endif /* defined(__NoOneDie__Block__) */
