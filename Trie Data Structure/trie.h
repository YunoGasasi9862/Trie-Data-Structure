 #pragma once

#define ARRAY_SZIE(a) sizeof(a)/sizeof(a[0]) //this is a way to define your own formulas

#define ALPHABET_SIZE 26

//converts key current character into index
#define CHAR_TO_INDEX(c) ((int)c-(int)'a') //another formula
typedef char TType;
//trie node

typedef struct TrieNode
{
	struct TrieNode* children[ALPHABET_SIZE];
	TType data; //this is my own addition!!

	//isEndofWord is true if the node represents
	//end of a word

	bool isEndofWord;

}TrieNode;

//Returns new trie node (the rest of the children will be initialized to NULL
TrieNode* getNode(TType data)
{
	TrieNode* pNode = NULL;

	pNode = (TrieNode*)malloc(sizeof(TrieNode));

	if (pNode)  //if the Node exists now
	{
		pNode->isEndofWord = false;
		pNode->data = data;

		for (int i = 0; i < ALPHABET_SIZE; i++)
		{
			pNode->children[i] = NULL;
		}
	}
	return pNode;


}

//If not present, inserts key into trie
//If the key is prefix of trie node, just marks the leaf node
void insert(TrieNode* root, const char* key)
{
	int level; //at which level
	int length = strlen(key);
	int index;

	TrieNode* pCrawl = root; //temporary

	for (level = 0; level < length; level++)
	{
		index = CHAR_TO_INDEX(key[level]); //characters in string

		if (!pCrawl->children[index]) //if that character doesn't exist, then add it
			pCrawl->children[index] = getNode(key[level]);

		pCrawl = pCrawl->children[index];
	}

	pCrawl->isEndofWord = true; //marks the last node as true


}

bool search(TrieNode* root, const char* key) //search function is similar to insert
{
	int level;
	int length = strlen(key);
	int index;
	
	TrieNode* temp = root;

	for (level = 0; level < length; level++)
	{

		index = CHAR_TO_INDEX(key[level]);

		if (!temp->children[index])
			return false;

		temp = temp->children[index];
	}

	return (temp->isEndofWord); //it means return true!

}
//returns true if root has no children, else false
bool isEmpty(TrieNode* root)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (root->children[i])
			return false;

	return true;

}

//Recursive fucntion to delete a key from given Trie
TrieNode* remove(TrieNode* root, char* key, int depth = 0) //we can initialiaze depth up there too
{
	//if tree is empty
	if (!root)
		return NULL;

	//if last character of key is being processed
	if (depth == strlen(key))
	{

		//This node is no more end of word after
		//removal of given key
		if (root->isEndofWord)
			root->isEndofWord = false;


		//if given is not prefix of any other word
		if (isEmpty(root))  //this checks if the root has any children, or is a prefix of other word. If not, then delete the whole trie
		{
			delete root;  //delete works in c too
			root = NULL;
		}

		return root; //Trie deleted!
	}

	//If not last character, recur for the child (if its the prefix of some other root)
	//obtained using ASCII value
	int index = key[depth] - 'a'; //if depth is 0 which is the first character
	root->children[index] = remove(root->children[index], key, depth + 1); //increase the depth now.


	
	//if root does not have any child (it's only child got deleted), and is is not end of another word.

	if (isEmpty(root) && root->isEndofWord == false)
	{
		delete root;
		root = NULL;
	}
	return root;

}