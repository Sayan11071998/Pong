#include "../../Header/Sound/SoundManager.h"
#include <iostream>

namespace Sound
{
	sf::Music SoundManager::backgroundMusic;
	sf::SoundBuffer SoundManager::ballBounce;
	sf::Sound SoundManager::soundEffect;

	const std::string SoundManager::ballBouncePath = "Assets/Sounds/Ball_Bounce.wav";
	const std::string SoundManager::bgmPath = "Assets/Sounds/Pong_BGM.mp3";

	float SoundManager::backgroundMusicVolume = 50.0f;

	SoundManager::SoundManager() { initialize(); }

	SoundManager::~SoundManager() { delete this; }

	void SoundManager::initialize() { LoadSoundFromFile(); }

	void SoundManager::PlaySoundEffect(SoundType soundType)
	{
		switch (soundType)
		{
		case Sound::SoundType::BALL_BOUNCE:
			soundEffect.setBuffer(ballBounce);
			break;
		default:
			std::cerr << "Invalid sound type" << std::endl;
			return;
		}

		soundEffect.play();
	}

	void SoundManager::PlayBackgroundMusic()
	{
		backgroundMusic.setLoop(true);
		backgroundMusic.setVolume(backgroundMusicVolume);
		backgroundMusic.play();
	}

	void SoundManager::LoadSoundFromFile()
	{
		if (!ballBounce.loadFromFile(ballBouncePath))
			std::cerr << "Error loading sound file: " << ballBouncePath << std::endl;

		if (!backgroundMusic.openFromFile(bgmPath))
			std::cerr << "Error loading sound file: " << bgmPath << std::endl;
	}
}