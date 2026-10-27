#ifndef SOCKETMANAGER_HPP
#define SOCKETMANAGER_HPP

#include <string>
constexpr int BUFFER_SIZE = 1024;

class SocketManager {
private:
  int serverSocket;
  

public:
  SocketManager() = delete;
  SocketManager(int port);
  std::string readData();
  ~SocketManager() noexcept;
};

#endif