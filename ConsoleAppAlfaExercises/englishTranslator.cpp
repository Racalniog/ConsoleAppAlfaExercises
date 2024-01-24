#include <iostream>
#include <fstream>
#include <map>
#include <string>

std::map<std::string, std::string> dictionary = {
    {"hello", "hallo"},
    {"world", "welt"},
};

std::string translateToGerman(const std::string& englishWord) {
    auto it = dictionary.find(englishWord);
    if (it != dictionary.end()) {
        return it->second; // Return the corresponding German translation
    }
    else {
        return "Translation not found";
    }
}

void saveTranslationsToFile(const std::map<std::string, std::string>& translations, const std::string& filename) {
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (const auto& entry : translations) {
            outputFile << entry.first << ": " << entry.second << "\n";
        }
        std::cout << "Translations saved to " << filename << std::endl;
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

void run() {
    std::map<std::string, std::string> translations;

    while (true) {
        std::string englishWord;

        std::cout << "Enter an English word (or type 'exit' to finish): ";
        std::cin >> englishWord;

        if (englishWord == "exit") {
            break;
        }

        std::string germanTranslation = translateToGerman(englishWord);

        std::cout << "German translation: " << germanTranslation << std::endl;

        translations[englishWord] = germanTranslation;
    }

    saveTranslationsToFile(translations, "translations.txt");
}
