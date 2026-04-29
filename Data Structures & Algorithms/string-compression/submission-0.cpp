class Solution {
public:
    int compress(vector<char>& chars) {
        
        int n=chars.size(),read=0,write=0;

        while(read<n){
            char current=chars[read];
            int len=0;

            while(read<n && chars[read]==current){
                read++;
                len++;
            }
            chars[write++]=current;

            if(len>1){
                string ctr=to_string(len);
                for(char c:ctr){
                    chars[write++]=c;
                }
            }
        }
        return write;
    }
};