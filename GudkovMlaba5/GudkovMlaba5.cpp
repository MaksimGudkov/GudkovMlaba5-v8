#include <iostream>
#include <clocale>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <list>
#include <cmath>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    void inorderTraversal() { //для ответа на вариант лабы(просмотр элементов)
        inorderRecursive(root);
    }

    void display() { //вывод на экран
        displayRecursive(root);
    }
    void insertRandom(int count, int min, int max) {
        srand(time(nullptr)); // Инициализация генератора случайных чисел

        for (int i = 0; i < count; ++i) {
            int value = min + (rand() % (max - min + 1)); // Генерация случайного числа в диапазоне [min, max]
            insert(value);
        }
    }
    int ShowAnswer() { //вывод ответов
        return answer;
    }

private:
    Node* root;//указатель на корень
    int answer = 1;

    Node* insertRecursive(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        }
        else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }


    void displayRecursive(Node* node) { //вывод на экран
        if (node != nullptr) {
            displayRecursive(node->left);
            cout << node->data << " ";
            displayRecursive(node->right);
        }
    }


    void inorderRecursive(Node* node) { //задание лабы

        if (node != nullptr) {
            inorderRecursive(node->left);
            answer = answer * node->data;
            inorderRecursive(node->right);
        }
    }
};

int main() {
    system("chcp 1251"); // настраиваем кодировку консоли
    int x;

    BinaryTree tree; //обратились к бинарному дереву
    tree.insertRandom(7, 1, 20); //вывод деревов

    cout << endl << "Binary Tree: "; 
    tree.display();
    cout << endl;

    tree.inorderTraversal(); //просмотр всего дерева и далле вывод на консоль
    cout << "Произведение всех вершин: " << tree.ShowAnswer();
    return 0;
}