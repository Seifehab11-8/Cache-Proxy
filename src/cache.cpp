#include "../header/cache.hpp"
#include <chrono>
#include <optional>

Cache::Cache(int ttl) : ttl(ttl) {}

void Cache::put(const std::string &uri, const std::string &value) {
  CacheEntry cacheEntry;
  cacheEntry.expireAt =
      std::chrono::steady_clock::now() + std::chrono::seconds(ttl);
  cacheEntry.value = value;

  cacheEntries[uri] = cacheEntry;
}

std::optional<Cache::CacheEntry> Cache::get(const std::string &uri) {
  if (!cacheEntries.count(uri))
    return std::nullopt;

  if (cacheEntries.at(uri).isExpired()) {
    cacheEntries.erase(uri);
    return std::nullopt;
  }
  return cacheEntries.at(uri);
}