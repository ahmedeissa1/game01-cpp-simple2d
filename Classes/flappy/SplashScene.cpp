#include "flappy/SplashScene.h"
#include "flappy/MainMenuScene.h"
#include "flappy/Definitions.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace flappy;

Scene* SplashScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SplashScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SplashScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect( "flappy/Sounds/Hit.mp3" );
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect( "flappy/Sounds/Point.mp3" );
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect( "flappy/Sounds/Wing.mp3" );

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    this->scheduleOnce( schedule_selector( SplashScene::GoToMainMenuScene ), DISPLAY_TIME_SPLASH_SCENE );

    auto backgroundSprite = Sprite::create("flappy/Splash Screen.png");
    backgroundSprite->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );

    this->addChild(backgroundSprite);

    return true;
}

void SplashScene::GoToMainMenuScene( float dt )
{
	auto scene = MainMenuScene::createScene();

	Director::getInstance()->replaceScene( TransitionFade::create( TRANSITION_TIME, scene ) );
}



