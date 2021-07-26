//https://leetcode.com/problems/zigzag-conversion/submissions/
//Run Code 수행 시 OK 하지만 Submit시에 같은 input에서 오류 발생

char textData[1001][1001] = {'\0', };
string strResult;

class Solution {
public:
    string convert(string s, int numRows) {     
        int ll = 0;  int cc = 0;
        string::iterator iter;
        bool movetrigger = true;
        textData[ll][cc] = s.front();
        
        if(numRows ==1) return s;
        
        for(iter=s.begin()+1; iter!=s.end(); iter++){
            if(ll <= 0 || ll == numRows-1){
                if(movetrigger) movetrigger = false;
                else movetrigger = true;
            }
            
            if(movetrigger){
                ll--;
                cc++;
            }
            else{
                ll++;
            }
            
            textData[ll][cc] = *iter;
        }
        
        printdata(numRows, s.length());
        
        return strResult;
    }
    
    void printdata(int numRows, int len)
    {
        int sum = 0;
        for(int i=0;i<=numRows;i++)
        {
            for(int j=0;j<100;j++)
            {
                if(textData[i][j] != '\0'){
                    cout << textData[i][j];
                    strResult.push_back(textData[i][j]);
                    sum++;
                    if(sum == len) return;
                }
                else cout << " ";
            }
            cout << endl;
        }
    }
    
};
