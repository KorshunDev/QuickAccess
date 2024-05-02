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
        auto squareMenu = CCMenu::create();
        this->addChild(menu);
        this->addChild(squareMenu);
        menu->setLayout(RowLayout::create());
        menu->setID("quick-access-menu");
        CCSize size = CCDirector::sharedDirector()->getWinSize();
        menu->setPosition((size.width / 2) - 100, 100.f);
        menu->setContentSize({350.f, 50.f});
        menu->setAnchorPoint({0.213, 0.500});
        menu->ignoreAnchorPointForPosition(false);
        squareMenu->setPosition((size.width / 2) - 200, 100.f);
        squareMenu->setContentSize({100.f, 100.f});
        squareMenu->setAnchorPoint({0.500, 0.500});
        squareMenu->ignoreAnchorPointForPosition(false);
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
        auto savedButton = CCMenuItemSpriteExtra::create(
                CircleButtonSprite::createWithSpriteFrameName("gj_folderBtn_001.png"),
                this,
                menu_selector(MyMenuLayer::onSaved)
        );
        auto profileButton = CCMenuItemSpriteExtra::create(
                CCSprite::createWithSpriteFrameName("GJ_profileButton_001.png"),
                this,
                menu_selector(MyMenuLayer::onMyProfile)
                );
        auto sentButton = CCMenuItemSpriteExtra::create(
                CircleButtonSprite::createWithSpriteFrameName("modBadge_01_001.png"),
                this,
                menu_selector(MyMenuLayer::onSent)
                );
        auto profileMenu = this->getChildByID("profile-menu");
        profileMenu->getChildByID("profile-button")->removeFromParent();
        this->getChildByID("player-username")->removeFromParent();
        this->getChildByID("profile-menu")->removeFromParent();
        menu->addChild(profileButton);
		menu->addChild(myLevels);
        menu->addChild(awarded);
        menu->addChild(hall_of_fame);
        menu->addChild(favouriteLevels);
        menu->addChild(savedButton);
        menu->addChild(sentButton);
        menu->updateLayout();
        awarded->setID("awarded-button"_spr);
		myLevels->setID("my-levels-button"_spr);
        hall_of_fame->setID("hall_of_fame_button"_spr);
        favouriteLevels->setID("favourite-levels-button"_spr);
        savedButton->setID("search-button"_spr);
        profileButton->setID("profile-button"_spr);
        sentButton->setID("sent-button"_spr);
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

    void onSaved(CCObject *sender) {
        auto searchObject = GJSearchObject::create(SearchType::SavedLevels);
        auto browserLayer = LevelBrowserLayer::scene(searchObject);
        auto transitionFade = CCTransitionFade::create(0.5, browserLayer);

        CCDirector::sharedDirector()->pushScene(transitionFade);
    }

    void onSent(CCObject *sender) {
        auto searchObject = GJSearchObject::create(SearchType::Sent);
        auto browserLayer = LevelBrowserLayer::scene(searchObject);
        auto transitionFade = CCTransitionFade::create(0.5, browserLayer);

        CCDirector::sharedDirector()->pushScene(transitionFade);
    }
};
