#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/GameStatsManager.hpp>

using namespace geode::prelude;

class $modify(PlayLayer) {
	void playEndAnimationToPos(cocos2d::CCPoint position) {
		bool origTestmode = this->m_isTestMode;
		this->m_isTestMode = true;
		PlayLayer::playEndAnimationToPos(position);
		this->m_isTestMode = origTestmode;
	}
	void playPlatformerEndAnimationToPos(cocos2d::CCPoint position) {
		bool origTestmode = this->m_isTestMode;
		this->m_isTestMode = true;
		PlayLayer::playPlatformerEndAnimationToPos(position);
		this->m_isTestMode = origTestmode;
	}
	void levelComplete() {
		bool origTestmode = this->m_isTestMode;
		this->m_isTestMode = true;
		PlayLayer::levelComplete();
		this->m_isTestMode = origTestmode;
	}
};

class $modify(GameStatsManager) {
	void setStat(char const* key, int value) {
		return;
	}
};