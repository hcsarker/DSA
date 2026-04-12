# 📘 LeetCode 28 Find First Occurrence (strStr)

## 🔥 Problem

দুইটা string:

```
haystack → main string
needle   → substring
```

👉 `needle` প্রথম কোথায় শুরু হয়েছে (index) return করতে হবে\
👉 না থাকলে:

```
return -1
```

***

## 🧠 Key Idea (Simple)

👉 আমরা check করবো:

```
haystack এর প্রতিটা position থেকে substring match হয় কিনা
```

***

## 💻 Python Code (Basic)

```
class Solution(object):
    def strStr(self, haystack, needle):
        n = len(haystack)
        m = len(needle)

        for i in range(n - m + 1):
            if haystack[i:i+m] == needle:
                return i

        return -1
```

***

## 🔎 Explanation

***

### loop

```
for i in range(n - m + 1):
```

👉 যতদূর possible substring match হতে পারে

***

### substring check

```
haystack[i:i+m]
```

👉 length = needle এর মতো

***

### match

```
if equal → return index
```

***

## 🪜 Dry Run

```
haystack = "sadbutsad"
needle   = "sad"
```

***

#### i = 0

```
"sad" == "sad" ✅
```

👉 return:

```
0
```

***

## 🪜 Another Example

```
haystack = "leetcode"
needle = "leeto"
```

***

Check:

```
"leetc" ≠ "leeto"
```

👉 no match → return:

```
-1
```

***

## ⏱ Complexity

Time : O(n \* m)\
Space : O(1)
