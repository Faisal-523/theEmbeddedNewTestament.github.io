> ## 🚀 Practice & deep-dive on EmbeddedInterviewLab
>
> Solve embedded-flavored coding problems in-browser with AI-graded feedback, and browse the ranked question bank.
>
> 👉 **[Practice coding problems with AI feedback →](https://embeddedinterviewlab.com/coding?utm_source=github&utm_medium=referral&utm_campaign=kb_cta&utm_content=data_struct_implementation)** &nbsp;·&nbsp; **[Open the Interview Question Bank →](https://embeddedinterviewlab.com/questions?utm_source=github&utm_medium=referral&utm_campaign=kb_cta&utm_content=data_struct_implementation)**

---

```c
#include<stdio.h>
#include<stdint.h>

// Task: Swap all odd and even bits
// Tips: get the number with all odd bits and all even bits first and then or them together.
uint32_t swapOddEven(uint32_t target) {
    return ((target & 0xaaaaaaaa) >> 1) | ((target & 0x55555555) << 1);
}

int main(void) {
    // test 1:
    uint32_t test1 = 0xa;
    printf("%x\n", swapOddEven(test1));
    
    // test 2:
    uint32_t test2 = 0x5;
    printf("%x\n", swapOddEven(test2));
    
    // test 3:
    uint32_t test3 = 0xff;
    printf("%x\n", swapOddEven(test3));
    
    // test 4:
    uint32_t test4 = 0xaa;
    printf("%x\n", swapOddEven(test4));
    
    return 0;
}
```