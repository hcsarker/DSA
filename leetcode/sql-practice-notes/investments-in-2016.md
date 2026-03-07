---
description: 🏷 Difficulty Medium
---

# 📘 Investments in 2016

### 🧠 Interview Pattern

**Group Filtering + Duplicate Detection + Unique Location**

***

## 📝 Table: Insurance

| Column    | Type  |
| --------- | ----- |
| pid       | int   |
| tiv\_2015 | float |
| tiv\_2016 | float |
| lat       | float |
| lon       | float |

* `pid` → Primary key
* `lat, lon` → City location

***

## 🎯 Objective

Find:

```
SUM(tiv_2016)
```

For policyholders who satisfy **two conditions**

***

### ✅ Condition 1

Policyholders must share the **same tiv\_2015 with at least one other person**

Example

| pid | tiv\_2015 |
| --- | --------- |
| 1   | 10        |
| 2   | 10        |

These qualify.

***

### ❌ Condition 2

Location must be **unique**

Meaning:

```
(lat, lon)
```

should appear **only once**

Example

| pid | lat | lon |
| --- | --- | --- |
| 1   | 10  | 20  |
| 2   | 10  | 20  |

❌ Not allowed.

***

## 🧠 Strategy

We need **two subqueries**

#### 1️⃣ Find duplicated tiv\_2015

```
GROUP BY tiv_2015
HAVING COUNT(*) > 1
```

***

#### 2️⃣ Find unique locations

```
GROUP BY lat, lon
HAVING COUNT(*) = 1
```

***

## ✅ PostgreSQL Solution

```
SELECT 
    ROUND(SUM(tiv_2016)::numeric,2) AS tiv_2016
FROM Insurance
WHERE tiv_2015 IN (
    SELECT tiv_2015
    FROM Insurance
    GROUP BY tiv_2015
    HAVING COUNT(*) > 1
)
AND (lat, lon) IN (
    SELECT lat, lon
    FROM Insurance
    GROUP BY lat, lon
    HAVING COUNT(*) = 1
);
```

***

## 🔎 Explanation

#### Step 1

Find duplicated investment values

```
SELECT tiv_2015
FROM Insurance
GROUP BY tiv_2015
HAVING COUNT(*) > 1
```

***

#### Step 2

Find unique city locations

```
SELECT lat, lon
FROM Insurance
GROUP BY lat, lon
HAVING COUNT(*) = 1
```

***

#### Step 3

Filter rows satisfying both conditions

```
WHERE tiv_2015 IN (...)
AND (lat,lon) IN (...)
```

***

#### Step 4

Sum tiv\_2016

```
SUM(tiv_2016)
```

***

#### Step 5

Round result

PostgreSQL requires casting:

```
ROUND(SUM(tiv_2016)::numeric,2)
```

***

## 📊 Visual Example

Insurance Table

| pid | tiv\_2015 | tiv\_2016 | lat | lon |
| --- | --------- | --------- | --- | --- |
| 1   | 10        | 5         | 1   | 1   |
| 2   | 10        | 6         | 2   | 2   |
| 3   | 20        | 7         | 3   | 3   |
| 4   | 20        | 8         | 3   | 3   |

Condition check

| pid | result |
| --- | ------ |
| 1   | ✅      |
| 2   | ✅      |
| 3   | ❌      |
| 4   | ❌      |

Sum

5 + 6 = 11
