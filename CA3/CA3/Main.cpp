//Michael Gallagher
#include "HuffManTree.h"
#include<string>
#include<cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <bitset>
#include <sstream>
using namespace std;
// to store the frequency of character of the input data
map<char, int >charList;
// to map each character its huffman value
map<char, string> codes;


/***************************************************************************************

*    Usage: <modified>
*    Title: <Letter Frequencies In A Text File>
*    Author: <NickDMax>
*    Date: <18/04/2018>
*    Availability: <http://www.dreamincode.net/forums/topic/49604-letter-frequencies-in-a-text-file/>
*
***************************************************************************************/
/***************************************************************************************

*    Usage: <modified>
*    Title: <Letter Frequencies>
*    Author: <kdmpenguin>
*    Date: <18/04/2018>
*    Availability: <http://www.cplusplus.com/forum/beginner/66019/>
*
***************************************************************************************/
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

/***************************************************************************************

*    Usage: <used>
*    Title: Huffman Decoding
*    Author: Harshit Sidhwa
*    Date: 19/04/2018
*    Availability: https://www.geeksforgeeks.org/huffman-decoding/
*
***************************************************************************************/
//Prints the huffman codes
void printCodes(struct HuffmanNode* root, string str)
{
	if (!root)
		return;
	if (root->character != '¬')
		cout << root->character << ": " << str << "\n";

	printCodes(root->leftPtr, str + "0");
	printCodes(root->rightPtr, str + "1");
}

// utility function to store characters along with
// there huffman value in a hash table,
void storeCodes(struct HuffmanNode* root, string str)
{
	if (root == NULL)
		return;
	if (root->character != '¬')
		codes[root->character] = str;
	storeCodes(root->leftPtr, str + "0");
	storeCodes(root->rightPtr, str + "1");
}

// STL priority queue to store heap tree, with respect
// to their heap root node value
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
		// to the min heap '¬' is a special value
		// for internal nodes, not used
		top = new HuffmanNode('¬', left->freq + right->freq);

		top->leftPtr = left;
		top->rightPtr = right;
		minHeap.push(top);
	}
	
	storeCodes(minHeap.top(), "");
}

/***************************************************************************************

*    Usage: <used>
*    Title: <std::map>
*    Author: <cplusplus>
*    Date: <19/04/2018>
*    Availability: <http://www.cplusplus.com/reference/map/map/>
*
***************************************************************************************/
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

/***************************************************************************************

*    Usage: <used>
*    Title: Huffman Decoding
*    Author: Harshit Sidhwa
*    Date: 19/04/2018
*    Availability: https://www.geeksforgeeks.org/huffman-decoding/
*
***************************************************************************************/
// function iterates through the encoded string 
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
		if (encodedString[i] == '0')// if s[i]=='0' then move to node->left
			current = current->leftPtr;
		else
			current = current->rightPtr;// if s[i]=='1' then move to node->right

		if(current->leftPtr==NULL and current->rightPtr==NULL)// if leaf node append the node->data to our output string
		{
			ans += current->character;
			current = root;
		}		
	}
	outfile << ans;
	outfile.close();	
};

/***************************************************************************************

*    Usage: <modified>
*    Title: <Convert a string of binary into an ASCII string (C++)>
*    Author: <Dale Wilson>
*    Date: <20/04/2018>
*    Availability: <https://stackoverflow.com/questions/23344257/convert-a-string-of-binary-into-an-ascii-string-c>
*
***************************************************************************************/

void compress()
{	
	ifstream infile;
	ofstream outfile("compressed.txt");

	infile.open("encoded.txt");
	string encodedString;
	while (getline(infile, encodedString));
	stringstream sstream(encodedString);
	string output;

	while (sstream.good())
	{
		bitset<8> Eight_bits;
		sstream >> Eight_bits;
		char c = char(Eight_bits.to_ulong());
		output += c;
	}
	outfile << output;
	outfile.close();
}

//void decompress()
//{
//	Couldnt get it work
//	
//}

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