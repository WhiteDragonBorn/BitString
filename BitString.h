#pragma once

#include <string>

class BitString {
 private:
  std::string dataLeft;
  std::string dataRight;

 public:
  BitString();
  BitString(const BitString&);
  BitString(const std::string&);
  ~BitString();

  void setLeftBits(const std::string&);
  void setRightBits(const std::string&);
  std::string getLeftBits();
  std::string getRightBits();

  void operator=(const BitString other);
  BitString operator&(BitString& other);
  BitString operator|(BitString& other);
  BitString operator^(BitString& other);
  BitString operator!();
  BitString operator>>(int other);
  BitString operator<<(int other);

  std::string toString();
};
