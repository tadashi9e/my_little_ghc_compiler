#ifndef GHC_SYMBOLS_H_
#define GHC_SYMBOLS_H_

#include <stdint.h>
#include <map>
#include <mutex>
#include <string>
#include <unordered_map>

class SymbolDictionary {
 public:
  static SymbolDictionary& getInstance();
  int64_t id_of_str(const std::string& str) {
    std::unique_lock<std::mutex> lock(mutex_);
    std::unordered_map<std::string, int64_t>::const_iterator
      iter = str_index_map_.find(str);
    if (iter != str_index_map_.end()) {
      return iter->second;
    }
    ++last_index_;
    str_index_map_[str] = last_index_;
    index_str_map_[last_index_] = str;
    return last_index_;
  }
  std::string str_of_id(int64_t id) const {
    std::unique_lock<std::mutex> lock(mutex_);
    std::unordered_map<int64_t, std::string>::const_iterator
      iter = index_str_map_.find(id);
    if (iter != index_str_map_.end()) {
      return iter->second;
    }
    return "";
  }

 private:
  mutable std::mutex mutex_;
  std::unordered_map<std::string, int64_t> str_index_map_;
  std::unordered_map<int64_t, std::string> index_str_map_;
  int64_t last_index_;
  SymbolDictionary()
    : last_index_(0) {
  }
};

SymbolDictionary& SymbolDictionary::getInstance() {
  static SymbolDictionary instance_;
  return instance_;
}

#endif  // GHC_SYMBOLS_H_
