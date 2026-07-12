> ## 🚀 Practice & deep-dive on EmbeddedInterviewLab
>
> Solve embedded-flavored coding problems in-browser with AI-graded feedback, and browse the ranked question bank.
>
> 👉 **[Practice coding problems with AI feedback →](https://embeddedinterviewlab.com/coding?utm_source=github&utm_medium=referral&utm_campaign=kb_cta&utm_content=data_struct_implementation)** &nbsp;·&nbsp; **[Open the Interview Question Bank →](https://embeddedinterviewlab.com/questions?utm_source=github&utm_medium=referral&utm_campaign=kb_cta&utm_content=data_struct_implementation)**

---

## StrStr
#### Usage
```
make
./strstr
```

#### Analysis

#### Code
```c
#include <stdio.h>
 
// returns true if X and Y are same
int compare(const char *X, const char *Y)
{
    while (*X && *Y)
    {
        if (*X != *Y)
            return 0;
 
        X++;
        Y++;
    }
 
    return (*Y == '\0');
}
 
// Function to implement strstr() function
const char* strstr(const char* X, const char* Y)
{
    while (*X != '\0')
    {
        if ((*X == *Y) && compare(X, Y))
            return X;
        X++;
    }
 
    return NULL;
}
 
// Implement strstr function in C
int main()
{
    char *X = "Techie Delight - Coding made easy";
    char *Y = "Coding";
 
    printf("%s\n", strstr(X, Y));
 
    return 0;
}
```

### Reference

https://www.techiedelight.com/implement-strstr-function-c-iterative-recursive/