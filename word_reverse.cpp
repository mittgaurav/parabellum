#include <iostream>
#include <string.h>

void reverse(char* string, size_t i, size_t j) {
    while( i < j ) {
        char temp = string[i];
        string[i] = string[j];
        string[j] = temp;
        i++; j--;
    }
}
int main() {
    char string[] = "  i like to   code   ";
    std::cout << string << std::endl;
  
    reverse(string, 0, strlen(string) - 1);
    std::cout << string << std::endl;

    size_t prev = 0;  // start of word
    for( size_t i = 0; i <= strlen(string); i++) {
        if(string[i] == ' ' || string[i] == '\0') {
            if(i > prev) {  // optimization for spaces
                reverse(string, prev, i-1);
            }
            prev = i + 1;  // start of next word
        }
    }

    std::cout << string << std::endl;
}