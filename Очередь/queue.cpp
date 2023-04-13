#include<string>
#include <iostream>
#include<fstream>
#include<Windows.h>
using namespace std;
struct Node
{
    int data;
    Node* nxtptr = nullptr;

};
struct queue {
    int size = 0;
    Node* tail = nullptr;
};
void del(queue* queue);
void pushback(queue *queue, int data) {
    if (!(queue == nullptr) || (queue->size == 0)) {
        Node* newnode = new Node;
        newnode->data = data;
        newnode->nxtptr = queue->tail;
        queue->tail = newnode;
        queue->size++;
    }
    else {
        Node* newnode = new Node;
        queue->size=1;
        newnode->data = data;
        queue->tail = newnode;
    }
        

}
queue* CreateQueue(int size) {
    queue* Queue = new queue;
    string tmp;
    int num;
    cout << "введите элементы очереди:" << endl;
    for (int i = 0;i < size;i++) {
        cin >> num;
        pushback(Queue, num);
    }
    return Queue;
}
void Deletequeue(queue* queue) {
    int sz = queue->size;
    for (int j = 0;j < sz;j++) {
        del(queue);
    }
}
void printqueue(queue* queue) {
    Node* tmp = queue->tail;
    int k = queue->size;
    cout << "last";
    for(int i=0;i<k ;i++)
    {
        cout <<" > " << tmp->data;
        tmp = tmp->nxtptr;
    }
    cout << " > first";
    cout << endl;
}
void del(queue* queue) {
    Node* tmp = queue->tail;
    Node* tmp1 = queue->tail;
    tmp1 = tmp1->nxtptr;
    while (tmp1->nxtptr != nullptr) {
        tmp1 = tmp1->nxtptr;
        tmp = tmp->nxtptr;
    }
    tmp->nxtptr = nullptr;
    queue->size--;
    delete tmp1;
}
void fileoutput(string name, queue* queue) {
    Node* tmp = queue->tail;
    ofstream fout;
    fout.open(name);
    int t = queue->size;
    for (int k = 0;k<t;k++) {
        fout << tmp->data;
        fout << endl;
        tmp = tmp->nxtptr;
    }
    fout.close();
}
void fileinput(string name, queue* queue,int size) {
    ifstream fin;
    fin.open(name);
    int num;
    for (int i = 0;i < size;i++) {
        fin >> num;
        pushback(queue, num);
    }
}
void add_onfirst_place(queue* queue, int num) {
    Node* tmp = queue->tail;
    Node* newnode=new Node;
    while (tmp->nxtptr != nullptr) {
        tmp = tmp->nxtptr;
    }
    newnode->data = num;
    tmp->nxtptr = newnode;
    newnode->nxtptr = nullptr;
    queue->size++;
}
void dellete_object(queue* queue, int key) {
    Node* tmp = queue->tail;
    Node* prev = queue->tail;
    int i = 0;
    if (queue->tail->data == key) {
        tmp = tmp->nxtptr;
        queue->tail = tmp;
    }
    else {
        while (i < queue->size) {
            if (queue->tail->data != key) {
                add_onfirst_place(queue, queue->tail->data);
                del(queue);
                i++;
            }
            else {
                del(queue);
            }
        }
    }
}
void showmenu() {
    cout << "0-Создать очередь" << endl;
    cout << "1-Удалить очередь" << endl;
    cout << "2-Вывести очередь на экран" << endl;
    cout << "3-Добавить элемент в конец очереди" << endl;
    cout << "4-Удалить первый элемент из очереди" << endl;
    cout << "5-Удалить элемент по индексу" << endl;
    cout << "6-Записать очередь в файл" << endl;
    cout << "7-Считать очередь из файла" << endl;
    cout << "8-Удалить K элементов с начала очереди" << endl;
    cout << "9-Выйти из программы" << endl;
}
void menu() {
    int cs;
    int listsize, addswitch, element, tmp1;
    queue* ochered=new queue;
    string filename, tmp2;
    bool flag = true;
    while (flag == true) {
        showmenu();
        cin >> cs;
        switch (cs)
        {
        case 0: {
            cout << "Введите количество элементов очереди:";
            cin >> listsize;
            ochered= CreateQueue(listsize);
            break;
        }
        case 1: {
            cout << "Очередь удалена" << endl;
            Deletequeue(ochered);
            cout << "Нажмите любую кнопку для возврата в меню" << endl;
            cin >> tmp2;
        }
        case 2: {
            printqueue(ochered);
            cout << "Нажмите любую кнопку для возврата в меню" << endl;
            cin >> tmp2;
            break;
        }
        case 3: {
            cout << "Введите элемент для добавления:";
            cin >> element;
            pushback(ochered, element);
            break;
            
        }
        case 4: {
            del(ochered);
            break;
        }
        case 5: {
            int k = 1;
            cout << "Введите индекс для удаления:";
            cin >> addswitch;
            if (addswitch == 0) {
                Node* remove = ochered->tail;
                remove = remove->nxtptr;
                ochered->tail = remove;
            }
            else {
                Node* remove = ochered->tail;
                remove = remove->nxtptr;
                Node* preremove = ochered->tail;
                while (k != addswitch) {
                    preremove = preremove->nxtptr;
                    remove = remove->nxtptr;
                    k++;
                }
                remove = remove->nxtptr;
                preremove->nxtptr = remove;

            }
            ochered->size--;
            break;

        }
        case 6: {
            cout << "очередь сохранена в файл list.txt" << endl;
            fileoutput("list.txt", ochered);
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
            fileinput("list.txt", ochered, addswitch);
            break;
        }
        case 8: {
            cout << "Введите количество элементов для удаления:";
            cin >> tmp1;
            for (int j = 0;j < tmp1;j++) {
                del(ochered);
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
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    menu();

}


