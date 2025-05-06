#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Country {
	char countryName[50];
	char capital[100];
	int numberrOfCities;
	int foundationYear;
	int area;
	char presidentName[100];
};

typedef struct Node {
	struct Country country;
	struct Node* left;
	struct Node* right;
} Node;

struct Node* create_new_node(struct Country country) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->country = country;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

struct Node* insert_node_country(struct Node* root, struct Country country) {
	if (root == NULL) {
		return create_new_node(country);
	}
	if (country.area < root->country.area) {
		root->left = insert_node_country(root->left, country); // inserting the country with the smollest area in the left subtree
	}
	else {
		root->right = insert_node_country(root->right, country); // inserting the country with the biggest area in the right subtree
	}
	return root;
}

struct Country read_new_country() {
	struct Country country;
	printf("Country name: ");
	scanf_s("%s", country.countryName, (unsigned)_countof(country.countryName));
	printf("Capital: ");
	scanf_s("%s", country.capital, (unsigned)_countof(country.capital));
	printf("Number of cities: ");
	scanf_s("%i", &country.numberrOfCities);
	printf("Year of foundation: ");
	scanf_s("%i", &country.foundationYear);
	printf("Area: ");
	scanf_s("%i", &country.area);
	printf("President's name: ");
	scanf_s("%s", country.presidentName, (unsigned)_countof(country.presidentName));
	return country;
}

void display_country(struct Country country) {
	printf("\nCountry name: %s\n", country.countryName);
	printf("Capital: %s\n", country.capital);
	printf("Number of cities: %i\n", country.numberrOfCities);
	printf("Year of foundation: %i\n", country.foundationYear);
	printf("Area: %i\n", country.area);
	printf("President's name: %s\n", country.presidentName);
}

void display_in_order(struct Node* root) {
	if (root != NULL) {
		display_in_order(root->left);
		display_country(root->country);
		display_in_order(root->right);
	}
}

// Calculates the height of the binary tree.
// The height is the number of nodes along the longest path from the root to a leaf.
// If the tree is empty, height is 0.
// Recursively calculates the height of left and right subtrees and returns the larger one plus 1.
int tree_height(struct Node* root) {
	if (root == NULL) {
		return 0;
	}
	int left_height = tree_height(root->left);
	int right_height = tree_height(root->right);
	return (left_height > right_height ? left_height : right_height) + 1;
}

int search_node(struct Node* root, int key) { // Searches for a node with the given key (foundation year).
	if (root == NULL) {
		return 0;
	}
	if (root->country.foundationYear == key) {
		return 1;
	}
	int left_search = search_node(root->left, key);
	int right_search = search_node(root->right, key);
	return left_search || right_search;
}

int node_depth(struct Node* root, int key, int depth) { // Calculates the depth of a node with the given key (number of cities).
	if (root == NULL) {
		return 0;
	}
	if (root->country.numberrOfCities == key) {
		return depth;
	}
	int left_depth = node_depth(root->left, key, depth + 1);
	int right_depth = node_depth(root->right, key, depth + 1);
	if (left_depth != 0)
		return left_depth;
	else
		return right_depth;
}

int node_height(struct Node* root, int key) { // Calculates the height of a node with the given key (area).
	if (root == NULL) {
		return 0;
	}
	if (root->country.area == key) {
		return tree_height(root);
	}
	int left_height = node_height(root->left, key);
	int right_height = node_height(root->right, key);
	return (left_height != 0) ? left_height : right_height;
}

void print_tree_leaves(struct Node* root) { //printing the leaves of the tree
	if (root == NULL) {
		return;
	}
	if (root->left == NULL && root->right == NULL) {
		printf("Leaf node: %s\n", root->country.countryName); //Leaf node - a node with no children
	}
	else {
		printf("Internal node: %s\n", root->country.countryName); // Internal node - a node with children

		print_tree_leaves(root->left);
		print_tree_leaves(root->right);
	}
}

void free_tree(struct Node* node) {
	if (node == NULL) return;
	free_tree(node->left);
	free_tree(node->right);
	free(node);
}

int main() {
	struct Node* root = NULL;
	int countryCount, i, area, year, cityCount, menuOption;

	printf("Number of countries to insert: ");
	scanf_s("%i", &countryCount);

	for (i = 0; i < countryCount; i++) {
		printf("\nEnter information about the country:\n");
		struct Country country = read_new_country();
		root = insert_node_country(root, country);
	}

	printf("\nCountries entered:\n");
	display_in_order(root);
	do {
		printf("\nMenu:\n");
		printf("1 - Calculate tree depth\n");
		printf("2 - Search for a node by key (foundation year)\n");
		printf("3 - Calculate node depth (based on number of cities)\n");
		printf("4 - Calculate node height (based on area)\n");
		printf("5 - Display all tree leaves\n");
		printf("6 - Clear the tree\n");

		printf("\nEnter menu option: ");
		scanf_s("%i", &menuOption);

		switch (menuOption) {
		case 1:
			printf("\nTree depth = %i", tree_height(root));
			break;

		case 2:
			printf("Enter the foundation year to search: ");
			scanf_s("%i", &year);
			if (search_node(root, year)) {
				printf("Country founded in %i was found", year);
			}
			else {
				printf("Country founded in %i was not found", year);
			}
			break;

		case 3:
			printf("Enter the number of cities for the node (to calculate depth): ");
			scanf_s("%i", &cityCount);
			int depth = node_depth(root, cityCount, 0);
			if (depth != 0) {
				printf("Depth of node with %i cities = %i", cityCount, depth);
			}
			else {
				printf("Node with %i cities not found", cityCount);
			}
			break;

		case 4:
			printf("Enter the area of the country (to calculate node height): ");
			scanf_s("%i", &area);
			int height = node_height(root, area);
			if (height != 0) {
				printf("Height of node with area %i = %i", area, height);
			}
			else {
				printf("Node with area %i not found", area);
			}
			break;

		case 5:
			printf("Displaying all leaves of the tree:\n");
			print_tree_leaves(root);
			break;

		case 6:
			free_tree(root);
			printf("Tree has been cleared");
			break;

		default:
			printf("Error. Please enter a number between 1 and 6");
		}
	} while (menuOption != 0);
	return 0;
}
