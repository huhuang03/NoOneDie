//
//  Edge.h
//  NoOneDie
//
//  Created by Tonghu_Yi on 8/7/14.
//
//

#ifndef __NoOneDie__Edge__
#define __NoOneDie__Edge__

#include <iostream>
#include <cocos2d.h>
USING_NS_CC;

class Edge:public Node {
    
public:
    virtual bool init();
    CREATE_FUNC(Edge);
};

#endif /* defined(__NoOneDie__Edge__) */
