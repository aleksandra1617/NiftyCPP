#pragma once

#include <string>

/**
 * @class StringProcessor
 * @brief A utility class providing various string manipulation functions.
 */
class StringProcessor {
public:
    /**
     * @brief Interweaves two strings character by character.
     *
     * Example:
     *   str1 = "abc", str2 = "defgh" -> "adbecfgh"
     *
     * @param str1 The first string.
     * @param str2 The second string.
     * @return A new string with characters interwoven from str1 and str2.
     */
    static std::string Interweave(const std::string& str1, const std::string& str2);

    /**
     * @brief Replaces all occurrences of a substring with another substring.
     *
     * Example:
     *   text = "hello world", search = "world", replace = "C++"
     *   -> "hello C++"
     *
     * @param text The input string (copied).
     * @param search The substring to search for.
     * @param replace The substring to replace with.
     * @return A new string with replacements applied.
     */
    static std::string ReplaceAll(std::string text, const std::string& search, const std::string& replace);

    /**
     * @brief Capitalizes the first letter of every word in the string.
     *
     * Words are separated by whitespace.
     *
     * Example:
     *   "hello world" -> "Hello World"
     *
     * @param text The input string.
     * @return A new string with every word capitalized.
     */
    static std::string CapitalizeWords(const std::string& text);

    /**
     * @brief Capitalizes the first letter of every sentence in the string.
     *
     * Sentences are detected by ending punctuation ('.', '!', '?').
     *
     * Example:
     *   "hello. how are you?" -> "Hello. How are you?"
     *
     * @param text The input string.
     * @return A new string with every sentence capitalized.
     */
    static std::string CapitalizeSentences(const std::string& text);
};