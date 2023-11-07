#pragma once
#include <iostream>
#include <string>
#include <cmath>

const int TABLE_SIZE = 10;  // Размер хеш-таблицы

struct User {
    std::string login;
    std::string hash;
};

class HashTable {
private:
    User* table[TABLE_SIZE];  // Хеш-таблица

    // Метод умножения для получения хеша
    int hashFunction(const std::string& key) {
        int hash = 0;
        double A = (sqrt(5) - 1) / 2;  // Фактор умножения
        for (char c : key) {
            hash += c;
            hash *= A;
        }
        return hash % TABLE_SIZE;
    }

    // Метод квадратичного пробирования для разрешения коллизий
    int quadraticProbing(int hash, int i) {
        return (hash + i * i) % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    // Метод для добавления пары логин-хеш в хеш-таблицу
    void addUser(const std::string& login, const std::string& hash) {
        User* newUser = new User;
        newUser->login = login;
        newUser->hash = hash;

        int key = hashFunction(login);  // Получаем хеш ключа 
        int index = key;
        int i = 0;

        // Ищем свободную ячейку для вставки
        while (table[index] != nullptr) {
            index = quadraticProbing(key, i);
            i++;
        }

        table[index] = newUser;
    }

    // Метод для поиска хеша по логину
    std::string findHash(const std::string& login) {
        int key = hashFunction(login);  // Получаем хеш ключа
        int index = key;
        int i = 0;

        // Перебираем ячейки хеш-таблицы, пока не найдем нужный хеш или не достигнем пустой ячейки
        while (table[index] != nullptr) {
            if (table[index]->login == login) {
                return table[index]->hash;  // Найден хеш для данного логина
            }
            index = quadraticProbing(key, i);
            i++;
        }

        return "";  // Хеш не найден
    }
};

