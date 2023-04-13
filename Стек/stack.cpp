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
struct Stack {
    int size = 0;
    Node* vershina = nullptr;
};
void poplast(Stack* stack) {
    Node* tmp = stack->vershina;
    tmp = tmp->nxtptr;
    stack->vershina = tmp;
    stack->size--;

}
void pushback(Stack* Stack, int data) 
{
    Node* tmp1 = Stack->vershina;
    Node* tmp = new Node;
    tmp->data = data;
    if (Stack->size==0) {
        Stack->size++;
        Stack->vershina = tmp;
        Stack->vershina->nxtptr = nullptr;
    }
    else {
        tmp->nxtptr = tmp1;
        Stack->vershina = tmp;
        Stack->size++;
    }

}
Stack* CreateStack(int size) {
    Stack* stack = new Stack;
    string tmp;
    int num;
    cout << "введите элементы стэка:" << endl;
    for (int i = 0;i < size;i++) {
        cin >> num;
        pushback(stack, num);
    }
    return stack;
}
void printstack(Stack* stack) {
    if (stack->size == 0) {
        cout << "Stack is empty" << endl;
    }
    else {
        Node* tmp = stack->vershina;
        int k = stack->size;
        cout << "last" << endl;;
        while (tmp->nxtptr != nullptr)
        {
            cout << tmp->data << endl;
            tmp = tmp->nxtptr;
        }
        cout << tmp->data << endl;
        cout << "first";
        cout << endl;
    }
   
}
void deletestack(Stack* stack) {
    Node* tmp = stack->vershina;
    int sz = stack->size;
    for (int i = 0;i < sz;i++) {
        poplast(stack);
    }
}
void fileoutput(string name, Stack* stack) {
    ofstream fout;
    fout.open(name);
    int n = stack->size;
    Node* tmp = stack->vershina;
    for (int i = 0;i<n;i++) {
        fout <<tmp->data<<endl;
        tmp = tmp->nxtptr;
    }
    fout.close();
}
void fileinput(string name, Stack* stack, int size) {
    ifstream fin;
    string tmp1;
    fin.open(name);
    int num;
    int arr[20];
    for (int i = size-1;i >=0;i--) {
        getline(fin, tmp1);
        arr[i] = stoi(tmp1);
    }
    for (int j = 0;j < size;j++) {
        pushback(stack, arr[j]);
    }
}
void dellete_object(Stack* stack, int key) {
    Node* tmp = stack->vershina;
    Node* prev = stack->vershina;
    int i = 0;
    int a[20];
    if (stack->vershina->data== key) {
        tmp = tmp->nxtptr;
        stack->vershina = tmp;
    }
    else {
        tmp = tmp->nxtptr;
        while (tmp->data != key) {
            tmp = tmp->nxtptr;
            prev = prev->nxtptr;
        }
        tmp = tmp->nxtptr;
        prev->nxtptr = tmp;
        
    }
    stack->size--;
}

void showmenu() {
    cout << "0-Создать стэк" << endl;
    cout << "1-Удалить стэк" << endl;
    cout << "2-Вывести стэк на экран" << endl;
    cout << "3-Добавить элемент наверх стэка" << endl;
    cout << "4-Удалить последний элемент из стэка" << endl;
    cout << "5-Удалить элемент по индексу" << endl;
    cout << "6-Записать стэк в файл" << endl;
    cout << "7-Считать стэк из файла" << endl;
    cout << "8-Удалить K элементов с конца стэка" << endl;
    cout << "9-Выйти из программы" << endl;
}
void menu() {
    int cs;
    int listsize, addswitch, element, tmp1;
    Stack* stack = new Stack;
    string filename, tmp2;
    bool flag = true;
    while (flag == true) {
        showmenu();
        cin >> cs;
        switch (cs)
        {
        case 0: {
            cout << "Введите количество элементов стэка:";
            cin >> listsize;
            stack = CreateStack(listsize);
            break;
        }
        case 1: {
            cout << "Стэк удалён" << endl;
            deletestack(stack);
            cout << "Нажмите любую кнопку для возврата в меню" << endl;
            cin >> tmp2;
            break;
        }
        case 2: {
            printstack(stack);
            cout << "Нажмите любую кнопку для возврата в меню" << endl;
            cin >> tmp2;
            break;
        }
        case 3: {
            cout << "Введите элемент для добавления:";
            cin >> element;
            pushback(stack, element);
            break;

        }
        case 4: {
            poplast(stack);
            break;
        }
        case 5: {
            int k = 1;
            cout << "Введите индекс для удаления:";
            cin >> addswitch;
            if (addswitch == 0) {
                Node* remove = stack->vershina;
                remove = remove->nxtptr;
                stack->vershina = remove;
            }
            else {
                Node* remove = stack->vershina;
                remove = remove->nxtptr;
                Node* preremove = stack->vershina;
                while (k != addswitch) {
                    preremove = preremove->nxtptr;
                    remove = remove->nxtptr;
                    k++;
                }
                remove = remove->nxtptr;
                preremove->nxtptr = remove;

            }
            stack->size--;
            break;

        }
        case 6: {
            cout << "очередь сохранена в файл list.txt" << endl;
            fileoutput("list.txt", stack);
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
            fileinput("list.txt", stack, addswitch);
            break;
        }
        case 8: {
            cout << "Введите количество элементов для удаления:";
            cin >> tmp1;
            for (int j = 0;j < tmp1;j++) {
                poplast(stack);
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

    return 0;

}


