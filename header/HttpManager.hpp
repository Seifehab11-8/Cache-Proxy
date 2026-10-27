#ifndef HTTPMANAGER_HPP
#define HTTPMANAGER_HPP

#include <curl/curl.h>
#include <memory>

class HttpManager {
    private:
    std::unique_ptr<CURL> curl;

    public:
    HttpManager() = delete;
    HttpManager(std::string url);
};

#endif