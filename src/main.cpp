#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/ui/BasedButtonSprite.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}
        auto menu = CCMenu::create();
        this->addChild(menu);
        menu->setLayout(RowLayout::create());
        menu->setID("quick-access-menu");
        CCSize size = CCDirector::sharedDirector()->getWinSize();
        menu->setPosition((size.width / 2) - 100, 100.f);
        menu->setContentSize({350.f, 50.f});
        menu->setAnchorPoint({0.200, 0.500});
        menu->ignoreAnchorPointForPosition(false);
        auto spr = CCSprite::createWithSpriteFrameName("GJ_myServerBtn_001.png");
		auto myLevels = CCMenuItemSpriteExtra::create(
        spr,
			this,
            menu_selector(MyMenuLayer::onMyLevels)
		);
        auto awarded = CCMenuItemSpriteExtra::create(
                CCSprite::createWithSpriteFrameName("GJ_starBtn_001.png"),
                this,
                menu_selector(MyMenuLayer::onAwarded)
                );
        auto hall_of_fame = CCMenuItemSpriteExtra::create(
                CCSprite::createWithSpriteFrameName("GJ_viewListsBtn_001.png"),
                this,
                menu_selector(MyMenuLayer::onHallOfFame)
                );
        auto favouriteLevels = CCMenuItemSpriteExtra::create(
                CircleButtonSprite::createWithSpriteFrameName("gj_heartOn_001.png"),
                this,
                menu_selector(MyMenuLayer::onFavouriteLevels)
                );
		menu->addChild(myLevels);
        menu->addChild(awarded);
        menu->addChild(hall_of_fame);
        menu->addChild(favouriteLevels);
        menu->updateLayout();
        awarded->setID("awarded-button");
		myLevels->setID("my-levels-button");
        hall_of_fame->setID("hall_of_fame");
        favouriteLevels->setID("favourite-levels");
		return true;
	}

	void onMyLevels(CCObject* sender) {
        auto searchObject = GJSearchObject::create(SearchType::MyLevels);
        auto browserLayer = LevelBrowserLayer::scene(searchObject);

        auto transitionFade = CCTransitionFade::create(0.5, browserLayer);

        CCDirector::sharedDirector()->pushScene(transitionFade);
	}
    void onAwarded(CCObject *sender) {
        auto searchObject = GJSearchObject::create(SearchType::Awarded);
        auto browserLayer = LevelBrowserLayer::scene(searchObject);

        auto transitionFade = CCTransitionFade::create(0.5, browserLayer);

        CCDirector::sharedDirector()->pushScene(transitionFade);
    }

    void onHallOfFame(CCObject *sender) {
        auto searchObject = GJSearchObject::create(SearchType::HallOfFame);
        auto browserLayer = LevelBrowserLayer::scene(searchObject);

        auto transitionFade = CCTransitionFade::create(0.5, browserLayer);

        CCDirector::sharedDirector()->pushScene(transitionFade);
    }

    void onFavouriteLevels(CCObject *sender) {
        auto searchObject = GJSearchObject::create(SearchType::FavouriteLevels);
        auto browserLayer = LevelBrowserLayer::scene(searchObject);

        auto transitionFade = CCTransitionFade::create(0.5, browserLayer);

        CCDirector::sharedDirector()->pushScene(transitionFade);
    }
};
