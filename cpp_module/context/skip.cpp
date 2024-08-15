#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string removeNumbersAndSubstringsBetweenSameNumbers(const string& str) {
    string result;
    unordered_map<string, size_t> numMap;  // Map to track the positions of numbers
    size_t i = 0;

    while (i < str.length()) {
        // Skip non-digit characters and add them to the result
        while (i < str.length() && !isdigit(str[i])) {
            result += str[i];
            ++i;
        }

        // Extract the number from the string
        string number;
        while (i < str.length() && isdigit(str[i])) {
            number += str[i];
            ++i;
        }

        if (!number.empty()) {
            // Check if the number has been seen before
            if (numMap.find(number) != numMap.end()) {
                // Remove the substring between the same numbers and the numbers themselves
                size_t prevPos = numMap[number];
                result = result.substr(0, prevPos);  // Keep content before the first occurrence
                numMap.clear();  // Reset the map for new numbers
            } else {
                // Record the position of the number
                numMap[number] = result.length();
            }
        }
    }

    return result;
}

int main() {
    string str = "reda mhmd 457 eid ahmed 457 mhmd ahmed";
    string result = removeNumbersAndSubstringsBetweenSameNumbers(str);
    cout << "Resulting string: " << result << endl;
    return 0;
}
