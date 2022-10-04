//! Question: https://leetcode.com/problems/design-add-and-search-words-data-structure/

/** Initialize your data structure here. */
unordered_map<int, vector<string>> mp;
WordDictionary()
{
	mp.clear();
}

/** Adds a word into the data structure. */
void addWord(string word)
{
	mp[word.size()].push_back(word);
}

/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
bool isSame(string str, string word)
{
	if (str == word)
		return true;
	int n = word.size();
	for (int i = 0; i < n; i++)
	{
		if (word[i] == '.')
			continue;
		else if (word[i] != str[i])
			return false;
	}
	return true;
}
bool search(string word)
{
	int n = word.size();
	if (mp.find(n) != mp.end())
	{
		auto temp = mp[n];
		for (auto str : temp)
		{
			if (isSame(str, word))
			{
				return true;
			}
		}
		return false;
	}
	else
		return false;
}
