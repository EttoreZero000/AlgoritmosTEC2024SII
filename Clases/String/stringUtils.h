#ifndef STRINGUTIL_H
#define STRINGUTIL_H

#include <string>

class StringUtil {
public:
    static std::string toUpperCase(const std::string& str);
    static std::string toLowerCase(const std::string& str);
    static std::string removeVowels(const std::string& str);
    static std::string vocalesMayuscula(const std::string& str);
    static std::string consonantesMayuscula(const std::string& str);
    static std::string letrasMayuscula(const std::string& str, bool tipo);
};

#endif // STRINGUTIL_H
