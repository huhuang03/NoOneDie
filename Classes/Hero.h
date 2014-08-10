//
//  Hero.h
//  NoOneDie
//
//  Created by Tonghu_Yi on 8/9/14.
//
//

#ifndef __NoOneDie__Hero__
#define __NoOneDie__Hero__

#include <iostream>
#include <cocos2d.h>
class Hero :public cocos2d::Sprite {
public:
    virtual bool init();
    CREATE_FUNC(Hero);
};

#endif /* defined(__NoOneDie__Hero__) */
