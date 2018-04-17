//Michael Gallagher
#include "HuffManTree.h"
#include<string>
#include<cstdlib>
#include <fstream>
#include <iostream>
#include <map>
using namespace std;
//http://www.cplusplus.com/forum/beginner/66019/
//http://www.dreamincode.net/forums/topic/49604-letter-frequencies-in-a-text-file/

map<char, int >charList;

// Prints huffman codes from
// the root of Huffman Tree.
void printCodes(struct HuffmanNode* root, string str)
{

	if (!root)
		return;

	if (root->character != '$')
		cout << root->character << ": " << str << "\n";

	printCodes(root->leftPtr, str + "0");
	printCodes(root->rightPtr, str + "1");
}

void HuffmanCodes(char characters[], int freq[], int size)
{
	struct HuffmanNode *left, *right, *top;

	// Create a min heap & inserts all characters of data[]
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, compare> minHeap;

	for (int i = 0; i < size; ++i)
		minHeap.push(new HuffmanNode(characters[i], freq[i]));
	// Iterate while size of heap doesn't become 1
	while (minHeap.size() != 1) {

		// Extract the two minimum
		// freq items from min heap
		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		// Create a new internal node with
		// frequency equal to the sum of the
		// two nodes frequencies. Make the
		// two extracted node as left and right children
		// of this new node. Add this node
		// to the min heap '$' is a special value
		// for internal nodes, not used
		top = new HuffmanNode('$', left->freq + right->freq);

		top->leftPtr = left;
		top->rightPtr = right;

		minHeap.push(top);
	}
	// Print Huffman codes using
	// the Huffman tree built above
	printCodes(minHeap.top(), "");
}

void characterFreq()
{
	ifstream infile;
	char ch;

	infile.open("Source.txt");
	

	ch = infile.get();
	while (ch != EOF)
	{
		charList[ch]++;
		ch = infile.get();
	}
	for (auto character : charList)
	{
		cout << character.first << " : " << character.second << "\n";
	}
}

int main()
{
	

	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	int freq[] = { 5, 9, 12, 13, 16, 45 };

	int size = sizeof(arr) / sizeof(arr[0]);
	characterFreq();
	HuffmanCodes(arr, freq, size);

	system("pause");
	return 0;
}