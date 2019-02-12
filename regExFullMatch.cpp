#include <iostream>
#include <string.h>

static const char* pat = "xa*b*.*a.x";
static const char* str = "xaaa";
const size_t patLen = 10;
const size_t strLen = 4;
bool result[strLen + 1][patLen + 1] = {false};

// pretty print result matrix.
void print() {
  std::cout << "-  0  ";
  for(  size_t i = 0; i <  patLen; ++i)
    std::cout << pat[i] << "  ";
  std::cout << "\n";
  for(  size_t i = 0; i <= strLen; ++i) {
    if(0 == i)
      std::cout << "0  ";
    else
      std::cout << str[i - 1] << "  ";
    for(size_t j = 0; j <= patLen; ++j)
      std::cout << (result[i][j] ? 'T' : '-') << "  ";
    std::cout << "\n";
  }
  std::cout << "\n";
}

bool isMatch(const char* str, const char* pat) {
  // empty pattern and empty string match
  result[0][0] = true;
  
  // empty string and certain '*' patterns match
  for(size_t i = 0; i < patLen; ++i) {
    if('*' == pat[i])
      result[0][i + 1] = result[0][i - 1];
  }

  for(  size_t i = 0; i < strLen; ++i) {
    for(size_t j = 0; j < patLen; ++j) {

      if(pat[j] == str[i] || '.' == pat[j])
        // char in pat and str match. Check previous pat and str or
        // char in pat is '.', i.e. we don't care which char in str
        result[i + 1][j + 1] = result[i][j];
      else if('*' == pat[j]) {
        // std::cout << "pat:\t" << pat[j - 1] << "\tstr:\t" << str[i] <<"\n";

        result[i + 1][j + 1] = result[i + 1][j - 1] // ignore this char in pat
            ||
            // if previous pat and this str char match, then success is 
            // either continuation of last pat char, or the one before the
            // previous pat char.
            (pat[j - 1] == str[i] && (result[i + 1][j] || result[i][j]))
            ||
            // if previous pat is '.', then success is previous to previous pat
            // till this str
            (pat[j - 1] == '.'    && result[i][j - 1]);
      }
    }
  }

  print();
  return result[strLen][patLen];
}

int main() {
  bool result = isMatch(str, pat);
  std::cout << "result is " << ( result ? "match!" : "no match :(" );
}