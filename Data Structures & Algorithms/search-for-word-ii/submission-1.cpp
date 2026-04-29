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