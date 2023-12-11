## Competitive Programming | DSA | C++/Python

~ This repo consists of all important algos which are trial and tested in live contests. More algos on the way to be added :) ...

### Sliding Window Technique
1. `Fixed` Sliding Window template
```cpp
int i = 0, j = 0;
while(j < n){
    // operation
    if(j - i + 1 < k) ++j;
    else if(j - i + 1 == k){
        // operations
        ++i; ++j; // window shifted
    }
}
```

2. `Variable` Sliding Window template
```cpp
int i = 0, j = 0;
// k => some value which we have to achieve!! (Depends on Question)
while(j < n){
    // operation
    if(condition < k){
        ++j;
    }
    else if(condition == k){
        // answer calculation
        ++j;
    }
    else if(condition > k){
        while(condition > k){
            // remove calculation for i
            ++i;
        }
        ++j;
    }
}
```

### Stack 

- Resources <br>
https://leetcode.com/discuss/study-guide/2347639/A-comprehensive-guide-and-template-for-monotonic-stack-based-problems

### Dynamic Programming (DP)
- Important concept <br>

- Resources <br>


### OOPs 

- Resources <br>
https://leetcode.com/discuss/interview-question/3828150/OOPS-Cheatsheet-for-Interviews-or-30-questions

### DBMS
1. refer: https://leetcode.com/discuss/study-guide/3823497/dbms-cheatsheet-for-interviews-30-questions
