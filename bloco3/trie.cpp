/*
 * Victor Rofrigues da Silva  NUSP: 12566140
 *
 * find total occurences of a word in given text
 *
 *  */

#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

typedef struct trieNode
{
	struct trieNode *prox[ALPHABET_SIZE];

	int words_here;
	bool fim;
} TrieNode;

TrieNode *criaNode(void)
{
	TrieNode *no = new TrieNode;

	no->fim = false;
	no->words_here = 0;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		no->prox[i] = NULL;

	return no;
}

void insert(TrieNode *raiz, string chave)
{
	TrieNode *p = raiz;

	for (int i = 0; i < (int)chave.length(); i++)
	{
		int index = chave[i] - 'a';
		if (!p->prox[index])
			p->prox[index] = criaNode();
		p->fim = false;
		p = p->prox[index];
		p->words_here++;
	}

	p->fim = true;
}

void remove(TrieNode *raiz, string chave)
{
	TrieNode *p = raiz;

	for (int i = 0; i < (int)chave.length(); i++)
	{
		int index = chave[i] - 'a';
		p->words_here--;
		if (p->words_here == 0)
			p->fim = true;
		p = p->prox[index];
	}
	p->words_here--;
	if (p->words_here == 0)
		p->fim = true;
}

int search(TrieNode *raiz, string chave)
{
	TrieNode *p = raiz;

	for (int i = 0; i < (int)chave.length(); i++)
	{
		int index = chave[i] - 'a';
		if (!p->prox[index] || p->prox[index]->words_here == 0)
			return false;

		p = p->prox[index];
	}

	return p->words_here;
}

int main()
{
	TrieNode *raiz = criaNode();
	string s;
	int operation, total_commands;

	cin >> total_commands;

	for (int i = 0; i < total_commands; i++)
	{

		cin >> operation;
		cin >> s;

		switch (operation)
		{
		case 1:
			insert(raiz, s);
			break;

		case 2:
			remove(raiz, s);
			break;

		case 3:
			cout << search(raiz, s) << '\n';
			break;
		default:
			break;
		}
	}

	return 0;
}
