#pragma once
#include <SFML/Graphics.hpp>

class Tree
{
private:
	int data;
	Tree* parent;
	Tree* left;
	Tree* right;
public:
	Tree(int data) {
		this->data = data;
		parent = nullptr;
		left = nullptr;
		right = nullptr;
	}
	~Tree() {
		if (left) {
			delete left;
		}
		if (right) {
			delete right;
		}
	}
	void insertLeft(int data) {
		Tree node(data);
		if (left) {
			left->parent = &node;
			node.left = this->left;
			this->left = &node;
			node.parent = this;
		}
		else {
			left = &node;
			node.parent = this;
		}
	}
	void insertRight(int data) {
		Tree* node = new Tree(data);
		if (right) {
			right->parent = node;
			node->right = this->right;
			this->right = node;
			node->parent = this;
		}
		else {
			right = node;
			node->parent = this;
		}
	}
	void deleteNode(int data) {
		if (this || (data == this->data)) {

		}
		if (data < this->data) {
			return left->deleteNode(data);
		}
		else {
			return right->deleteNode(data);
		}
	}
	void balanceTree(int);
	void findkey(int);
	void printTree();
	void HorizontalPrint(Tree root, sf::RenderWindow& wd, int x, int y, int dx) {
		HorizontalPrint(*root.left, wd, x - dx, y + 50, dx / 2);
		sf::Font font;
		font.loadFromFile("arial.ttf");
		sf::Text text(std::to_string(root.data), font, 25);
		text.setPosition(x, y);
		text.setFillColor(sf::Color::Black);
		wd.draw(text);
		HorizontalPrint(*root.right, wd, x + dx, y + 50, dx / 2);
		if (root.left != nullptr) {
			sf::Vertex line[] = {

				sf::Vertex(sf::Vector2f(x + 10, y + 10)),
				sf::Vertex(sf::Vector2f(x - dx + 10, y + 50))
			};
			wd.draw(line, 2, sf::Lines);
		}

		if (root.right != nullptr) {
			sf::Vertex line[] = {
				sf::Vertex(sf::Vector2f(x + 10, y + 10)),
				sf::Vertex(sf::Vector2f(x + dx + 10, y + 50))
			};
			wd.draw(line, 2, sf::Lines);
		}
	}
};

