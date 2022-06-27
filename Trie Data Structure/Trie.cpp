#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "trie.h"
#define ARRAY_SZIE(a) sizeof(a)/sizeof(a[0]) //this is a way to define your own formulas

int main()
{
	/*char keys[][8] = { "the", "a", "there", "answer", "any",
					"by", "bye", "their" };

	char output[][32] = { "Not present in trie", "Present in trie" };


	construct trie

	TrieNode* root = getNode(NULL);

	for (int i = 0; i < ARRAY_SZIE(keys); i++)
	{
		insert(root, keys[i]);
	}



	printf("%s --- %s\n", "the", output[search(root, "the")]);
	printf("%s --- %s\n", "these", output[search(root, "these")]);
	printf("%s --- %s\n", "their", output[search(root, "their")]);
	printf("%s --- %s\n", "thaw", output[search(root, "thaw")]);*/

	// Input keys (use only 'a' through 'z'
	// and lower case)
	char keys[][10] = {"the", "a", "there",
					  "answer", "any", "by",
					  "bye", "their", "hero", "heroplane" };
	int n = ARRAY_SZIE(keys);

	struct TrieNode* root = getNode(NULL);

	// Construct trie
	for (int i = 0; i < n; i++)
		insert(root, keys[i]);

	// Search for different keys
	search(root, "the") ? printf("Yes\n") : printf("No\n");
	search(root, "these") ? printf("Yes\n") : printf("No\n");
	root= remove(root, "heroplane");
	search(root, "hero") ? printf("Yes\n") : printf("No\n");

	return 0;
}
