#pragma once
#include <iostream>
#include <string>
#include <cmath>

const int TABLE_SIZE = 10;  // ������ ���-�������

struct User {
    std::string login;
    std::string hash;
};

class HashTable {
private:
    User* table[TABLE_SIZE];  // ���-�������

    // ����� ��������� ��� ��������� ����
    int hashFunction(const std::string& key) {
        int hash = 0;
        double A = (sqrt(5) - 1) / 2;  // ������ ���������
        for (char c : key) {
            hash += c;
            hash *= A;
        }
        return hash % TABLE_SIZE;
    }

    // ����� ������������� ������������ ��� ���������� ��������
    int quadraticProbing(int hash, int i) {
        return (hash + i * i) % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    // ����� ��� ���������� ���� �����-��� � ���-�������
    void addUser(const std::string& login, const std::string& hash) {
        User* newUser = new User;
        newUser->login = login;
        newUser->hash = hash;

        int key = hashFunction(login);  // �������� ��� ����� 
        int index = key;
        int i = 0;

        // ���� ��������� ������ ��� �������
        while (table[index] != nullptr) {
            index = quadraticProbing(key, i);
            i++;
        }

        table[index] = newUser;
    }

    // ����� ��� ������ ���� �� ������
    std::string findHash(const std::string& login) {
        int key = hashFunction(login);  // �������� ��� �����
        int index = key;
        int i = 0;

        // ���������� ������ ���-�������, ���� �� ������ ������ ��� ��� �� ��������� ������ ������
        while (table[index] != nullptr) {
            if (table[index]->login == login) {
                return table[index]->hash;  // ������ ��� ��� ������� ������
            }
            index = quadraticProbing(key, i);
            i++;
        }

        return "";  // ��� �� ������
    }
};

