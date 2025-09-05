#include <iostream>
#include "StringProcessor.h"

int main() 
{
    const std::string str1 = "abc";
    const std::string str2 = "defgh";
    std::cout << "Interweave: " << StringProcessor::Interweave(str1, str2) << "\n";

    const std::string text = "hello world. this is a test! how are you?";
    std::cout << "Capitalize Words: " << StringProcessor::CapitalizeWords(text) << "\n";
    std::cout << "Capitalize Sentences: " << StringProcessor::CapitalizeSentences(text) << "\n";

    std::string replaced = StringProcessor::ReplaceAll(text, "test", "demo");
    std::cout << "Replace 'test' with 'demo': " << replaced << "\n";

    return 0;
}