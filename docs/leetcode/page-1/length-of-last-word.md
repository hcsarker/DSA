---
description: LeetCode 58
---

# 📘 Length of Last Word

***

### 🔥 Problem

একটা string `s` দেওয়া আছে যেখানে **words এবং spaces** আছে।

তোমাকে **last word এর length** বের করতে হবে।

👉 Word মানে

```
continuous non-space characters
```

***

### 🧩 Example

#### Example 1

Input

```
s = "Hello World"
```

Words

```
Hello
World
```

Last word

```
World
```

Length

```
5
```

Output

```
5
```

***

#### Example 2

Input

```
s = "   fly me   to   the moon  "
```

Last word

```
moon
```

Length

```
4
```

***

## 🧠 Simple Idea

আমরা **string এর শেষ থেকে iterate করবো**।

#### Steps

1️⃣ শেষের space skip করবো\
2️⃣ last word count করবো

***

## 💻 Simple Python Code

```
class Solution(object):
    def lengthOfLastWord(self, s):
        i = len(s) - 1
        length = 0

        # skip spaces at end
        while i >= 0 and s[i] == ' ':
            i -= 1

        # count last word
        while i >= 0 and s[i] != ' ':
            length += 1
            i -= 1

        return length
```

***

## 🔎 Line by Line Explanation

#### index last এ নেওয়া

```
i = len(s) - 1
```

Example

```
s = "Hello World"
```

```
i = 10
```

***

#### length variable

```
length = 0
```

Last word এর length count করার জন্য।

***

#### ending space skip করা

```
while i >= 0 and s[i] == ' ':
    i -= 1
```

Example

```
"Hello World   "
```

Spaces remove হয়ে pointer যাবে

```
d
```

***

#### last word count

```
while i >= 0 and s[i] != ' ':
```

Word শেষ না হওয়া পর্যন্ত loop।

***

#### length increase

```
length += 1
```

Character count করা হচ্ছে।

***

#### left এ move করা

```
i -= 1
```

Next character check।

***

#### return answer

```
return length
```

***

## 🧩 Example Dry Run

```
s = "Hello World"
```

Start

```
d → count = 1
l → count = 2
r → count = 3
o → count = 4
W → count = 5
```

Stop at space.

Output

```
5
```

***

## ⏱ Complexity

Time : O(n)\
Space : O(1)
