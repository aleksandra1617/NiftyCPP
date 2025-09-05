#include "StringProcessor.h"
#include <algorithm>
#include <cctype>

std::string StringProcessor::Interweave(const std::string& str1, const std::string& str2) 
{
    std::string result;
    size_t i = 0, j = 0;

    while (i < str1.size() && j < str2.size()) 
    {
        result.push_back(str1[i++]);
        result.push_back(str2[j++]);
    }

    if (i < str1.size()) result.append(str1.substr(i));
    if (j < str2.size()) result.append(str2.substr(j));

    return result;
}


std::string StringProcessor::ReplaceAll(std::string text, const std::string& search, const std::string& replace) 
{
    if (search.empty()) return text;
    size_t pos = 0;

    while ((pos = text.find(search, pos)) != std::string::npos) 
    {
        text.replace(pos, search.size(), replace);
        pos += replace.size();
    }

    return text;
}


std::string StringProcessor::CapitalizeWords(const std::string& text) 
{
    std::string result = text;
    bool capitalize = true;

    for (size_t i = 0; i < result.size(); ++i) 
    {
        if (std::isspace(static_cast<unsigned char>(result[i]))) 
        {
            capitalize = true;
        }
        else if (capitalize && std::isalpha(static_cast<unsigned char>(result[i]))) 
        {
            result[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(result[i])));
            capitalize = false;
        }
    }

    return result;
}

std::string StringProcessor::CapitalizeSentences(const std::string& text) 
{
    std::string result = text;
    bool capitalize = true;

    for (size_t i = 0; i < result.size(); ++i) 
    {
        if (capitalize && std::isalpha(static_cast<unsigned char>(result[i]))) 
        {
            result[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(result[i])));
            capitalize = false;
        }

        if (result[i] == '.' || result[i] == '!' || result[i] == '?') {
            capitalize = true;
        }
    }

    return result;
}
