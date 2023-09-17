#include "BitString.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

BitString::BitString() {
  dataLeft = "";
  dataRight = "";
  for (int i = 0; i < 32; ++i) {
    dataLeft += "0";
    dataRight += "0";
  }
}

BitString::BitString(const BitString& bit) {
  dataLeft = bit.dataLeft;
  dataRight = bit.dataRight;
}

BitString::BitString(const string& str) {
  if (str.length() != 64) {
    throw("Not 64 bit");
  } else {
    for (int i = 0; i < 64; ++i) {
      if (i >= 0 && i < 32) {
        dataLeft += str[i];
      } else {
        dataRight += str[i];
      }
    }
  }
}

void BitString::setLeftBits(const string& str) {
  if (str.length() != 32) {
    throw("Not 32 bit");
  } else {
    for (int i = 0; i < 32; ++i) {
      dataLeft[i] = str[i];
    }
  }
}

void BitString::setRightBits(const string& str) {
  if (str.length() != 32) {
    throw("Not 32 bit");
  } else {
    for (int i = 0; i < 32; ++i) {
      dataRight[i] = str[i];
    }
  }
}

string BitString::getLeftBits() {
  string toReturn = "";
  for (int i = 0; i < 32; ++i) {
    toReturn += dataLeft[i];
  }
  return toReturn;
}

string BitString::getRightBits() {
  string toReturn = "";
  for (int i = 0; i < 32; ++i) {
    toReturn += dataRight[i];
  }
  return toReturn;
}

string BitString::toString() {
  string temp = "";
  temp += dataLeft + dataRight;
  return temp;
}

BitString BitString::operator&(BitString& other) {
  BitString toReturn;
  int varSize = dataLeft.size();
  for (int i = 0; i < varSize; i++) {
    toReturn.dataLeft[i] =
        (other.dataLeft[i] == '1' && dataLeft[i] == '1') + '0';
    toReturn.dataRight[i] =
        (other.dataRight[i] == '1' && dataRight[i] == '1') + '0';
  }
  return toReturn;
}

BitString BitString::operator|(BitString& other) {
  BitString toReturn;
  int varSize = dataLeft.size();
  for (int i = 0; i < varSize; i++) {
    toReturn.dataLeft[i] =
        (other.dataLeft[i] == '1' || dataLeft[i] == '1') + '0';
    toReturn.dataRight[i] =
        (other.dataRight[i] == '1' || dataRight[i] == '1') + '0';
  }
  return toReturn;
}

BitString BitString::operator^(BitString& other) {
  BitString toReturn;
  int varSize = dataLeft.size();
  for (int i = 0; i < varSize; i++) {
    toReturn.dataLeft[i] = (other.dataLeft[i] == dataLeft[i]) ? '0' : '1';
    toReturn.dataRight[i] = (other.dataRight[i] == dataRight[i]) ? '0' : '1';
  }
  return toReturn;
}

BitString BitString::operator!() {
  BitString toReturn;
  int varSize = dataLeft.size();
  for (int i = 0; i < varSize; i++) {
    toReturn.dataLeft[i] = (dataLeft[i] == '0') ? '1' : '0';
    toReturn.dataRight[i] = (dataRight[i] == '0') ? '1' : '0';
  }
  return toReturn;
}

void BitString::operator=(BitString other) {
  for (int i = 0; i < dataLeft.size(); i++) {
    dataLeft[i] = other.dataLeft[i];
    dataRight[i] = other.dataRight[i];
  }
}

BitString BitString::operator>>(int other) {
  string toReturn = dataLeft + dataRight;
  if (other > 64 || other < 0) {
    throw("Wrong shift");
  } else {
    toReturn = toReturn.substr(0, toReturn.size() - other);
    string temp = "";
    for (int i = 0; i < other; ++i) {
      temp += "0";
    }
    toReturn = temp + toReturn;
  }
  return toReturn;
}

BitString BitString::operator<<(int other) {
  string toReturn = dataLeft + dataRight;
  if (other > 64 || other < 0) {
    throw("Wrong shift");
  } else {
    toReturn = toReturn.substr(other, toReturn.size());
    string temp = "";
    for (int i = 0; i < other; ++i) {
      temp += "0";
    }
    toReturn = toReturn + temp;
  }
  return toReturn;
}