# 📘 LeetCode 135 Candy

## 🔥 Problem

একটা array `ratings` দেওয়া আছে।

Rules:

```
1️⃣ প্রত্যেক child কমপক্ষে 1 candy পাবে
2️⃣ যার rating বেশি → সে তার পাশের থেকে বেশি candy পাবে
```

👉 তোমাকে **minimum total candies** বের করতে হবে।

***

## 🧠 Key Idea (🔥 Most Important)

👉 একবারে solve করা কঠিন → তাই **2 pass greedy**

```
1️⃣ Left → Right
2️⃣ Right → Left
```

***

## 💡 Intuition

👉 Left pass:

```
যদি ratings[i] > ratings[i-1]
→ candies[i] = candies[i-1] + 1
```

👉 Right pass:

```
যদি ratings[i] > ratings[i+1]
→ candies[i] = max(candies[i], candies[i+1] + 1)
```

***

## 💻 Python Code

```
class Solution(object):
    def candy(self, ratings):
        n = len(ratings)
        candies = [1] * n

        # left → right
        for i in range(1, n):
            if ratings[i] > ratings[i-1]:
                candies[i] = candies[i-1] + 1

        # right → left
        for i in range(n-2, -1, -1):
            if ratings[i] > ratings[i+1]:
                candies[i] = max(candies[i], candies[i+1] + 1)

        return sum(candies)
```

***

## 🔎 Step by Step Explanation

***

## 1️⃣ Initialize

```
candies = [1] * n
```

সবাইকে কমপক্ষে 1 candy।

***

## 2️⃣ Left → Right pass

```
for i in range(1, n):
```

Check:

```
if ratings[i] > ratings[i-1]:
```

👉 increasing slope

***

## 3️⃣ Right → Left pass

```
for i in range(n-2, -1, -1):
```

Check:

```
if ratings[i] > ratings[i+1]:
```

👉 decreasing slope

***

## 🪜 Dry Run 1

```
ratings = [1,0,2]
```

***

#### Initial

```
[1,1,1]
```

***

#### Left pass

```
[1,1,2]
```

***

#### Right pass

```
[2,1,2]
```

***

#### Total

```
2 + 1 + 2 = 5
```

***

## 🪜 Dry Run 2

```
ratings = [1,2,2]
```

***

#### Initial

```
[1,1,1]
```

***

#### Left pass

```
[1,2,1]
```

***

#### Right pass

```
[1,2,1]
```

***

#### Total

```
4
```

***

## ⏱ Complexity

Time : O(n)\
Space : O(n)
