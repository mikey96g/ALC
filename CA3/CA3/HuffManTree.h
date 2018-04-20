#pragma once
#include<string>
#include<stdlib.h>
#include <fstream>
#include <iostream>
#include <map>
#include<vector>
#include <queue>
using namespace std;


/***************************************************************************************

*    Usage: <used>
*    Title: Huffman Decoding
*    Author: Harshit Sidhwa
*    Date: 19/04/2018
*    Availability: https://www.geeksforgeeks.org/huffman-decoding/
*
***************************************************************************************/

struct HuffmanNode
{
	char character;
	int freq;
	HuffmanNode *leftPtr, *rightPtr;
	HuffmanNode(char character, int freq)
	{
		leftPtr = rightPtr = NULL;
		this->character = character;
		this->freq = freq;
	}
};


// For comparison of two heap nodes (needed in min heap)
struct compare {

	bool operator()(HuffmanNode* l, HuffmanNode* r)

	{
		return (l->freq > r->freq);
	}
};





