#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "trie.h"
#define ARRAY_SZIE(a) sizeof(a)/sizeof(a[0]) //this is a way to define your own formulas

int main()
{
	char keys[][8] = { "the", "a", "there", "answer", "any",
					"by", "bye", "their" };

	char output[][32] = { "Not present in trie", "Present in trie" };


	//construct trie

	TrieNode* root = getNode(NULL);

	for (int i = 0; i < ARRAY_SZIE(keys); i++)
	{
		insert(root, keys[i]);
	}



	printf("%s --- %s\n", "the", output[search(root, "the")]);
	printf("%s --- %s\n", "these", output[search(root, "these")]);
	printf("%s --- %s\n", "their", output[search(root, "their")]);
	printf("%s --- %s\n", "thaw", output[search(root, "thaw")]);

	return 0;
}
