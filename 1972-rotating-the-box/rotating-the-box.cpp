class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int rows= box.size(), cols=box[0].size();
        vector<vector<char>>res(cols, vector<char>(rows, '.'));

        for(int i=0; i<rows; i++){
            int emptyPos=cols-1;
            for(int j=cols-1; j>=0; j--){
                if(box[i][j]=='*'){
                    res[j][rows-i-1]='*';
                    emptyPos=j-1;
                }else if(box[i][j]=='#'){
                    res[emptyPos][rows-i-1]='#';
                    emptyPos--;
                }
            }
        }
        return res;
    }
};