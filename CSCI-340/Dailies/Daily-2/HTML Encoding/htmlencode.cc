#include <iostream>
#include <string>

int main() {
    std::string input;
    char c;

    while (std::cin.get(c)) {
        switch (c) {
            case '&':
                input += "&amp;";
                break;
            case '<':
                input += "&lt;";
                break;
            case '>':
                input += "&gt;";
                break;
            case '"':
                input += "&quot;";
                break;
            case '\'':
                input += "&apos;";
                break;
            default:
                input += c;
        }
    }
 
    std::cout << input;

    return 0;
}
