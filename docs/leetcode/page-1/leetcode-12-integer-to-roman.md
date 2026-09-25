# 📘 LeetCode 12 Integer to Roman

## 🔥 Problem

একটা integer `num` দেওয়া আছে।

তোমাকে এটাকে **Roman numeral** এ convert করতে হবে।

***

## 🧠 Roman Symbols

| Value | Symbol |
| ----- | ------ |
| 1000  | M      |
| 900   | CM     |
| 500   | D      |
| 400   | CD     |
| 100   | C      |
| 90    | XC     |
| 50    | L      |
| 40    | XL     |
| 10    | X      |
| 9     | IX     |
| 5     | V      |
| 4     | IV     |
| 1     | I      |

***

## 💡 Key Idea (Greedy 🔥)

👉 বড় value থেকে ছোট value এ check করবো

```
যতবার সম্ভব subtract করবো
```

***

## 💻 Python Code

```
class Solution(object):
    def intToRoman(self, num):
        values = [1000,900,500,400,100,90,50,40,10,9,5,4,1]
        symbols = ["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"]

        res = ""

        for i in range(len(values)):
            while num >= values[i]:
                res += symbols[i]
                num -= values[i]

        return res
```

***

## 🔎 Step by Step Explanation

***

### values + symbols

```
values  = [1000,900,500,...]
symbols = ["M","CM","D",...]
```

👉 mapping তৈরি করা

***

### loop

```
for i in range(len(values)):
```

👉 বড় থেকে ছোট value iterate

***

### greedy subtraction

```
while num >= values[i]:
```

👉 যতবার possible subtract

***

```
res += symbols[i]
num -= values[i]
```

***

## 🪜 Example

```
num = 58
```

***

#### Step 1

```
50 → L
num = 8
```

***

#### Step 2

```
5 → V
num = 3
```

***

#### Step 3

```
1 → I
1 → I
1 → I
```

***

## 🎯 Output

```
LVIII
```

***

## 🪜 Example 2

```
num = 1994
```

***

```
1000 → M
900  → CM
90   → XC
4    → IV
```

***

## 🎯 Output

```
MCMXCIV
```

***

## ⏱ Complexity

```
Time  : O(1)
Space : O(1)
```

***
