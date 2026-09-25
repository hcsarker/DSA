# 📘 LeetCode 151  Reverse Words in a String

## 🔥 Problem

একটা string `s` দেওয়া আছে।

👉 তোমাকে words গুলোর order reverse করতে হবে।

***

## ❗ Important Conditions

```
1️⃣ extra spaces remove করতে হবে
2️⃣ words এর মাঝে শুধু 1টা space থাকবে
3️⃣ leading/trailing space থাকবে না
```

***

## 🧩 Example

#### Example 1

```
s = "the sky is blue"
```

Output

```
"blue is sky the"
```

***

#### Example 2

```
s = "  hello   world  "
```

Output

```
"world hello"
```

***

## 🧠 Key Idea (🔥 Easy)

👉 Python shortcut:

```
split → reverse → join
```

***

## 💻 Simple Python Code

```
class Solution(object):
    def reverseWords(self, s):
        return " ".join(s.split()[::-1])
```

***

## 🔎 Explanation

***

### 1️⃣ split()

```
s.split()
```

👉 automatically:

```
extra spaces remove করে
```

Example

```
"  hello   world  ".split()
→ ["hello", "world"]
```

***

### 2️⃣ reverse

```
[::-1]
```

👉 reverse list

```
["world", "hello"]
```

***

### 3️⃣ join

```
" ".join(...)
```

👉 1টা space দিয়ে join

```
"world hello"
```

***

## 🪜 Full Dry Run

```
s = "  hello   world  "
```

***

#### Step 1

```
split → ["hello","world"]
```

***

#### Step 2

```
reverse → ["world","hello"]
```

***

#### Step 3

```
join → "world hello"
```

***

## ⏱ Complexity

```
Time  : O(n)
Space : O(n)
```

***

## 🎯 Pattern

```
String Manipulation
```

***

## ⚡ Interview Follow-up (Without built-in)

👉 যদি বলে built-in use করা যাবে না:

```
class Solution(object):
def reverseWords(self, s):
words = []
word = ""

for ch in s:
if ch != " ":
word += ch
else:
if word:
words.append(word)
word = ""

if word:
words.append(word)

words.reverse()
return " ".join(words)
```
