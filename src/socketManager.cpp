#include "../header/socketManager.hpp"
#include <iostream>
#include <unistd.h>
#include <array>
#include <netinet/in.h>
#include <sys/socket.h>

SocketManager::SocketManager(int port) {
  serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  sockaddr_in serverAddress;
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons(port);
  serverAddress.sin_addr.s_addr = INADDR_ANY;
  std::cout<<"[INFO] bind started..."<<std::endl;
  if (bind(serverSocket, reinterpret_cast<sockaddr *>(&serverAddress),
          sizeof(serverAddress)) < 0) {
    std::cerr << "[ERROR] bind failed to port "<< port << " " << std::strerror(errno) << '\n';
    close(serverSocket);
    return;
  }
  listen(serverSocket, 5);
  std::cout<<"[INFO] bind success to port "<< port <<std::endl;
}

std::string SocketManager::readData()
{
  int clientSocket = accept(serverSocket, nullptr, nullptr);
  std::array<char, BUFFER_SIZE> buffer;
  ssize_t n = recv(clientSocket, buffer.data(), buffer.size(), 0);
  return (n > 0) ? std::string(buffer.data(), n) : "";
}

SocketManager::~SocketManager()noexcept { 
  std::cout << "[DEBUG] Destructor called for server manager" << std::endl;
  close(serverSocket); 
}