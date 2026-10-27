#ifndef CACHE_HPP
#define CACHE_HPP
#include <chrono>
#include <optional>
#include <string>
#include <unordered_map>

class Cache {
private:
  struct CacheEntry {
    std::chrono::steady_clock::time_point expireAt;
    std::string value;

    bool isExpired() { return expireAt <= std::chrono::steady_clock::now(); }
  };
  int ttl;
  std::unordered_map<std::string, CacheEntry> cacheEntries;

public:
  Cache() = delete;
  Cache(int ttl);
  void put(const std::string &uri, const std::string &value);
  std::optional<CacheEntry> get(const std::string &uri);
};

#endif