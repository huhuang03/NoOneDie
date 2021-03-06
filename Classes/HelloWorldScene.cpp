#include "HelloWorldScene.h"
#include "Hero.h"
#include "Block.h"
#include "GameOverScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
//    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vec2(0, -1000));
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !LayerColor::initWithColor(Color4B(255, 255, 255, 255)) )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
//    auto label = LabelTTF::create("Hello World", "Arial", 24);
//    
//    // position the label on the center of the screen
//    label->setPosition(Vec2(origin.x + visibleSize.width/2,
//                            origin.y + visibleSize.height - label->getContentSize().height));
//
//    // add the label as a child to this layer
//    this->addChild(label, 1);
//
//    // add "HelloWorld" splash screen"
//    auto sprite = Sprite::create("HelloWorld.png");
//
//    // position the sprite on the center of the screen
//    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
//
//    // add the sprite as a child to this layer
//    this->addChild(sprite, 0);
//    Edge * edge = Edge::create();
//    edge->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
//    addChild(edge);
//    
//    Hero *hero = Hero::create();
//    hero->setPosition(Vec2(50, 36));
//    addChild(hero);
//    
//    Block *block = Block::create();
//    block->setPositionY(block->getContentSize().height / 2);
//    addChild(block);
    
    _gcs.insert(0, GameController::createWithHeight(this, 40));
    _gcs.insert(0, GameController::createWithHeight(this, 200));
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = [this](Touch *t ,Event *e) {
        for (auto gc = _gcs.begin(); gc != _gcs.end(); gc++) {
            if ((*gc)->contains(t->getLocation())) {
                if (!(*gc)->isInGround()) {
                    break;
                }
                (*gc)->jump();
                break;
            }
        }
        return true;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    auto lister = EventListenerPhysicsContact::create();
    lister->onContactBegin = [this](PhysicsContact &contact) {
//        int mask1 = contact.getShapeA()->getBody()->getContactTestBitmask();
//        int mask2 = contact.getShapeB()->getBody()->getContactTestBitmask();
        this->unscheduleUpdate();
        CCDirector::getInstance()->replaceScene(GameOverScene::createScene());
        return true;
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(lister, this);
    scheduleUpdate();
    
    return true;
}

void HelloWorld::update(float delta) {
    for (auto gc = _gcs.begin(); gc != _gcs.end(); gc++) {
        (*gc)->update();
    }
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
