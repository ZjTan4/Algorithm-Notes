/*
4-1 Word Ladder
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

    Only one letter can be changed at a time.
    Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

Note:

    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.
    You may assume no duplicates in the word list.
    You may assume beginWord and endWord are non-empty and are not the same.
    You may assume endWord is a transformed word.

输入

第一行，字符串beginWord。 第二行，字符串endWord。 第三行，word list中的word个数N(1=<N<=50)。 后面N行为N个word list中的word。 (beginWord, endWord和word list中word的长度l的范围为3<=l<=5)
输出shortest transformation sequence 的长度，如果不存在则输出0。
Example

Input:

    hit
    cog
    6
    hot
    dot
    dog
    lot
    log
    cog

Output:

    5

Explanation:
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog", return its length 5.
*/

#include<iostream>
#include<string>

using namespace std;

//count the number of deferent latters of 2 strings 
int compare(string a, string b)
{
	int count = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])count++;
	}
	return count;
}

//judge if the seleted word in wordList has been compared before
bool InIndex(int a[], int index,int count)
{
	for (int i = 0; i < count; i++)
	{
		if (a[i] == index)return true;
	}
	return false;
}

int main()
{
	string beginWord, endWord;
	cin >> beginWord >> endWord;
	int N;
	cin >> N;
	string *wordList = new string[N];
	for (int i = 0; i < N; i++)
	{
		cin >> wordList[i];
	}
	int *index = new int[N];
	int count = 0;
	string ptr = beginWord;
	while (true)
	{
		int isFound = 0;
		for (int i = 0; i < N ; i++)
		{
            //see if the seleted word has been compared before
			if (InIndex(index, i, count))continue;
			
            if (compare(wordList[i],ptr)==1)
			{
				ptr = wordList[i];
				index[count] = i;
				count++;
				isFound = 1;
				break;
			}
		}

        //judge if the path to transformed word is found
		if (compare(ptr,endWord)==1)
		{
			count += 2;
			break;
		}

        //judge if the path to transformed word exists
		if (isFound == 0)
		{
			count = 0;
			break;
		}
	}
	cout << count << endl;
}