#pragma once
#include <SFML/Audio.hpp>
#include <string>

namespace Sound
{
	enum class SoundType
	{
		BALL_BOUNCE
	};

	class SoundManager
	{
	public:
		SoundManager();
		~SoundManager();

		void initialize();

		static void PlaySoundEffect(SoundType soundType);
		static void PlayBackgroundMusic();

	private:
		static sf::Music backgroundMusic;
		static sf::Sound soundEffect;
		static sf::SoundBuffer ballBounce;

		static float backgroundMusicVolume;
		static const std::string bgmPath;
		static const std::string ballBouncePath;

		static void LoadSoundFromFile();
	};
}