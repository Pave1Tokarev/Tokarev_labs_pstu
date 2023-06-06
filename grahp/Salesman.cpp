#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
// Îïðåäåëåíèå ñòðóêòóðû óçëà äåðåâà
struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Ôóíêöèÿ äëÿ âñòàâêè óçëà â äåðåâî
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    }
    else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

// Ôóíêöèÿ äëÿ óäàëåíèÿ óçëà èç äåðåâà
Node* remove(Node* root, int key) {
    if (root == nullptr) {
        return nullptr;
    }
    if (key < root->key) {
        root->left = remove(root->left, key);
    }
    else if (key > root->key) {
        root->right = remove(root->right, key);
    }
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = root->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        root->key = temp->key;
        root->right = remove(root->right, temp->key);
    }
    return root;
}

// Ôóíêöèÿ äëÿ ïîèñêà ýëåìåíòà ïî êëþ÷ó
Node* search(Node* root, int key) {
    if (root == nullptr || root->key == key) {
        return root;
    }
    if (key < root->key) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

// Ôóíêöèÿ äëÿ îáõîäà äåðåâà â ïðÿìîì ïîðÿäêå
void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Ôóíêöèÿ äëÿ îáõîäà äåðåâà â ñèììåòðè÷íîì ïîðÿäêå
void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

// Ôóíêöèÿ äëÿ îáõîäà äåðåâà â îáðàòíîì ïîðÿäêå
void postOrder(Node* root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key << " ";
    }
}

// Ôóíêöèÿ äëÿ âû÷èñëåíèÿ âûñîòû äåðåâà
int height(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}
// Ôóíêöèÿ äëÿ ïîâîðîòà âïðàâî
Node* rotateRight(Node* root) {
    Node* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    return newRoot;
}

// Ôóíêöèÿ äëÿ ïîâîðîòà âëåâî
Node* rotateLeft(Node* root) {
    Node* newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    return newRoot;
}
// Ôóíêöèÿ äëÿ áàëàíñèðîâêè äåðåâà
Node* balance(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    int balanceFactor = height(root->left) - height(root->right);
    if (balanceFactor > 1) {
        if (height(root->left->left) >= height(root->left->right)) {
            root = rotateRight(root);
        }
        else {
            root->left = rotateLeft(root->left);
            root = rotateRight(root);
        }
    }
    else if (balanceFactor < -1) {
        if (height(root->right->right) >= height(root->right->left)) {
            root = rotateLeft(root);
        }
        else {
            root->right = rotateRight(root->right);
            root = rotateLeft(root);
        }
    }
    return root;
}



// Ôóíêöèÿ äëÿ ïå÷àòè äåðåâà â ãîðèçîíòàëüíîì âèäå
void printHorizontal(Node* root, int level, sf::RenderWindow& window, int x, int y, int dx)
{
    if (root == nullptr) {
        return;
    }

    printHorizontal(root->left, level + 1, window, x - dx, y + 50, dx / 2);
    sf::Color myColor2(2, 78, 104);
    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text text(std::to_string(root->key), font, 20);
    text.setPosition(x, y);
    text.setFillColor(sf::Color::Black);
    window.draw(text);

    printHorizontal(root->right, level + 1, window, x + dx, y + 50, dx / 2);

    if (root->left != nullptr) {
        sf::Vertex line[] = {

            sf::Vertex(sf::Vector2f(x + 10, y + 10)),
            sf::Vertex(sf::Vector2f(x - dx + 10, y + 50))
        };
        window.draw(line, 2, sf::Lines);
    }

    if (root->right != nullptr) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x + 10, y + 10)),
            sf::Vertex(sf::Vector2f(x + dx + 10, y + 50))
        };
        window.draw(line, 2, sf::Lines);
    }

    if (root->left != nullptr) {
        sf::Vertex line[] = {

            sf::Vertex(sf::Vector2f(x + 10, y + 10)),
            sf::Vertex(sf::Vector2f(x - dx + 10, y + 50))
        };
        window.draw(line, 2, sf::Lines);
    }
    if (root->right != nullptr) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x + 10, y + 10)),
            sf::Vertex(sf::Vector2f(x + dx + 10, y + 50))
        };
        window.draw(line, 2, sf::Lines);
    }
}

// Ôóíêöèÿ äëÿ ïå÷àòè äåðåâà â âåðòèêàëüíîì âèäå
void printVertical(Node* root, int level) {
    if (root == NULL) {
        return;
    }
    printVertical(root->right, level + 1);
    for (int i = 0; i < level; i++) {
        cout << "   ";
    }
    cout << root->key << endl;
    printVertical(root->left, level + 1);
}


int main() {
    setlocale(0, "");
    Node* root = nullptr;
    int choice = 0;
    int key = 0;
    Node* found = nullptr; // îáúÿâëåíèå ïåðåìåííîé found
    while (true) {
        cout << "Âûáåðèòå äåéñòâèå:" << endl;
        cout << "1. Âñòàâèòü ýëåìåíò" << endl;
        cout << "2. Óäàëèòü ýëåìåíò" << endl;
        cout << "3. Íàéòè ýëåìåíò" << endl;
        cout << "4. Îáõîä äåðåâà â ïðÿìîì ïîðÿäêå" << endl;
        cout << "5. Îáõîä äåðåâà â ñèììåòðè÷íîì ïîðÿäêå" << endl;
        cout << "6. Îáõîä äåðåâà â îáðàòíîì ïîðÿäêå" << endl;
        cout << "7. Áàëàíñèðîâêà äåðåâà" << endl;
        cout << "8. Ïå÷àòü äåðåâà" << endl;
        cout << "9. Âûõîä" << endl;
        cout << "Ââåäèòå íîìåð äåéñòâèÿ: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Ââåäèòå êëþ÷ ýëåìåíòà äëÿ âñòàâêè: ";
            cin >> key;
            root = insert(root, key);
            break;
        case 2:
            cout << "Ââåäèòå êëþ÷ ýëåìåíòà äëÿ óäàëåíèÿ: ";
            cin >> key;
            root = remove(root, key);
            break;
        case 3:
            cout << "Ââåäèòå êëþ÷ ýëåìåíòà äëÿ ïîèñêà: ";
            cin >> key;
            found = search(root, key); // èíèöèàëèçàöèÿ ïåðåìåííîé found
            if (found != nullptr) {
                cout << "Ýëåìåíò íàéäåí: " << found->key << endl;
            }
            else {
                cout << "Ýëåìåíò íå íàéäåí" << endl;
            }
            break;
        case 4:
            cout << "Îáõîä äåðåâà â ïðÿìîì ïîðÿäêå: ";
            preOrder(root);
            cout << endl;
            break;
        case 5:
            cout << "Îáõîä äåðåâà â ñèììåòðè÷íîì ïîðÿäêå: ";
            inOrder(root);
            cout << endl;
            break;
        case 6:
            cout << "Îáõîä äåðåâà â îáðàòíîì ïîðÿäêå: ";
            postOrder(root);
            cout << endl;
            break;
        case 7:
            root = balance(root);
            break;
        case 8:
        {
            sf::RenderWindow window(sf::VideoMode(800, 600), "Tree");
            window.clear(sf::Color::White);
            printHorizontal(root, 0, window, 400, 50, 200);
            window.display();
            sf::Event event;
            while (window.isOpen()) {
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    }
                }
            }
            break;
        }
        case 9:
            cout << "Âûõîä" << endl;
            return 0;
        default:
            cout << "Íåâåðíûé íîìåð äåéñòâèÿ" << endl;
            break;
        }
    }
    return 0;
}