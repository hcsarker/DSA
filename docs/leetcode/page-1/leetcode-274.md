---
description: H-Index
---

# 📘 LeetCode 274

## 🔥 Problem

একটা array `citations` দেওয়া আছে।

```
citations[i] = ith paper কত citation পেয়েছে
```

তোমাকে **researcher এর h-index বের করতে হবে**।

***

## 🧠 H-Index Definition

একজন researcher এর **h-index = h** যদি

```
at least h papers have ≥ h citations
```

***

## 🧩 Example

Input

```
citations = [3,0,6,1,5]
```

মানে researcher এর 5টা paper আছে।

| Paper | Citations |
| ----- | --------- |
| 1     | 3         |
| 2     | 0         |
| 3     | 6         |
| 4     | 1         |
| 5     | 5         |

***

## 🪜 Step 1 → Sort

আমরা আগে sort করি।

```
[0,1,3,5,6]
```

***

## 🪜 Step 2 → Check condition

আমরা check করবো

```
citations[i] ≥ papers_left
```

| i | citations\[i] | papers\_left | Condition |
| - | ------------- | ------------ | --------- |
| 0 | 0             | 5            | ❌         |
| 1 | 1             | 4            | ❌         |
| 2 | 3             | 3            | ✅         |

এখানে

```
h = 3
```

***

## 🎯 Final Answer

```
3
```

***

## 💻 Python Code

```
class Solution(object):
    def hIndex(self, citations):
        citations.sort()
        n = len(citations)

        for i in range(n):
            if citations[i] >= n - i:
                return n - i

        return 0
```

***

## 🔎 Line by Line Explanation

***

### sort citations

```
citations.sort()
```

Example

```
Before
[3,0,6,1,5]

After
[0,1,3,5,6]
```

***

### number of papers

```
n = len(citations)
```

Example

```
n = 5
```

***

### loop through array

```
for i in range(n):
```

Array traverse।

***

### check condition

```
if citations[i] >= n-i:
```

Example

```
i = 2
citations[2] = 3
n-i = 3
```

Condition

```
3 ≥ 3
```

True

***

### return answer

```
return n-i
```

```
5 - 2 = 3
```

***

## 🪜 Dry Run

```
citations = [3,0,6,1,5]
```

Sorted

```
[0,1,3,5,6]
```

Check

```
i=0 → 0 ≥ 5 ❌
i=1 → 1 ≥ 4 ❌
i=2 → 3 ≥ 3 ✅
```

Answer

```
3
```

***

## ⏱ Complexity

Time : O(n log n)\
Space : O(1)
