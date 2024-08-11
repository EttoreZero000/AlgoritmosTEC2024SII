#include "stringUtils.h"
#include <algorithm> // Para std::transform

std::string StringUtil::toUpperCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}
std::string StringUtil::toLowerCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}
std::string StringUtil::removeVowels(const std::string& str) {
    std::string result;
    for (char c : str) {
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            result += c;
        }
    }
    return result;
}
std::string StringUtil::vocalesMayuscula(const std::string& str) {
    std::string result;
    for (char c : str) {
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            result += c;
        } else {
            std::string charAsString(1, c); // Convertir el char a std::string
            result += StringUtil::toUpperCase(charAsString);
        }
    }
    return result;
}
std::string StringUtil::consonantesMayuscula(const std::string& str) {
    std::string result;
    for (char c : str) {
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            std::string charAsString(1, c); // Convertir el char a std::string
            result += StringUtil::toUpperCase(charAsString);
        } else {
            result += c;
        }
    }
    return result;
}
std::string StringUtil::letrasMayuscula(const std::string& str, bool tipo) {
    std::string result;
    for (char c : str) {
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            if(!tipo){
                std::string charAsString(1, c); // Convertir el char a std::string
                result += StringUtil::toUpperCase(charAsString);
            }else{
                std::string charAsString(1,c);
                result += c;
            }
        } else {
            if(!tipo){
                result += c;
            }else{
                std::string charAsString(1, c); // Convertir el char a std::string
                result += StringUtil::toUpperCase(charAsString);
            }
        }
    }
    return result;
}