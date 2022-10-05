// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

// making node
struct Node{
  Node* arr[2];
  bool contain(int bit){
      return arr[bit]!=NULL;
  }
  void put(int bit, Node* node){
      arr[bit] = node;
  }
  Node* get(int bit){
      return arr[bit];
  }
  
};

// Intialise a trie data structure
class Trie{
  Node* root;
  public:
    Trie(){
        root = new Node();
    }
    
//   Insert number in a trie
    void insert(int num){
        Node* node = root;
        for(int i = 31; i>=0; i--){
            int bit = (num>>i)&1;
            if(!node -> contain(bit)){
               node ->  put(bit,new Node());
            }
            node = node->get(bit);
        }
    }
  // Getting maximum xor of element num in with other element
    int getMax(int num){
        Node* node = root;
        int val = 0;
        for(int i = 31; i>=0; i--){
            int bit = (num>>i)&1;
            if(node->contain(1-bit)){
                val = val | (1<<i);
                node = node -> get(1-bit);
            }
            else{
                node = node -> get(bit);
            }
        }
        return val;
    }
};

// Find Maximum xor of two elements in an array

int findMaximumXOR(vector<int>& nums) {
    int n = nums.size();
    Trie trie;
    for(int i = 0; i<n; i++)trie.insert(nums[i]);
    int mx = 0;
    for(int i = 0; i<n; i++){
        mx = max(mx, trie.getMax(nums[i]));
    }
    return mx;
}
