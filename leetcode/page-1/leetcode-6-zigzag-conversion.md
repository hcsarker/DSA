# 📘 LeetCode 6 Zigzag Conversion

## 🔥 Problem

একটা string `s` দেওয়া আছে, এবং `numRows`।

👉 string টাকে zigzag pattern এ লিখে\
👉 তারপর row-wise পড়ে output দিতে হবে।

***

## 🧩 Example

```
s = "PAYPALISHIRING"
numRows = 3
```

Zigzag pattern:

```
P   A   H   N
A P L S I I G
Y   I   R
```

Output:

```
PAHNAPLSIIGYIR
```

***

## 🧠 Key Idea

👉 আমরা actual zigzag draw করবো না\
👉 বরং **row-wise store করবো**

***

## 💡 Intuition

আমরা একটা direction maintain করবো:

```
down → up → down → up
```

***

## 💻 Python Code

```
class Solution(object):
    def convert(self, s, numRows):
        if numRows == 1:
            return s

        rows = [""] * numRows
        curRow = 0
        goingDown = False

        for char in s:
            rows[curRow] += char

            if curRow == 0 or curRow == numRows - 1:
                goingDown = not goingDown

            if goingDown:
                curRow += 1
            else:
                curRow -= 1

        return "".join(rows)
```

***

## 🔎 Step by Step Explanation

***

### 1️⃣ Edge case

```
if numRows == 1:
    return s
```

👉 zigzag possible না

***

### 2️⃣ rows initialize

```
rows = [""] * numRows
```

Example:

```
["", "", ""]
```

***

### 3️⃣ pointer + direction

```
curRow = 0
goingDown = False
```

***

### 4️⃣ loop through string

```
for char in s:
```

***

### 5️⃣ add char to row

```
rows[curRow] += char
```

***

### 6️⃣ direction change

```
if curRow == 0 or curRow == numRows-1:
    goingDown = not goingDown
```

👉 top বা bottom এ গেলে direction change

***

### 7️⃣ move pointer

```
if goingDown:
    curRow += 1
else:
    curRow -= 1
```

***

## 🪜 Dry Run (Important)

```
s = "PAYPALISHIRING"
numRows = 3
```

***

#### Row filling

```
Row 0 → P   A   H   N
Row 1 → A P L S I I G
Row 2 → Y   I   R
```

***

#### Stored as

```
["PAHN", "APLSIIG", "YIR"]
```

***

#### Final

```
"PAHNAPLSIIGYIR"
```

***

## ⏱ Complexity

```
Time  : O(n)
Space : O(n)
```

***
