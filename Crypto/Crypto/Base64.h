
#ifndef _BASE64_H_
#define _BASE64_H_

#include "Crypto.h"

std::string 	base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len);
std::string 	base64_decode(std::string const& encoded_string);

#endif