---
description: Jump Game
---

# 📘 LeetCode 55

## 🔥 Problem

একটা array `nums` দেওয়া আছে।

```
nums[i] = maximum jump length from index i
```

তুমি **index 0 থেকে শুরু করবে**।

Check করতে হবে তুমি **last index এ পৌঁছাতে পারবে কিনা**।

Return

```
True  → reach possible
False → reach impossible
```

***

## 🧩 Example

Input

```
nums = [2,3,1,1,4]
```

Index jump meaning

```
index 0 → jump max 2
index 1 → jump max 3
index 2 → jump max 1
index 3 → jump max 1
index 4 → jump max 4
```

Possible path

```
0 → 1 → 4
```

Output

```
True
```

***

## ❌ Impossible Example

```
nums = [3,2,1,0,4]
```

Problem

```
index 3 = 0
```

এখানে stuck হয়ে যাবে।

Output

```
False
```

***

## 🧠 Key Idea (Greedy)

আমরা track করবো

```
maxReach
```

মানে **এখন পর্যন্ত আমরা maximum কোন index পর্যন্ত যেতে পারি**।

***

## 🔍 Algorithm

Loop করবো array এর উপর।

Check করবো

```
i > maxReach
```

মানে

```
আমরা ঐ index এ পৌঁছাতে পারিনি
```

তাহলে return

```
False
```

Otherwise update

```
maxReach = max(maxReach , i + nums[i])
```

***

## 💻 Python Code

```
class Solution(object):
    def canJump(self, nums):
        maxReach = 0

        for i in range(len(nums)):
            if i > maxReach:
                return False

            maxReach = max(maxReach, i + nums[i])

        return True
```

***

## 🔎 Line by Line Explanation

#### maxReach variable

```
maxReach = 0
```

Initially আমরা শুধু

```
index 0
```

এ থাকতে পারি।

***

#### loop

```
for i in range(len(nums)):
```

Array traverse করবো।

***

#### unreachable check

```
if i > maxReach:
```

Example

```
i = 4
maxReach = 3
```

মানে

```
index 4 এ পৌঁছানো সম্ভব না
```

Return

```
False
```

***

#### max reach update

```
maxReach = max(maxReach , i + nums[i])
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
maxReach = 4
```

***

## 🪜 Dry Run

Input

```
[2,3,1,1,4]
```

Start

```
maxReach = 0
```

***

#### i = 0

```
maxReach = max(0, 0+2)
maxReach = 2
```

***

#### i = 1

```
maxReach = max(2, 1+3)
maxReach = 4
```

***

#### i = 2

```
maxReach = max(4, 2+1)
maxReach = 4
```

***

#### i = 3

```
maxReach = max(4, 3+1)
maxReach = 4
```

***

#### i = 4

```
i <= maxReach
```

Last index reached ✅

Return

```
True
```

***

## ⏱ Complexity

```
Time  : O(n)
Space : O(1)
```

***

## 🎯 Pattern

```
Greedy Algorithm
```

***

## ⭐ Interview Trick

Always remember

Jump Game\
\=\
track farthest reachable index
