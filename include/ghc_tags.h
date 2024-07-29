#ifndef GHC_TAGS_H_
#define GHC_TAGS_H_

#include <stdint.h>
#include <atomic>
#include <iostream>
#include <string>

using Q = intptr_t;
using A = std::atomic<Q>;

enum TAG_T {
  TAG_LREF,
  TAG_REF,
  TAG_ATOM,
  TAG_INT,
  TAG_LIST,
  TAG_NIL,
  TAG_STR,
  TAG_SUS,
};

inline std::string to_str(TAG_T tag) {
  switch (tag) {
  case TAG_LREF: return "LREF";
  case TAG_REF: return "REF";
  case TAG_ATOM: return "ATOM";
  case TAG_INT: return "INT";
  case TAG_LIST: return "LIST";
  case TAG_NIL: return "NIL";
  case TAG_STR: return "STR";
  case TAG_SUS: return "SUS";
  default: return "---";
  }
}

inline std::ostream& operator<<(std::ostream& stream,
                                TAG_T tag) {
  stream << to_str(tag);
  return stream;
}

template<TAG_T TAG, typename VALUE>
Q tagvalue(VALUE value) {
  return (static_cast<Q>(value) << 3) | TAG;
}

template<TAG_T TAG, typename VALUE>
Q tagptr(VALUE* p) {
  return (reinterpret_cast<Q>(p) & ~static_cast<Q>(0x7)) | TAG;
}

inline TAG_T tag_of(Q q) {
  return static_cast<TAG_T>(q & 0x7);
}

template<typename VALUE>
VALUE value_of(Q q) {
  return static_cast<VALUE>(q >> 3);
}

template<typename VALUE>
VALUE* ptr_of(Q q) {
  return reinterpret_cast<VALUE*>(q & ~static_cast<Q>(0x7));
}

#endif  // GHC_TAGS_H_
