---
description: 📘 LeetCode 80
---

# Remove Duplicates from Sorted Array II

***

### 🔥 Problem Summary

* Array sorted (non-decreasing)
* প্রতিটা unique number **at most 2 times** থাকতে পারবে
* In-place modify করতে হবে
* Extra array ব্যবহার করা যাবে না
* Return করতে হবে `k` (final valid length)

***

### 🧠 Key Difference (26 vs 80)

| Problem | Allow                     |
| ------- | ------------------------- |
| 26      | Each number once          |
| 80      | Each number at most twice |

***

## 🟢 Core Idea → Two Pointer

আমরা একটা `write` pointer ব্যবহার করবো।

#### Trick:

আমরা check করবো:

```
Current number == nums[write-2] ?
```

👉 যদি equal হয় → already 2টা আছে → skip\
👉 না হলে → add করবো

***

## 🔥 কেন `write-2`?

কারণ:

আমরা চাই সর্বোচ্চ 2টা রাখবো।

যদি current element `nums[write-2]` এর সমান হয়,\
তাহলে তার মানে:

👉 আগের দুইটা already same\
👉 তাই এটা 3rd copy\
👉 skip

***

## 🧩 Example

Input:

```
[1,1,1,2,2,3]
```

***

#### Step-by-step

Start:

```
write = 0
```

***

#### num = 1

write < 2 → always allowed

Array:

```
[1]
```

***

#### num = 1

write < 2 → allowed

Array:

```
[1,1]
```

***

#### num = 1

Check:

```
nums[write-2] = nums[0] = 1
```

Equal → skip ❌

***

#### num = 2

Check:

```
nums[write-2] = nums[0] = 1
```

Not equal → add ✅

Array:

```
[1,1,2]
```

***

#### num = 2

Check:

```
nums[write-2] = nums[1] = 1
```

Not equal → add ✅

Array:

```
[1,1,2,2]
```

***

#### num = 3

Check:

```
nums[write-2] = nums[2] = 2
```

Not equal → add ✅

Final:

```
[1,1,2,2,3]
```

Return k = 5

***

## 💻 Code (Python)

```
class Solution(object):
    def removeDuplicates(self, nums):
        write = 0
        
        for num in nums:
            if write < 2 or num != nums[write-2]:
                nums[write] = num
                write += 1
        
        return write
```

***

## ⏱ Complexity

```
Time  = O(n)
Space = O(1)
```

***

## 🎯 Pattern Name

👉 Two Pointer (Controlled Frequency)

***

## 🔥 Ultimate Pattern Trick

For:

```
Allow at most K duplicates
```

Just change:

```
if write < K or num != nums[write-K]:
```

***

### 🔥 General Template

```
def removeDuplicates(nums, K):
    write = 0
    for num in nums:
        if write < K or num != nums[write-K]:
            nums[write] = num
            write += 1
    return write
```

***
