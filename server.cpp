#include <SFML/Network.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include <memory>  // shared_ptr kullanabilmek için

// Client bağlantısını işlemek için fonksiyon
void handleClient(std::shared_ptr<sf::TcpSocket> client) {
    char buffser[1024];
    std::size_t received;

    if (client->receive(buffser, sizeof(buffser), received) != sf::Socket::Done) {
        std::cerr << "Veri alınamadı!" << std::endl;
        return;
    }

    // Veriyi bir string'e dönüştür
    std::string receivedData(buffser, received);

    // Bilgisayar ismini ve dosya içeriğini ayrıştır
    size_t pos = receivedData.find("PC Adı: ");
    if (pos != std::string::npos) {
        // Bilgisayar ismini ayır
        size_t endPos = receivedData.find("\n", pos);
        std::string pcName = receivedData.substr(pos + 8, endPos - (pos + 8));

        std::cout << "Bağlantı alındı! PC Adı: " << pcName << std::endl;

        // Geriye kalan kısmı dosya içeriği olarak kabul et
        std::string fileContent = receivedData.substr(endPos + 1);
        
        // Dosya yolunu al
        std::string dosyaYolu = "C:/Users/ronit/Desktop/" + pcName + "'s feedback.txt";
        std::ofstream dosya(dosyaYolu, std::ios::binary);
        if (!dosya.is_open()) {
            std::cerr << "Dosya yazılamadı!" << std::endl;
            return;
        }

        dosya.write(fileContent.c_str(), fileContent.size());
        dosya.close();

        std::cout << "Dosya başarıyla feedback.txt'ye yazıldı!" << std::endl;
    } else {
        std::cerr << "Beklenen formatta veri alınamadı!" << std::endl;
    }
}

int main() {
    sf::TcpListener listener;

    // Sunucu belirli bir portu dinlemeye başlar
    if (listener.listen(54000) != sf::Socket::Done) {
        std::cerr << "Port dinlenemedi!" << std::endl;
        return 1;
    }

    std::cout << "Bağlantı bekleniyor (port 54000)..." << std::endl;

    while (true) {
        std::shared_ptr<sf::TcpSocket> client = std::make_shared<sf::TcpSocket>();

        // Bağlantı kabul edilir
        if (listener.accept(*client) != sf::Socket::Done) {
            std::cerr << "Bağlantı kabul edilemedi!" << std::endl;
            continue;  // Bağlantı kabul edilmezse bir sonraki client beklenir
        }

        std::cout << "Bağlantı alındı!" << std::endl;

        // Yeni client bağlantısı için yeni bir thread başlat
        std::thread clientThread(handleClient, client);  // pointer'ı geçiyoruz
        clientThread.detach();  // Detached thread, ayrı olarak çalışmaya devam eder
    }

    return 0;
}
