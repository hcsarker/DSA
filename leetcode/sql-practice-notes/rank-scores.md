---
description: '🏷 Difficulty: Medium'
---

# 📘 Rank Scores

### 🧠 Pattern: Window Function – Dense Ranking

***

### 📝 Problem Statement

#### 🔹 Table: Scores

| Column Name | Type    |
| ----------- | ------- |
| id          | int     |
| score       | decimal |

* `id` is primary key
* `score` has two decimal places

***

### 🎯 Objective

Rank the scores based on:

1️⃣ Highest score → Rank 1\
2️⃣ Same score → Same rank\
3️⃣ No gaps between ranks

⚠ This is called **Dense Ranking**

***

## 🧠 Ranking Types (Very Important for Interview)

| Function       | Gap After Tie?   | Example |
| -------------- | ---------------- | ------- |
| `RANK()`       | ❌ Yes (gap থাকে) | 1,2,2,4 |
| `DENSE_RANK()` | ✅ No gap         | 1,2,2,3 |
| `ROW_NUMBER()` | ❌ No tie allowed | 1,2,3,4 |

👉 এই প্রশ্নে দরকার:

```
DENSE_RANK()
```

***

## ✅ PostgreSQL Solution

```
SELECT 
    score,
    DENSE_RANK() OVER (ORDER BY score DESC) AS rank
FROM Scores
ORDER BY score DESC;
```

***

## 🔎 How It Works

```
DENSE_RANK() OVER (ORDER BY score DESC)
```

* `OVER()` → Window function
* `ORDER BY score DESC` → Highest first
* Same score → Same rank
* No gaps after tie

***

## 📊 Example

#### Input

| id | score |
| -- | ----- |
| 1  | 4.00  |
| 2  | 3.85  |
| 3  | 3.85  |
| 4  | 3.65  |

***

#### Output

| score | rank |
| ----- | ---- |
| 4.00  | 1    |
| 3.85  | 2    |
| 3.85  | 2    |
| 3.65  | 3    |

***

## 🔥 Why NOT RANK()?

If we used:

```
RANK() OVER (ORDER BY score DESC)
```

Result would be:

```
1
2
2
4   ❌ (gap)
```

But question says:

> “There should be no holes between ranks.”

So we use:

DENSE\_RANK()📘 Rank Scores
