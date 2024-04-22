#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>

void CrashThisGame() {
	*(int*)0 = 0;
}

class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}

		auto crashButton = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_dislikeBtn_001.png"),
			this,
			menu_selector(MyMenuLayer::onCrashButton)
		);

		auto menu = this->getChildByID("bottom-menu");
		menu->addChild(crashButton);

		crashButton->setID("crash-button"_spr);

		menu->updateLayout();

		return true;
	}

	void onCrashButton(CCObject*) {
		CrashThisGame();
	}
};
