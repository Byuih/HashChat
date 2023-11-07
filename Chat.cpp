#include "Chat.h"
int main() {
    HashTable chat;

    // Добавляем пользователей в чат
    chat.addUser("user1", "hash1");
    chat.addUser("user2", "hash2");
    chat.addUser("user3", "hash3");

    // Поиск хеша по логину
    std::cout << "Hash for user1: " << chat.findHash("user1") << std::endl;
    std::cout << "Hash for user2: " << chat.findHash("user2") << std::endl;
    std::cout << "Hash for user3: " << chat.findHash("user3") << std::endl;

    return 0;
}