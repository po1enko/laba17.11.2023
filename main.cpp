#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// структура для представления элемента связного списка
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// класс для представления связного списка
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // добавление элемента в конец списка
    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // вставка элемента по индексу
    void insertAtIndex(int index, int value) {
        Node* newNode = new Node(value);
        if (index == 0 || !head) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            for (int i = 0; i < index - 1 && current->next; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // поиск элемента в списке
    bool search(int value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // вывод списка
    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));

    LinkedList myList;

    // заполнение списка рандомными числами
    for (int i = 0; i < 10; ++i) {
        myList.append(rand() % 100);
    }

    cout << "ishodniy spisok: ";
    myList.display();

    int index, value;
    cout << "vvedite index dlya vstavki: ";
    cin >> index;

    cout << "vvedite znecheniye dlya vstavki: ";
    cin >> value;

    myList.insertAtIndex(index, value);

    cout << "spisok posle vstavki: ";
    myList.display();

    int searchValue;
    cout << "vvedite znachenie dlya poiska: ";
    cin >> searchValue;

    if (myList.search(searchValue)) {
        cout << "element est v spiske." << endl;
    } else {
        cout << "elementa net v spiske." << endl;
    }

    return 0;
}