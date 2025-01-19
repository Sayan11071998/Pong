#include "../../Header/Sound/SoundManager.h"
#include <iostream>

namespace Sound
{
	sf::SoundBuffer SoundManager::ballBounce;
	sf::Sound SoundManager::soundEffect;

	const std::string SoundManager::ballBouncePath = "Assets/Sounds/Ball_Bounce.wav";

	SoundManager::SoundManager() { initialize(); }

	SoundManager::~SoundManager()
	{
	}

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
	}

	void SoundManager::initialize() { LoadSoundFromFile(); }

	void SoundManager::LoadSoundFromFile()
	{
		if (!ballBounce.loadFromFile(ballBouncePath))
			std::cerr << "Error loading sound file: " << ballBouncePath << std::endl;
	}
}