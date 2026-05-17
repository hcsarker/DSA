# 📘 LeetCode 68 Text Justification

##

***

## 🔥 Problem

👉 তোমাকে words গুলো এমনভাবে সাজাতে হবে যাতে:

```
1️⃣ প্রতিটি line এর length = maxWidth2️⃣ left + right fully justified3️⃣ spaces evenly distribute করতে হবে4️⃣ last line → শুধু left justified
```

***

## 🧠 Core Idea (🔥 Greedy)

```
এক লাইনে যত বেশি word ঢুকানো যায় → ঢুকাও
```

***

## 🪜 Step by Step Approach

***

### 1️⃣ Line build করা

👉 যতক্ষণ:

```
total_letters + spaces + next_word ≤ maxWidth
```

👉 ততক্ষণ word add করো

***

### 2️⃣ Space calculate

ধরি:

```
words = ["This", "is", "an"]
```

```
total letters = 4 + 2 + 2 = 8maxWidth = 16
```

👉 extra space:

```
16 - 8 = 8
```

***

### 3️⃣ Space distribute

```
gap = words-1 = 2
```

```
each gap = 8 // 2 = 4extra = 8 % 2 = 0
```

👉 result:

```
"This____is____an"
```

***

### 4️⃣ Special cases

***

#### ✅ Last line

```
left justified
```

```
word1 word2 word3____
```

***

#### ✅ Single word line

```
word______
```

***

## 💻 Python Code

```
class Solution(object):    def fullJustify(self, words, maxWidth):        res = []        i = 0        n = len(words)        while i < n:            # step 1: find words for current line            line_words = []            line_len = 0            while i < n and line_len + len(words[i]) + len(line_words) <= maxWidth:                line_words.append(words[i])                line_len += len(words[i])                i += 1            # step 2: calculate spaces            spaces = maxWidth - line_len            gaps = len(line_words) - 1            # step 3: last line OR single word            if i == n or gaps == 0:                line = " ".join(line_words)                line += " " * (maxWidth - len(line))            else:                space_each = spaces // gaps                extra = spaces % gaps                line = ""                for j in range(gaps):                    line += line_words[j]                    line += " " * (space_each + (1 if j < extra else 0))                line += line_words[-1]            res.append(line)        return res
```

***

## 🔎 Dry Run (Example)

```
words = ["This","is","an","example","of","text","justification."]maxWidth = 16
```

***

#### Line 1

```
"This", "is", "an"
```

letters = 8\
spaces = 8

👉 output:

```
"This    is    an"
```

***

#### Line 2

```
"example","of","text"
```

letters = 13\
spaces = 3

👉 distribution:

```
```

```
example__of_text
```

***

#### Line 3 (last line)

```
"justification."
```

👉 left justified:

```
"justification.  "
```

***

## ⏱ Complexity

```
Time  : O(n)Space : O(n)
```

***

##
