---
description: Jump Game II
---

# 📘 LeetCode 45

## 🔥 Problem

একটা array `nums` দেওয়া আছে।

```
nums[i] = maximum jump length from index i
```

তুমি **index 0 থেকে শুরু করবে**।

তোমাকে বের করতে হবে:

```
minimum number of jumps
```

যাতে তুমি **last index (n-1)** এ পৌঁছাতে পারো।

***

## 🧩 Example

#### Example 1

```
nums = [2,3,1,1,4]
```

Possible path

```
0 → 1 → 4
```

Jumps

```
2
```

Output

```
2
```

***

#### Example 2

```
nums = [2,3,0,1,4]
```

Possible path

```
0 → 1 → 4
```

Output

```
2
```

***

## 🧠 Key Idea (Greedy + Range)

আমরা একটা **window / range** ধরে এগোবো।

আমরা track করবো:

```
currentEnd → current jump range শেষ
farthest   → next jump এ maximum কোথায় যেতে পারবো
jumps      → total jumps
```

***

## 🪜 Intuition

ধরো তুমি একটা range এর মধ্যে আছো।

```
currentEnd
```

এর মধ্যে যতগুলো position আছে সেগুলো দেখে **farthest reach** বের করবো।

যখন range শেষ হবে:

```
jump++
currentEnd = farthest
```

***

## 💻 Python Code

```
class Solution(object):
    def jump(self, nums):
        jumps = 0
        currentEnd = 0
        farthest = 0

        for i in range(len(nums) - 1):
            farthest = max(farthest, i + nums[i])

            if i == currentEnd:
                jumps += 1
                currentEnd = farthest

        return jumps
```

***

## 🔎 Line by Line Explanation

***

### jumps variable

```
jumps = 0
```

Minimum jumps count করার জন্য।

***

### current range end

```
currentEnd = 0
```

এই jump এ আমরা **কোথায় পর্যন্ত যেতে পারি**।

***

### farthest reachable

```
farthest = 0
```

Next jump এ **maximum কোথায় যেতে পারবো**।

***

### loop

```
for i in range(len(nums)-1):
```

Last index এ jump করার দরকার নেই।

তাই

```
n-1 পর্যন্ত loop
```

***

### farthest update

```
farthest = max(farthest, i + nums[i])
```

Example

```
i = 1
nums[i] = 3
```

```
i + nums[i] = 4
```

Update

```
farthest = 4
```

***

### jump condition

```
if i == currentEnd:
```

মানে

```
current jump range শেষ
```

তাই

```
new jump নিতে হবে
```

***

### increase jump

```
jumps += 1
```

***

### update range

```
currentEnd = farthest
```

Next jump এ আমরা **farthest পর্যন্ত যেতে পারবো**।

***

## 🪜 Dry Run

Input

```
[2,3,1,1,4]
```

Start

```
jumps = 0
currentEnd = 0
farthest = 0
```

***

#### i = 0

```
farthest = max(0 , 0+2)
farthest = 2
```

```
i == currentEnd
```

Jump

```
jumps = 1
currentEnd = 2
```

***

#### i = 1

```
farthest = max(2 , 1+3)
farthest = 4
```

***

#### i = 2

```
farthest = max(4 , 2+1)
farthest = 4
```

```
i == currentEnd
```

Jump

```
jumps = 2
currentEnd = 4
```

Reached last index ✅

***

## ⏱ Complexity

```
Time  : O(n)
Space : O(1)
```

***
