---
description: 🏷 Difficulty Medium
---

# 📘 Consecutive Numbers

### 🧠 Interview Pattern

Consecutive Records / Self Join

***

## 📝 Problem

#### Table: Logs

| Column Name | Type    |
| ----------- | ------- |
| id          | int     |
| num         | varchar |

* `id` is primary key
* `id` is auto increment starting from **1**

***

### 🎯 Objective

Find numbers that appear **at least 3 times consecutively**.

***

### 📊 Example

#### Input

| id | num |
| -- | --- |
| 1  | 1   |
| 2  | 1   |
| 3  | 1   |
| 4  | 2   |
| 5  | 1   |
| 6  | 2   |
| 7  | 2   |

#### Output

| ConsecutiveNums |
| --------------- |
| 1               |

👉 Because **1 appears 3 times consecutively**

***

## ✅ PostgreSQL Solution (Self Join)

```
SELECT DISTINCT l1.num AS ConsecutiveNums
FROM Logs l1
JOIN Logs l2 ON l1.id = l2.id - 1
JOIN Logs l3 ON l1.id = l3.id - 2
WHERE l1.num = l2.num
AND l2.num = l3.num;
```

***

## 🔎 Explanation

আমরা **3টা row compare করছি**

```
l1 → current row
l2 → next row
l3 → next next row
```

#### Step 1

```
l1.id = l2.id - 1
```

Example

```
1 → 2
```

***

#### Step 2

```
l1.id = l3.id - 2
```

Example

```
1 → 3
```

***

#### Step 3

Check numbers are same

```
l1.num = l2.num
l2.num = l3.num
```

So we get

```
1 1 1
```

***

## 📌 Why DISTINCT?

Because result duplicate হতে পারে

Example

```
1 1 1 1
```

Then query finds

```
1 1 1
1 1 1
```

So we use

DISTINCTv
