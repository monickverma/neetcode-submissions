class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> ans=exist(board,words);
    return ans;
    }

    vector<string> exist(vector<vector<char>>& board, vector<string>& words){
        int m=board.size();
        int n=board[0].size();
        unordered_set<string> uniqueWords;


        for(auto word: words)
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(dfs(board,word,i,j,0))
                    uniqueWords.insert(word); 

        return vector<string>(uniqueWords.begin(), uniqueWords.end());
    }

    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index){
        if(index==word.length())return true;

        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[index]) return false;

        char temp=board[i][j];
        board[i][j]='#';

        bool found= dfs(board, word,i+1,j,index+1)||
                    dfs(board, word,i-1,j,index+1)||
                    dfs(board, word,i,j+1,index+1)||
                    dfs(board, word,i,j-1,index+1);
        
        board[i][j]=temp;
        return found;
    }
    
};
/*
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct TrieNode {
    TrieNode* children[26] = {};
    string word = "";
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->word = word;
    }
};

class Solution {
private:
    int m, n;
    vector<vector<char>> board;
    vector<string> result;
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    
    void dfs(int i, int j, TrieNode* node) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '#' || !node->children[board[i][j] - 'a'])
            return;

        char c = board[i][j];
        node = node->children[c - 'a'];

        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = "";  // Avoid duplicates
        }

        board[i][j] = '#';  // Mark visited

        for (const auto& dir : directions) {
            int ni = i + dir[0], nj = j + dir[1];
            dfs(ni, nj, node);
        }

        board[i][j] = c;  // Restore the board
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        this->board = board;
        m = board.size();
        n = board[0].size();

        Trie trie;
        for (const string& word : words) trie.insert(word);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(i, j, trie.root);
            }
        }
        
        return result;
    }
};

int main() {
    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };
    vector<string> words = {"oath", "pea", "eat", "rain"};

    Solution solution;
    vector<string> result = solution.findWords(board, words);

    for (const string& word : result) {
        cout << word << " ";
    }
    return 0;
}
*/