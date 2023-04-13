#include <iostream>
#include<string>
#include<ctime>
#include<fstream>
#include<windows.h>
using namespace std;
string names[10] = { "Павел","Артём","Никита","Владимир","Виталий","Максим","Алексей","Владислав","Анатолий","Александр" };
string surnames[10] = { "Лихачёв","Петров","Плотников","Большагин","Орысенко","Субботин","Черепанов","Гусин","Каменских","Ошев" };
string patronymic[10] = { "Павлович","Артёмович","Владимирович","Алексеевич","Анатольевич","Александрович","Антонович","Тимофеевич","Игнатьевич","Михайлович" };
string phones[10]= { "74955096756","74957042376","74952128737","74957363187","74958726294","74959833608","74951179556","74959360136","74951964814","74950716705" };
string adress[10]= { "Зеленая ул., д. 16","Садовая ул., д. 6","Сосновая ул., д. 20","Вокзальная ул., д. 4","Гагарина ул., д. 19","Якуба Коласа ул., д. 19","Комсомольская ул., д. 2","Мира ул., д. 12","Набережная ул., д. 6","Приозерная ул., д. 1" };
struct student {
    student() {
        fio = "NULL";
        phone = "NULL";
        adress = "NULL";
    }
    string fio;
    string phone;
    string adress;

};
int hashfunction(string num, int size);
struct hashtable {
    student* array;
    int collisioncount = 0;
    hashtable(int size) {
        array = new student[size];
    }
    ~hashtable() {
        delete[] array;
    }
    void add(student tmp, int size) {
        int i = hashfunction(tmp.phone, size);
        int j = i;
        if (array[i].fio == "NULL") {
            array[i] = tmp;
            return;
        }
        else {
            while (i < size) {
                if (array[i].fio == "NULL") {
                    array[i] = tmp;
                    return;
                }
                collisioncount++;
                i++;
            }
            if (i >= size) {
                i = 0;
                collisioncount++;
                while (i < j) {
                    if (array[i].fio == "NULL") {
                        array[i] = tmp;
                        return;
                    }
                    collisioncount++;
                    i++;
                }
            }
        }
    }
    void findindex(string tmp, int size) {
        int hash = hashfunction(tmp, size);
        int index = hash;
        while (array[index].phone != tmp && index < size) {
            index++;
        }
        if (index >= size) {
            index = 0;
            while (array[index].phone != tmp && index < hash) {
                index++;
            }
            if (index >= hash) {
                cout << "Человекс с номером телефона " << tmp << " содержится под индексом " << index << endl;
            }
        }
        else {
            cout << "Человекс с номером телефона " << tmp << " содержится под индексом " << index << endl;
        }
    }
    void pop(string delet, int size) {
        int index = hashfunction(delet, size);
        if (array[index].phone == delet) {
            array[index] = student();
            return;
        }
        else {
            while (index < size) {
                if (array[index].phone == delet) {
                    array[index] = student();
                    return;
                }
                index++;
            }
            if (index >= size) {
                index = 0;
                while (index < size) {
                    if (array[index].phone == delet) {
                        array[index] = student();
                        return;
                    }
                    index++;
                }
            }
        }
    }
    void savetofile(student* array, int size) {
        ofstream fout("table.txt");
        for (int i = 0;i < size;i++) {
            fout << array[i].fio << endl;
            fout << array[i].phone << endl;
            fout << array[i].adress << endl;
        }
        fout.close();
    }
    void readfromfile(student* array, int size) {
        ifstream fin("table.txt");
        for (int i = 0;i < size;i++) {
            getline(fin, array[i].fio);
            getline(fin, array[i].phone);
            getline(fin, array[i].adress);
        }
        fin.close();
    }
};
int getnumber() {
    return (rand() % 10);
}
int hashfunction(string num,int size) {
    int sum=0;
    for (int i = 0;i < (num.length());i++) {
        sum += (int)num[i];
    }
    return sum % size;
}
string getfullname() {
    return(surnames[getnumber()] + " " + names[getnumber()] + " " + patronymic[getnumber()]);
}
string getphone() {
    return(phones[getnumber()]);
}
string getadress() {
    return (adress[getnumber()]);
}
student createstudent() {
    student tmp;
    tmp.fio = getfullname();
    tmp.adress = getadress();
    tmp.phone = getphone();
    return tmp;
}
void showinfo(const student tmp) {
    cout << "ФИО:" << tmp.fio<<endl;
    cout << "Номер телефона:" << tmp.phone<<endl;
    cout << "Адресс:" << tmp.adress << endl;
}
void printarray(student* array, int size) {
    for (int i = 0;i < size;i++) {
        showinfo(array[i]);
        cout << endl;
    }
}
void fillarray(student* array,int count) {
    for (int i = 0;i < count;i++) {
        array[i] = createstudent();
    }
}
void showhash(hashtable* newhash, int size) {
    for (int i = 0;i < size;i++) {
        showinfo(newhash->array[i]);
    }
}

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "rus");
    int size = 0;
    while (size < 10) {
        cout << "Введите число элементов массива:";
        cin >> size;
    }
    cout << endl;
    student* array = new student[size];
    hashtable newtable(size);
    fillarray(array, size);
    for (int j = 0;j < size;j++) {
        newtable.add(array[j], size);
    }
    showhash(&newtable, size);
    newtable.findindex("74957363187", size);
    cout << "Количество коллизий на " << size << " элементов - " << newtable.collisioncount;
}

