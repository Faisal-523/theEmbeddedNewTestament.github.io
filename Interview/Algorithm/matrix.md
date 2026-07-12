> ## 🚀 Practice & deep-dive on EmbeddedInterviewLab
>
> Solve these in-browser with a C/C++ editor and AI-graded evaluation, and browse the ranked question bank.
>
> 👉 **[Practice coding problems with AI feedback →](https://embeddedinterviewlab.com/coding?utm_source=github&utm_medium=referral&utm_campaign=kb_cta&utm_content=interview_algorithm)** &nbsp;·&nbsp; **[Open the Interview Question Bank →](https://embeddedinterviewlab.com/questions?utm_source=github&utm_medium=referral&utm_campaign=kb_cta&utm_content=interview_algorithm)**

---

## Problems

1. Diagonal Traverse


## Implementation

### **Diagonal Traverse**

***Big O:*** O(n*m) speed, O(min(n,m)) space
```
Tips: 

```
```c++
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0)
            return vector<int>();
        
        int cols = matrix[0].size();
        if (cols == 0)
            return vector<int>();
        
        int dig_size = rows + cols - 1;
        
        vector<int> ret;
        int i = 0, j = 0;
        for (int k = 1; k <= dig_size; k++) {
            vector<int> diag{};
            i = k >= rows ? rows-1 : k-1;
            j = k >= rows ? k-rows : 0;
            while(i >= 0 && j < cols) {
                diag.push_back(matrix[i][j]);
                i--;
                j++;
            }
            if (k%2 == 0)
                reverse(diag.begin(), diag.end());
            ret.insert(ret.end(), diag.begin(), diag.end());
        }
        
        return ret;
    }
};
```
