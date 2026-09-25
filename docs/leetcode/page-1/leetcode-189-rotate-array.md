# 📘 LeetCode 189 – Rotate Array

### Reverse Algorithm (Line by Line Explanation)

#### Code

```
class Solution(object):
    def rotate(self, nums, k):
        n = len(nums)
        k = k % n

        nums.reverse()
        nums[:k] = reversed(nums[:k])
        nums[k:] = reversed(nums[k:])
```

***

## 🧠 Full Process Summary

Original

```
[1,2,3,4,5,6,7]
```

Step 1 reverse

```
[7,6,5,4,3,2,1]
```

Step 2 reverse first k

```
[5,6,7,4,3,2,1]
```

Step 3 reverse rest

```
[5,6,7,1,2,3,4]
```

***

## ⏱ Complexity

Time = O(n)\
Space = O(1)
