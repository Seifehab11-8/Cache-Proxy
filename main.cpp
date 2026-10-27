#include <iostream>
#include "header/socketManager.hpp"

int main() {
    std::cout<<"[INFO] App started.."<<std::endl;
    SocketManager socket(3000);
    while(true) {
        std::cout<<socket.readData();
    }
}