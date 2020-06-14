// Example usage of aes library
#include "aes.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
    
    std::string mode;
    std::cout << "Would you like to decrypt or encrypt? (d/e)" << std::endl;
    std::getline(std::cin, mode);

    std::string message;
    std::cout << "Enter your message: " << std::endl;
    std::getline(std::cin, message);

    std::string key;
    std::cout << "Enter your encryption key: " << std::endl;
    std::getline(std::cin, key);
    std::vector<std::vector<std::vector<unsigned char>>> roundKeys = aes::expandKey(key);

    std::cout << std::endl;

    if(mode == "e") {
        std::vector<std::vector<std::vector<unsigned char>>> mesBlocks = aes::getMessageBlocks(message);
        std::cout << aes::encrypt(roundKeys, mesBlocks) << std::endl;
    }

    else if(mode == "d")
    {
         std::cout << aes::decrypt(roundKeys, message) << std::endl;
    }
    
}