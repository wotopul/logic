#pragma once

#include <string>

enum logical_operation {
	CONJUNCTION, DISJUNCTION,
	IMPLICATION, NEGATION,
	VARIABLE
};

struct node {
	// if operation == NEGATION the only child is left
	node *left;
	node *right;

	logical_operation operation;
	char variable;

	node(node *left, node *right, logical_operation operation, char variable = 0)
		: left(left)
		, right(right)
		, operation(operation)
		, variable(variable) {}

	~node() {
		if (left != nullptr)
			delete left;
		if (right != nullptr)
			delete right;
	}

	bool operator==(node const* rhs) const;

	std::string to_string() const;
private:
	std::string to_string_impl() const;
};

