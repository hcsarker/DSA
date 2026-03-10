---
description: 🏷 Difficulty Medium
---

# 📘 Product Sales Analysis III

### 🧠 Interview Pattern

**First Record per Group**

***

## 📝 Table: Sales

| Column      | Type |
| ----------- | ---- |
| sale\_id    | int  |
| product\_id | int  |
| year        | int  |
| quantity    | int  |
| price       | int  |

Primary Key:

```
(sale_id, year)
```

Meaning same sale\_id cannot repeat in same year.

***

## 🎯 Objective

For each **product**

1️⃣ Find the **first year it was sold**

```
MIN(year)
```

2️⃣ Return **all sales rows from that year**

***

## 📊 Example

#### Input

| sale\_id | product\_id | year | quantity | price |
| -------- | ----------- | ---- | -------- | ----- |
| 1        | 100         | 2008 | 10       | 500   |
| 2        | 100         | 2009 | 12       | 500   |
| 3        | 200         | 2011 | 15       | 900   |
| 4        | 200         | 2012 | 20       | 950   |

***

#### First Year per Product

| product\_id | first\_year |
| ----------- | ----------- |
| 100         | 2008        |
| 200         | 2011        |

***

#### Output

| product\_id | first\_year | quantity | price |
| ----------- | ----------- | -------- | ----- |
| 100         | 2008        | 10       | 500   |
| 200         | 2011        | 15       | 900   |

***

## ✅ PostgreSQL Solution (Subquery + Join)

```
SELECT 
    s.product_id,
    s.year AS first_year,
    s.quantity,
    s.price
FROM Sales s
JOIN (
    SELECT product_id, MIN(year) AS first_year
    FROM Sales
    GROUP BY product_id
) f
ON s.product_id = f.product_id
AND s.year = f.first_year;
```

***

## 🔎 Step-by-Step Explanation

### Step 1 — Find First Year per Product

```
SELECT product_id, MIN(year)
FROM Sales
GROUP BY product_id
```

Example result

| product\_id | first\_year |
| ----------- | ----------- |
| 100         | 2008        |
| 200         | 2011        |

***

### Step 2 — Join with Original Table

```
ON s.product_id = f.product_id
```

Match product.

***

### Step 3 — Match First Year

```
s.year = f.first_year
```

Return rows from the **first selling year**.
