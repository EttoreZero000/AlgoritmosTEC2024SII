#include <iostream>
#include <string>
#include <algorithm> // Para std::transform
#include <sstream>
std::string upper(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}
std::string lower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}
int countSpaces(const std::string& str) {
    return std::count(str.begin(), str.end(), ' ');
}
int countWords(const std::string& str) {
    std::istringstream iss(str);
    std::string word;
    int count = 0;
    while (iss >> word) {
        ++count;
    }
    return count;
}
std::string removeVowels(const std::string& str) {
    std::string result;
    for (char c : str) {
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            result += c;
        }
    }
    return result;
}
int main() {
    std::string text = "Hola Mundo";
    std::cout << "Mayúsculas: " << upper(text) << std::endl;
    std::cout << "Minúsculas: " << lower(text) << std::endl;
    std::cout << "Contar espacios: " << countSpaces(text) << std::endl;
    std::cout << "Cantidad de palabras: " << countWords(text) << std::endl;
    std::cout << "Sin vocales: " << removeVowels(text) << std::endl;
    return 0;
}
