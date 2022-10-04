//! Question https://leetcode.com/problems/palindrome-pairs/

bool isPalindrome(string &word, int l, int r)
{
  while (l < r)
  {
    if (word[l] != word[r])
      return false;
    l++;
    r--;
  }
  return true;
}
vector<vector<int>> palindromePairs(vector<string> &words)
{
  unordered_map<string, int> mp;
  vector<vector<int>> ans;
  for (int i = 0; i < words.size(); ++i)
  {
    if (words[i] == "")
      continue;
    string str = words[i];
    // Inserting reverse so that we dont have to reverse every substring in later part
    reverse(begin(str), end(str));
    mp[str] = i;
  }
  for (int i = 0; i < words.size(); ++i)
  {
    if (words[i] == "")
    {
      for (int j = 0; j < words.size(); ++j)
        if (i != j && isPalindrome(words[j], 0, words[j].size() - 1))
        {
          ans.push_back({i, j});
          ans.push_back({j, i});
        }
      continue;
    }
    for (int cut = 0; cut < words[i].size(); ++cut)
    {
      // Current String gives Left + Mid
      // We need to check whether Mid is Palindrome or not
      // If yes, we need to search for Right
      //  Left = {0, cut-1}
      //  Mid = {cut, words[i].size() - 1}
      if (isPalindrome(words[i], cut, words[i].size() - 1))
      {
        string right = words[i].substr(0, cut);
        if (mp.find(right) != end(mp) && mp[right] != i)
        {
          ans.push_back({i, mp[right]});
        }
      }
      // Current String gives Mid + Right
      // We need to check whether Mid is Palindrome or not
      // If yes, we need to search for Left
      //  Mid = {0, cut-1}
      //  Right = {cut, words[i].size() - 1}
      if (isPalindrome(words[i], 0, cut - 1))
      {
        string left = words[i].substr(cut);
        if (mp.find(left) != end(mp) && mp[left] != i)
        {
          ans.push_back({mp[left], i});
        }
      }
    }
  }
  return ans;
}
