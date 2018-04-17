#pragma once
#include<string>
#include<stdlib.h>
#include <fstream>
#include <iostream>
#include <map>
#include<vector>
#include <queue>
using namespace std;
//https://www.geeksforgeeks.org/greedy-algorithms-set-3-huffman-coding/


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


// For comparison of
// two heap nodes (needed in min heap)
// utility function for the priority queue
struct compare {

	bool operator()(HuffmanNode* l, HuffmanNode* r)

	{
		return (l->freq > r->freq);
	}
};





