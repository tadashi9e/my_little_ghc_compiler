#ifndef GHC_TAGUTILS_H_
#define GHC_TAGUTILS_H_

#include <sstream>
#include "./ghc_tags.h"
#include "./ghc_symbols.h"

inline Q deref(Q q) {
  for (;;) {
    const TAG_T tag = tag_of(q);
    if (tag == TAG_LREF) {
      Q* p = ptr_of<Q>(q);
      const Q q2 = *p;
      if (q == q2) {
        break;
      }
      q = q2;
      continue;
    }
    if (tag == TAG_REF) {
      A* a = ptr_of<A>(q);
      const Q q2 = a->load();
      if (q == q2) {
        break;
      }
      q = q2;
      continue;
    }
    break;
  }
  return q;
}

// Replace SUS -> SUS link to REF -> SUS link
// to avoid non-self-referencing SUS link.
// SUS -> SUS link support make dereference performance degradation.
inline Q ref_of(Q q) {
  const TAG_T tag = tag_of(q);
  if (tag == TAG_SUS) {
    return tagptr<TAG_REF>(ptr_of<A>(q));
  }
  return q;
}

inline Q to_atom(const char* cstr, int arity) {
  const int64_t id =
    SymbolDictionary::getInstance().id_of_str(cstr);
  return tagvalue<TAG_ATOM>(id << 5 | arity);
}
inline std::string atom_str_of(Q q) {
  int64_t id = value_of<int64_t>(q) >> 5;
  return SymbolDictionary::getInstance().str_of_id(id);
}
inline int atom_arity_of(Q q) {
  return value_of<int64_t>(q) & 0x1f;
}

inline std::string to_str(Q q) {
  const TAG_T tag = tag_of(q);
  std::stringstream ss;
  switch (tag) {
  case TAG_LREF:
    ss << "<LREF>" << ptr_of<void>(q);
    break;
  case TAG_REF:
    ss << "<REF>" << ptr_of<void>(q);
    break;
  case TAG_ATOM:
    ss << "<ATOM>'" << atom_str_of(q) << "'";
    {
      const int i = atom_arity_of(q);
      if (i != 0) {
        ss << "/" << i;
      }
    }
    break;
  case TAG_INT:
    ss << "<INT>" << value_of<int64_t>(q);
    break;
  case TAG_LIST:
    ss << "<LIST>" << ptr_of<A>(q);
    break;
  case TAG_NIL:
    ss << "<NIL>" << ptr_of<A>(q);
    break;
  case TAG_STR:
    ss << "<STR>" << ptr_of<A>(q);
    break;
  case TAG_SUS:
    ss << "<SUS>" << ptr_of<A>(q);
    break;
  }
  return ss.str();
}

#endif  // GHC_TAGUTILS_H_
