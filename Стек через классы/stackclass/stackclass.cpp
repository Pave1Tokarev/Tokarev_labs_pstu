#include <iostream>
#include"stack.h" 
int main()
{
    setlocale(LC_ALL,"rus");
    cout << "Введите размер стека : ";
    int n,tmp;
    cin >> n;
    stack st;
    for (int i = 0;i < n;i++) {
        cout << i + 1 << " : ";
        cin >> tmp;
        st.push_top(tmp);
    }
    cout << "Введите количество элементов для добавления :";
    cin >> n;
    for (int i = 0;i < n;i++) {
        cout << i + 1 << " : ";
        cin >> tmp;
        st.push_top(tmp);
    }
    st.show();
    cout << "Введите количество элементов для удаления :";
    cin >> n;
    for (int i = 0;i < n;i++) {
        st.pop_top();
    }
    st.show();
    cout << "Размер стека : " << st()<<endl;
    cout << "Верхний элемент стека : " << st.get_top() << endl;
}
