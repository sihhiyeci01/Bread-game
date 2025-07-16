#pragma once
#include <vector>
#include <string>

struct TypedChar {
    char ch;
    int delayMs;
    bool isBackspace;
};

class Recorder {
public:
    void recordInput();                             // Klavye girişini al
    void playback() const;                          // Animasyonu ekrana oynat
    void saveToFile(const std::string& filename) const; // Veriyi dosyaya kaydet
    const std::vector<TypedChar>& getBuffer() const;    // Erişim için

private:
    std::vector<TypedChar> buffer;
};