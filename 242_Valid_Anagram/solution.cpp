#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Input: s = "anagram", t = "nagaram"
Output: true
---------
Input: s = "rat", t = "car"
Output: false
*/
class Solution {
public:
    bool isAnagram(const string& s, const string& t) {
        // Анаграммы обязаны быть одной длины
        if (s.length() != t.length()){
            return false;
        }

        // По условию только 26 строчных букв. 
        // Вектор на 26 элементов работает быстрее, чем unordered_map, тк нет не тратим время на хэширование
        vector<int> char_counts(26, 0);

        // Перебираем символы обоих строк одновременно для ускорения
        for (size_t i = 0; i < s.length(); ++i){
            // Вычисляем индекс от 0 до 25 через сдвиг ASCII-кода относительно 'a'
            char_counts[s[i] - 'a']++;
            char_counts[t[i] - 'a']--;
        }

        // Если строки анаграммы, то счетчики должны остаться нулевыми
        for (int count : char_counts){
            if (count != 0){
                return false;
            }
        }

        return true;
        
    }
};

int main() {
    string s = "rat";
    string t = "cat";
    Solution solution;
    bool result = solution.isAnagram(s, t);
    cout << "Result: " << boolalpha << result << endl; 
    return 0;
}