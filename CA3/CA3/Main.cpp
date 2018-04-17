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
//https://www.geeksforgeeks.org/huffman-decoding/
//https://stackoverflow.com/questions/4527686/how-to-update-stdmap-after-using-the-find-method
//https://stackoverflow.com/questions/478075/creating-files-in-c

map<char, int >charList;
map<char, string> codes;

// Prints huffman codes from
// the root of Huffman Tree.
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

void printCodes(struct HuffmanNode* root, string str)
{
	if (!root)
		return;
	if (root->character != '$')
		cout << root->character << ": " << str << "\n";

	printCodes(root->leftPtr, str + "0");
	printCodes(root->rightPtr, str + "1");
}

void storeCodes(struct HuffmanNode* root, string str)
{
	if (root == NULL)
		return;
	if (root->character != '$')
		codes[root->character] = str;
	storeCodes(root->leftPtr, str + "0");
	storeCodes(root->rightPtr, str + "1");
}

priority_queue<HuffmanNode*, vector<HuffmanNode*>, compare> minHeap;

void HuffmanCodes(int size)
{
	struct HuffmanNode *left, *right, *top;

	// Create a min heap & inserts all characters of data[]
	
	for (map<char, int>::iterator v = charList.begin(); v != charList.end(); v++)
		minHeap.push(new HuffmanNode(v->first, v->second));

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
	//printCodes(minHeap.top(), "");
	storeCodes(minHeap.top(), "");
}

void encode()
{
	ifstream infile;
	char ch;
	string temp;

	infile.open("Source.txt");
	ofstream outfile("encoded.txt");

	ch = infile.get();
	while (ch != EOF)
	{
		temp = codes.at(ch);
		outfile << temp;
		ch = infile.get();

	}
	outfile.close();
}

void decode(struct HuffmanNode* root)
{
	string ans = "";
	ifstream infile;
	ofstream outfile("decoded.txt");
	infile.open("encoded.txt");

	string encodedString;
	while (getline(infile, encodedString));
	struct HuffmanNode* current = root;
	for (int i=0;i<encodedString.size();i++)
	{
		if (encodedString[i] == '0')
			current = current->leftPtr;
		else
			current = current->rightPtr;

		if(current->leftPtr==NULL and current->rightPtr==NULL)
		{
			ans += current->character;
			current = root;
		}		
	}
	outfile << ans;
	outfile.close();

	//return ans+'\0';
};

int main()
{
	char size = charList.size();
	
	
	characterFreq();
	HuffmanCodes(size);
	cout << endl;
	printCodes(minHeap.top(), "");

	cout << endl;
	cout << endl;
	decode(minHeap.top());


	system("pause");
	return 0;
}