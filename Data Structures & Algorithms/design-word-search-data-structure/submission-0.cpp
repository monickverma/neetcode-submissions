struct Trie {
    Trie* children[26];
    bool terminal;

    Trie() {
        terminal = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class WordDictionary {
public:
    Trie* root;

    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie* node = root;

        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx])
                node->children[idx] = new Trie();
            node = node->children[idx];
        }
        node->terminal = true;
    }
    
    bool search(string word) {
        return searchInNode(word, 0, root);
    }

private:
     bool searchInNode(const string &word, int index, Trie* node) {
if(!node) return false;

if(index==word.size())return node->terminal;

char ch=word[index];

if(ch=='.'){
for(int i=0;i<26;i++){
		if(node->children[i] && searchInNode(word,index+1,node->children[i])) return true;
	}
}
else{
	int idx=ch-'a';
	return searchInNode(word,index+1,node->children[idx]);
}


 }
};
