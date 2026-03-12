---
description: 🏷 Difficulty Hard
---

# 📘 Human Traffic of Stadium

### 🧠 Interview Pattern

**Consecutive Rows + Window Function**

***

## 📝 Table: Stadium

| Column      | Type |
| ----------- | ---- |
| id          | int  |
| visit\_date | date |
| people      | int  |

Key facts:

* `visit_date` → unique
* `id` increases with date

***

## 🎯 Objective

Return rows where:

1️⃣ `people >= 100`\
2️⃣ **3 or more consecutive id rows**

***

## 📊 Example

#### Input

| id | visit\_date | people |
| -- | ----------- | ------ |
| 1  | 2017-01-01  | 10     |
| 2  | 2017-01-02  | 109    |
| 3  | 2017-01-03  | 150    |
| 4  | 2017-01-04  | 99     |
| 5  | 2017-01-05  | 145    |
| 6  | 2017-01-06  | 145    |
| 7  | 2017-01-07  | 145    |

***

#### Valid consecutive groups

```
2,3 ❌ (only 2 rows)

5,6,7 ✅ (3 rows)
```

***

#### Output

| id | visit\_date | people |
| -- | ----------- | ------ |
| 5  | 2017-01-05  | 145    |
| 6  | 2017-01-06  | 145    |
| 7  | 2017-01-07  | 145    |

***

## 🧠 Key Idea

Steps:

1️⃣ Filter rows where

```
people >= 100
```

2️⃣ Detect **consecutive ids**

3️⃣ Keep groups with **count ≥ 3**

***

## ✅ PostgreSQL Solution (Window Function)

```
SELECT id, visit_date, people
FROM (
    SELECT *,
           id - ROW_NUMBER() OVER (ORDER BY id) AS grp
    FROM Stadium
    WHERE people >= 100
) t
WHERE grp IN (
    SELECT grp
    FROM (
        SELECT id - ROW_NUMBER() OVER (ORDER BY id) AS grp
        FROM Stadium
        WHERE people >= 100
    ) x
    GROUP BY grp
    HAVING COUNT(*) >= 3
)
ORDER BY visit_date;
```

***

## 🔎 Step-by-Step Explanation

### Step 1 — Filter valid traffic

```
WHERE people >= 100
```

Table becomes

| id | people |
| -- | ------ |
| 2  | 109    |
| 3  | 150    |
| 5  | 145    |
| 6  | 145    |
| 7  | 145    |

***

### Step 2 — Create group identifier

```
id - ROW_NUMBER()
```

Example

| id | row\_number | group |
| -- | ----------- | ----- |
| 2  | 1           | 1     |
| 3  | 2           | 1     |
| 5  | 3           | 2     |
| 6  | 4           | 2     |
| 7  | 5           | 2     |

Rows with same group → **consecutive ids**

***

### Step 3 — Count rows in group

```
GROUP BY grp
HAVING COUNT(*) >= 3
```

Group result

| grp | count |
| --- | ----- |
| 1   | 2     |
| 2   | 3     |

Only group **2** qualifies.

***

### Step 4 — Return rows from valid group

| id | visit\_date | people |
| -- | ----------- | ------ |
| 5  | 2017-01-05  | 145    |
| 6  | 2017-01-06  | 145    |
| 7  | 2017-01-07  | 145    |

***

## 📌 Important SQL Trick

```
id - ROW_NUMBER()
```

This trick is used to detect:

```
consecutive sequences
```

Example

```
1 2 3
5 6 7
```

***

## 🧠 Concepts Tested

| Concept         | Why              |
| --------------- | ---------------- |
| Window Function | row numbering    |
| ROW\_NUMBER()   | detect sequence  |
| grouping trick  | consecutive rows |
| HAVING          | filter groups    |
| subquery        | group filtering  |

***

## 🎯 Interview Pattern

If question says

```
consecutive rows
3 days in a row
continuous records
```

Think immediately:

```
ROW_NUMBER trick
id - ROW_NUMBER()
```

***
