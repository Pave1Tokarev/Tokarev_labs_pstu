#include <iostream>
#include<fstream>
#include<string>
#include<Windows.h>
using namespace std;
struct Node {
    int data;
    Node* nxtptr = nullptr;
    Node* prevptr = nullptr;
};
struct LIST {
    Node* headNode = nullptr;
    Node* tailNode = nullptr;
    int size = 0;
};

void pushback(LIST& list, int data) {
    Node* currnode = list.headNode;
    Node* newnode = new Node;
    newnode->data = data;
    if (list.size == 0) {
        list.tailNode = newnode;
        list.headNode = newnode;
    }
    else {
        currnode->nxtptr = newnode;
        newnode->prevptr = currnode;
        list.headNode = newnode;
        
    }
    list.size++;
}
void pushforward(LIST& list, int data) {
    Node* newnode = new Node;
    Node* currnode=list.tailNode;
    newnode->data = data;
    if (list.size == 0) {
        list.tailNode = newnode;
        list.headNode = newnode;
    }
    else {
        list.tailNode->prevptr = newnode;
        newnode->nxtptr = currnode;
        list.tailNode = newnode;

    }
    list.size++;
}
void printlist(LIST& list) {
    Node* currentnode = list.tailNode;
    if (currentnode == nullptr) {
        cout << "list is empty" << endl;
    }
    else {
        while (currentnode != nullptr) {
            cout << currentnode->data << " ";
            currentnode = currentnode->nxtptr;
        }
    }
    cout << endl;
}
LIST createlist(int size) {
    LIST list;
    int el;
    if (size > 0) {
        cout << "Введите элементы списка:" << endl;
        for (int i = 0;i < size;i++) {
            cin >> el;
            pushback(list, el);
        }
    }
    return list;
}
void poplast(LIST& list) {
    if ((list.tailNode == nullptr) || (list.size=0)) {
        return;
    }
    else {
        Node* preremove = list.headNode;
        preremove = preremove->prevptr;
        preremove->nxtptr = nullptr;
        list.headNode = preremove;
        list.size--;
    }
    
}
void popfirst(LIST& list) {
    if ((list.tailNode == nullptr) || (list.size = 0)) {
        return;
    }
    else {
        Node* preremove = list.tailNode;
        preremove = preremove->nxtptr;
        preremove->prevptr = nullptr;
        list.tailNode = preremove;
    }
    list.size--;
}
void savelist(string name, LIST& list) {
    ofstream fout(name);
    Node* currentnode = list.tailNode;
    for (int i = 0;i < list.size;i++) {
        fout << currentnode->data << endl;
        currentnode = currentnode->nxtptr;
    }
    fout.close();

}
void deletelist(LIST& list) {
    int k = list.size;
    for (int j = 0;j<k;j++) {
        poplast(list);
    }
    cout << "сейчас список пуст" << endl;
}
void readlist(string name, LIST& list,int size) {
    ifstream fin(name);
    string tmp;
    for (int i = 0;i<size;i++) {
        getline(fin, tmp);
        pushback(list, stoi(tmp));
    }
    fin.close();
}
void showmenu() {
    cout << "1-Создать список" << endl;
    cout << "2-Вывести список на экран" << endl;
    cout << "3-Добавить элемент в список" << endl;
    cout << "4-Удалить элемент из списка" << endl;
    cout << "5-Удалить элемент по индексу" << endl;
    cout << "6-Записать список в файл" << endl;
    cout << "7-Считать список из файла" << endl;
    cout << "8-Удалить K элементов" << endl;
    cout << "9-Выйти из программы" << endl;
}
void menu() {
    int cs;
    int listsize, addswitch, element, tmp1;
    LIST list;
    string filename, tmp2;
    bool flag = true;
    while (flag == true) {
        showmenu();
        cin >> cs;
        switch (cs)
        {
        case 1: {
            cout << "Введите количество элементов списка:";
            cin >> listsize;
            list = createlist(listsize);
            break;
        }
        case 2: {
            printlist(list);
            cout << "Нажмите любую кнопку для возврата в меню" << endl;
            cin >> tmp2;
            break;
        }
        case 3: {
            cout << endl << "1-Добавить элемент в начало" << endl;
            cout << "2-Добавить элемент в конец" << endl;
            cin >> addswitch;
            cout << "Введите элемент для добавления:";
            cin >> element;
            if (addswitch == 1) {
                pushforward(list, element);
            }
            else {
                pushback(list, element);
            }
            break;
        }
        case 4: {
            cout << endl << "1-Удалить элемент с начала списка" << endl;
            cout << "2-Удалить элемент с конца списка" << endl;
            cin >> addswitch;
            if (addswitch == 1) {
                popfirst(list);
            }
            else {
                poplast(list);
            }
            break;
        }
        case 5: {
            int k = 1;
            cout << "Введите индекс для удаления:";
            cin >> addswitch;
            if (addswitch == 0) {
                Node* remove = list.tailNode;
                remove = remove->nxtptr;
                list.tailNode = remove;
            }
            else {
                Node* remove = list.tailNode;
                remove = remove->nxtptr;
                Node* preremove = list.tailNode;
                while (k != addswitch) {
                    preremove = preremove->nxtptr;
                    remove = remove->nxtptr;
                    k++;
                }
                remove = remove->nxtptr;
                preremove->nxtptr = remove;

            }
            list.size--;
            break;

        }
        case 6: {
            cout << "список сохранёт в файл list.txt" << endl;
            savelist("list.txt", list);
            cout << "Нажмите любую кнопку для возврата в меню" << endl;
            cin >> tmp2;
            break;
        }
        case 7: {
            cout << "Введите колтчество элементов для чтения:";
            cin >> addswitch;
            cout << "Список успешно считан" << endl;
            cout << "Нажмите любую кнопку для возврата в меню" << endl;
            cin >> tmp2;
            readlist("list.txt", list, addswitch);
            break;
        }
        case 8: {
            cout << "Введите количество элементов для удаления:";
            cin >> tmp1;
            cout << "1-Удалить К элементов с начала" << endl;
            cout << "2-Удалить К элементов с конца" << endl;
            cin >> addswitch;
            if (addswitch == 1) {
                for (int i = 0;i < tmp1;i++) {
                    popfirst(list);
                }
            }
            else {
                for (int i = 0;i < tmp1;i++) {
                    poplast(list);
                }
            }
            break;
        }
        case 9: {
            flag = false;
            break;
        }
        default:
            break;

        }
        system("cls");
    }

}
int main()
{
    setlocale(LC_ALL, "rus");
    menu();


}
