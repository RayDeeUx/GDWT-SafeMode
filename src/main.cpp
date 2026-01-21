#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/GJGameLevel.hpp>
#include <Geode/modify/GameStatsManager.hpp>
#include <Geode/modify/CurrencyRewardLayer.hpp>

using namespace geode::prelude;

class $modify(PlayLayer) {
	void playEndAnimationToPos(cocos2d::CCPoint position) {
		bool origTestmode = this->m_isTestMode;
		int origOrbs = this->m_orbs;
		int origDiamonds = this->m_diamonds;

		this->m_isTestMode = true;
		this->m_orbs = 0;
		this->m_diamonds = 0;

		PlayLayer::playEndAnimationToPos(position);

		this->m_isTestMode = origTestmode;
		this->m_orbs = origOrbs;
		this->m_diamonds = origDiamonds;
	}
	void playPlatformerEndAnimationToPos(cocos2d::CCPoint position, bool p0) {
		bool origTestmode = this->m_isTestMode;
		int origOrbs = this->m_orbs;
		int origDiamonds = this->m_diamonds;

		this->m_isTestMode = true;
		this->m_orbs = 0;
		this->m_diamonds = 0;

		PlayLayer::playPlatformerEndAnimationToPos(position, p0);

		this->m_isTestMode = origTestmode;
		this->m_orbs = origOrbs;
		this->m_diamonds = origDiamonds;
	}
	void levelComplete() {
		bool origTestmode = this->m_isTestMode;
		int origDiamonds = this->m_diamonds;
		int origOrbs = this->m_orbs;

		this->m_isTestMode = true;
		this->m_orbs = 0;
		this->m_diamonds = 0;

		PlayLayer::levelComplete();

		this->m_isTestMode = origTestmode;
		this->m_orbs = origOrbs;
		this->m_diamonds = origDiamonds;
	}
	void postUpdate(float dt) {
		int origOrbs = this->m_orbs;
		int origDiamonds = this->m_diamonds;

		this->m_orbs = 0;
		this->m_diamonds = 0;

		PlayLayer::postUpdate(dt);

		this->m_orbs = origOrbs;
		this->m_diamonds = origDiamonds;
	}
	void showNewBest(bool newReward, int orbs, int diamonds, bool demonKey, bool noRetry, bool noTitle) {
		return;
	}
};

class $modify(GameStatsManager) {
	void setStat(char const* key, int value) {
		return;
	}
};

class $modify(GJGameLevel) {
	void savePercentage(int percent, bool isPracticeMode, int clicks, int attempts, bool isChkValid) {
		return;
	}
};

class $modify(CurrencyRewardLayer) {
	bool init(int orbs, int stars, int moons, int diamonds, CurrencySpriteType demonKey, int keyCount, CurrencySpriteType shardType, int shardsCount, cocos2d::CCPoint position, CurrencyRewardType rewardType, float yOffset, float time) {
		if (!CurrencyRewardLayer::init(0, 0, 0, 0, demonKey, 0, shardType, 0, position, rewardType, yOffset, time)) return false;
		this->m_orbs = 0;
		this->m_stars = 0;
		this->m_moons = 0;
		this->m_diamonds = 0;
		this->m_keys = 0;
		this->m_shards = 0;
		return true;
	}
};