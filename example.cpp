#include <sstream> // required for 'stringstream'
#include <iostream> // required for 'cout'
#include <iomanip> // required for 'setfill'

#include "ripemd160.c"

std::string uint8_to_hex_string(const uint8_t *v, const size_t s) {
  std::stringstream ss;

  ss << std::hex << std::setfill('0');

  for (int i = 0; i < s; i++) {
    ss << std::hex << std::setw(2) << static_cast<int>(v[i]);
  }

  return ss.str();
}

int main() {
  size_t msglen = 32;
  uint8_t msg[msglen];

  size_t hashlen = 20;
  uint8_t hash[hashlen];

  std::string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

  memcpy(msg, str.c_str(), sizeof(msg));

  ripemd160(msg, msglen, hash);

  std::string hexstr = uint8_to_hex_string(hash, hashlen);

  std::cout << hexstr << std::endl;
  // e6d64710683e82853342e24f011bc77af21884ad

  return 0;
}
