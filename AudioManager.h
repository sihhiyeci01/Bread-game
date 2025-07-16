#pragma once

#include <SFML/Audio.hpp>
#include <filesystem>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <memory>
#include <string>
#include <thread>
#include <chrono>
#include <algorithm>

// Kısa erişim makroları
#define SM  SoundManager::instance()
#define SML SoundManager

class SoundManager {
public:
    // Singleton
    static SoundManager& instance() {
        static SoundManager mgr;
        return mgr;
    }

    // --- Efekt API ---
    static bool LoadEffect(const std::string& id, const std::string& filepath) {
        return instance().loadBuffer(id, filepath);
    }
    static bool PlayEffect(const std::string& id, bool loop = false, float volume = 100.f, float pitch = 1.f) {
        return instance().play(id, loop, volume, pitch);
    }
    static void StopEffect(const std::string& id) { instance().stop(id); }
    static void UnloadEffect(const std::string& id) { instance().unload(id); }
    static void SetEffectVolume(const std::string& id, float volume) {
        instance().setVolume(id, volume);
    }
    static void SetEffectPitch(const std::string& id, float pitch) {
        instance().setPitch(id, pitch);
    }

    // --- Müzik API ---
    static bool LoadMusic(const std::string& id, const std::string& filepath) {
        return instance().loadMusic(id, filepath);
    }
    static bool PlayMusic(const std::string& id, bool loop = true, float volume = 100.f, float pitch = 1.f) {
        return instance().playMusic(id, loop, volume, pitch);
    }
    static void StopMusic(const std::string& id) { instance().stopMusic(id); }
    static void UnloadMusic(const std::string& id) { instance().unloadMusic(id); }
    static void SetMusicVolume(const std::string& id, float volume) {
        instance().setMusicVolume(id, volume);
    }
    static void SetMusicPitch(const std::string& id, float pitch) {
        instance().setMusicPitch(id, pitch);
    }

    // --- Stop & Unload ---
    static void StopAndUnload(const std::string& id) {
        instance().stop(id);
        instance().unload(id);
        instance().stopMusic(id);
        instance().unloadMusic(id);
    }
    static void StopAndUnloadFile(const std::string& filename) {
        std::string id = getId(filename);
        StopAndUnload(id);
    }

    // --- Bekleme yardımcıları ---
    static void WaitEffect(const std::string& id) {
        auto& mgr = instance();
        auto it = mgr.sounds_.find(id);
        if (it != mgr.sounds_.end()) {
            for (auto& snd : it->second) {
                while (snd->getStatus() == sf::Sound::Playing)
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
        }
    }
    static void WaitMusic(const std::string& id) {
        auto& mgr = instance();
        auto it = mgr.musics_.find(id);
        if (it != mgr.musics_.end()) {
            while (it->second->getStatus() == sf::Music::Playing)
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
    static void WaitMusicUntil(const std::string& id, float targetSeconds) {
        auto& mgr = instance();
        auto it = mgr.musics_.find(id);
        if (it != mgr.musics_.end()) {
            auto& music = *it->second;
            while (music.getStatus() == sf::Music::Playing) {
                if (music.getPlayingOffset().asSeconds() >= targetSeconds) break;
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
            }
        }
    }

    // --- Fade In/Out (Effect & Music) ---
    static void FadeOutEffect(const std::string& id, float duration, int steps = 50) {
        auto& mgr = instance();
        auto it = mgr.sounds_.find(id);
        if (it == mgr.sounds_.end()) return;
        auto& sound = *it->second.front();
        float initial = sound.getVolume();
        float delta   = initial / steps;
        int wait      = int(duration * 1000 / steps);
        for (int i = 0; i < steps; ++i) {
            sound.setVolume(std::max(0.f, initial - delta * i));
            std::this_thread::sleep_for(std::chrono::milliseconds(wait));
        }
        StopAndUnload(id);
    }
    static void FadeOutMusic(const std::string& id, float duration, int steps = 50) {
        auto& mgr = instance();
        auto it = mgr.musics_.find(id);
        if (it == mgr.musics_.end()) return;
        auto& music = *it->second;
        float initial = music.getVolume();
        float delta   = initial / steps;
        int wait      = int(duration * 1000 / steps);
        for (int i = 0; i < steps; ++i) {
            music.setVolume(std::max(0.f, initial - delta * i));
            std::this_thread::sleep_for(std::chrono::milliseconds(wait));
        }
        StopAndUnload(id);
    }
    static void FadeInEffect(const std::string& id, float duration, float targetVolume = 100.f, int steps = 50) {
        auto& mgr = instance();
        auto it = mgr.sounds_.find(id);
        if (it == mgr.sounds_.end()) return;
        auto& sound = *it->second.front();
        sound.setVolume(0);
        sound.play();
        float delta = targetVolume / steps;
        int wait    = int(duration * 1000 / steps);
        for (int i = 0; i < steps; ++i) {
            sound.setVolume(delta * i);
            std::this_thread::sleep_for(std::chrono::milliseconds(wait));
        }
        sound.setVolume(targetVolume);
    }
    static void FadeInMusic(const std::string& id, float duration, float targetVolume = 100.f, int steps = 50) {
        auto& mgr = instance();
        auto it = mgr.musics_.find(id);
        if (it == mgr.musics_.end()) return;
        auto& music = *it->second;
        music.setVolume(0);
        music.play();
        float delta = targetVolume / steps;
        int wait    = int(duration * 1000 / steps);
        for (int i = 0; i < steps; ++i) {
            music.setVolume(delta * i);
            std::this_thread::sleep_for(std::chrono::milliseconds(wait));
        }
        music.setVolume(targetVolume);
    }
	
	// AudioManager.h içinde public bölüme ekleyin:

	/// Efekt bitince otomatik unload et (non-blocking)
	static void UnloadEffectWhenFinished(const std::string& id) {
		std::thread([id]() {
			auto& mgr = SoundManager::instance();
			// Bekle tüm sf::Sound nesneleri bitene kadar
			auto sit = mgr.sounds_.find(id);
			if (sit != mgr.sounds_.end()) {
				for (auto& sndPtr : sit->second) {
					while (sndPtr->getStatus() == sf::Sound::Playing) {
						std::this_thread::sleep_for(std::chrono::milliseconds(50));
					}
				}
			}
			// Bitince unload et
			mgr.unload(id);
		}).detach();
	}

	/// Müzik bitince otomatik unload et (non-blocking)
	static void UnloadMusicWhenFinished(const std::string& id) {
		std::thread([id]() {
			auto& mgr = SoundManager::instance();
			auto mit = mgr.musics_.find(id);
			if (mit != mgr.musics_.end()) {
				sf::Music& m = *mit->second;
				while (m.getStatus() == sf::Music::Playing) {
					std::this_thread::sleep_for(std::chrono::milliseconds(50));
				}
			}
			// Bitince unload et
			mgr.unloadMusic(id);
		}).detach();
	}


    static bool LoadEffectFile(const std::string& filename) {
        return LoadEffect(getId(filename), "sound/effect/" + filename);
    }
    static bool PlayEffectFile(const std::string& filename, bool loop = false, float volume = 100.f, float pitch = 1.f) {
        if (!LoadEffectFile(filename)) return false;
        return PlayEffect(getId(filename), loop, volume, pitch);
    }
    static bool LoadMusicFile(const std::string& filename) {
        return LoadMusic(getId(filename), "sound/music/" + filename);
    }
    static bool PlayMusicFile(const std::string& filename, bool loop = true, float volume = 100.f, float pitch = 1.f) {
        if (!LoadMusicFile(filename)) return false;
        return PlayMusic(getId(filename), loop, volume, pitch);
    }

    // --- Generic API ---
    static bool LoadFile(const std::string& filename) {
        return LoadMusicFile(filename) || LoadEffectFile(filename);
    }
    static bool PlayFile(const std::string& filename, bool loop = true, float volume = 100.f, float pitch = 1.f) {
        if (LoadMusicFile(filename))
            return PlayMusic(getId(filename), loop, volume, pitch);
        if (LoadEffectFile(filename))
            return PlayEffect(getId(filename), loop, volume, pitch);
        return false;
    }

    // --- Tek seferlik çalma (Update tabanlı) ---
    static bool PlayFileOnce(const std::string& filename, bool loop = false, float volume = 100.f, float pitch = 1.f) {
        namespace fs = std::filesystem;
        auto& inst = instance();
        const std::string id = getId(filename);
        const std::string musicPath  = "sound/music/"  + filename;
        const std::string effectPath = "sound/effect/" + filename;

        if (fs::exists(musicPath)) {
            inst.loadMusic(id, musicPath);
            inst.playMusic(id, loop, volume, pitch);
            inst.onceMusicIds_.insert(id);
            return true;
        }
        if (fs::exists(effectPath)) {
            inst.loadBuffer(id, effectPath);
            inst.play(id, loop, volume, pitch);
            inst.onceSoundIds_.insert(id);
            return true;
        }
        return false;
    }

    // --- Senkron bloklayıcı ---
    static void PlayFileBlocking(const std::string& filename, bool loop = false, float volume = 100.f, float pitch = 1.f) {
        auto& inst = instance();
        const std::string id = getId(filename);
        const std::string musicPath  = "sound/music/"  + filename;
        const std::string effectPath = "sound/effect/" + filename;
        namespace fs = std::filesystem;

        if (fs::exists(musicPath)) {
            inst.loadMusic(id, musicPath);
            inst.playMusic(id, loop, volume, pitch);
            auto& m = *inst.musics_[id];
            while (m.getStatus() == sf::Music::Playing)
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            inst.unloadMusic(id);
            return;
        }
        if (fs::exists(effectPath)) {
            inst.loadBuffer(id, effectPath);
            inst.play(id, loop, volume, pitch);
            auto& s = *inst.sounds_[id].front();
            while (s.getStatus() == sf::Sound::Playing)
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            inst.unload(id);
        }
    }

    // --- Toplu durdurma/temizleme ---
    static void StopAll()   { instance().stopAllSounds(); instance().stopAllMusic(); }
    static void UnloadAll() { instance().stopAllSounds(); instance().buffers_.clear(); instance().musics_.clear(); }

    // --- Update: PlayFileOnce ile işaretli sesleri temizler ---
    static void Update() { instance().updateImpl(); }

private:
    // Yardımcı: uzantısız ID
    static std::string getId(const std::string& name) {
        auto pos = name.find_last_of('.');
        return pos == std::string::npos ? name : name.substr(0, pos);
    }

    SoundManager() = default;
    ~SoundManager() = default;
    SoundManager(const SoundManager&) = delete;
    SoundManager& operator=(const SoundManager&) = delete;

    // Efekt altyapısı
    bool loadBuffer(const std::string& id, const std::string& filepath) {
        sf::SoundBuffer buf;
        if (!buf.loadFromFile(filepath)) return false;
        buffers_.emplace(id, std::move(buf));
        return true;
    }
    void unload(const std::string& id) {
        stop(id); buffers_.erase(id); sounds_.erase(id);
    }
    bool play(const std::string& id, bool loop, float volume, float pitch) {
        auto it = buffers_.find(id);
        if (it == buffers_.end()) return false;
        auto sound = std::make_unique<sf::Sound>(it->second);
        sound->setLoop(loop);
        sound->setVolume(volume);
        sound->setPitch(pitch);
        sound->play();
        auto& vec = sounds_[id];
        vec.push_back(std::move(sound));
        // Bitenleri temizle
        vec.erase(std::remove_if(vec.begin(), vec.end(),
                                 [](auto& s){ return s->getStatus()!=sf::Sound::Playing; }),
                  vec.end());
        return true;
    }
    void stop(const std::string& id) {
        auto it = sounds_.find(id);
        if (it!=sounds_.end()) {
            for (auto& s: it->second) s->stop();
            it->second.clear();
        }
    }
    void setVolume(const std::string& id, float v) {
        auto it = sounds_.find(id);
        if (it!=sounds_.end())
            for (auto& s: it->second) s->setVolume(v);
    }
    void setPitch(const std::string& id, float p) {
        auto it = sounds_.find(id);
        if (it!=sounds_.end())
            for (auto& s: it->second) s->setPitch(p);
    }
	void stopAllSounds() {
        for (auto& kv : sounds_) {
            for (auto& s : kv.second) s->stop();
        }
        sounds_.clear();
    }

    // Çalan tüm müzikleri durdur (bellekte kalırlar, sadece durdurur)
    void stopAllMusic() {
        for (auto& kv : musics_) {
            kv.second->stop();
        }
    }
    // Müzik altyapısı
    bool loadMusic(const std::string& id, const std::string& filepath) {
        auto music = std::make_unique<sf::Music>();
        if (!music->openFromFile(filepath)) return false;
        musics_.emplace(id, std::move(music));
        return true;
    }
    void unloadMusic(const std::string& id) {
        stopMusic(id); musics_.erase(id); onceMusicIds_.erase(id);
    }
    bool playMusic(const std::string& id, bool loop, float volume, float pitch) {
        auto it = musics_.find(id);
        if (it==musics_.end()) return false;
        auto& m = *it->second;
        m.setLoop(loop);
        m.setVolume(volume);
        m.setPitch(pitch);
        m.play();
        return true;
    }
    void stopMusic(const std::string& id) {
        auto it = musics_.find(id);
        if (it!=musics_.end()) it->second->stop();
    }
    void setMusicVolume(const std::string& id, float v) {
        auto it = musics_.find(id);
        if (it!=musics_.end()) it->second->setVolume(v);
    }
    void setMusicPitch(const std::string& id, float p) {
        auto it = musics_.find(id);
        if (it!=musics_.end()) it->second->setPitch(p);
    }

    // Update içeriği
    void updateImpl() {
        // Müzik temizleme
        for (auto it = onceMusicIds_.begin(); it != onceMusicIds_.end(); ) {
            auto mit = musics_.find(*it);
            if (mit==musics_.end() ||
                mit->second->getStatus()!=sf::Music::Playing)
            {
                unloadMusic(*it);
                it = onceMusicIds_.erase(it);
            } else ++it;
        }
        // Efekt temizleme
        for (auto it = onceSoundIds_.begin(); it != onceSoundIds_.end(); ) {
            auto sit = sounds_.find(*it);
            bool playing = false;
            if (sit!=sounds_.end()) {
                for (auto& s: sit->second) {
                    if (s->getStatus()==sf::Sound::Playing) {
                        playing = true;
                        break;
                    }
                }
            }
            if (!playing) {
                unload(*it);
                it = onceSoundIds_.erase(it);
            } else ++it;
        }
    }

    // Veri yapıları
    std::unordered_map<std::string, sf::SoundBuffer>                           buffers_;
    std::unordered_map<std::string, std::vector<std::unique_ptr<sf::Sound>>>   sounds_;
    std::unordered_map<std::string, std::unique_ptr<sf::Music>>                musics_;
    std::unordered_set<std::string> onceMusicIds_;
    std::unordered_set<std::string> onceSoundIds_;
};
