#include <iostream>
#include <string>

class Node {
public:
	int value;
	Node* right = nullptr;
	Node* left = nullptr;

	explicit Node(const int value): value(value) {
	}

	void appendChild(const int value) {
		const auto node = new Node(value);
		if (this->value < value) {
			if (this->left == nullptr) {
				this->left = node;
			}
			else {
				this->left->appendChild(value);
			}
		}
		else {
			if (this->right == nullptr) {
				this->right = node;
			}
			else {
				this->right->appendChild(value);
			}
		}
	}

	std::string traverse(const int level = 0) const
	{
		std::string res = std::to_string(level) + "-";
		res.append(std::to_string(this->value) + "\n");
		if (this->left != nullptr)
		{
			res.append(this->left->traverse(level + 1));
		}
		if (this->right != nullptr)
		{
			res.append(this->right->traverse(level + 1));
		}
		return res;
	}
};

int main()
{
	Node tree(5);
	tree.appendChild(5);
	tree.appendChild(7);
	tree.appendChild(3);

	std::cout << tree.traverse();
}