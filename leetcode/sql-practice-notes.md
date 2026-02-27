---
description: – LeetCode Patterns
---

# SQL Practice Notes

## 1️⃣&#x20;



***

## 2️⃣ Combine Two Tables

### 🔹 Pattern: LEFT JOIN

```
SELECT p.firstName, p.lastName, a.city, a.state
FROM Person p
LEFT JOIN Address a
ON p.personId = a.personId;
```

#### 🧠 Concept

* LEFT JOIN → keeps all rows from left table
* Unmatched → NULL

***

## 3️⃣ Employees Earning More Than Managers

### 🔹 Pattern: SELF JOIN

```
SELECT e.name AS Employee
FROM Employee e
JOIN Employee m
ON e.managerId = m.id
WHERE e.salary > m.salary;
```

#### 🧠 Concept

* Same table join
* Compare employee vs manager

***

## 4️⃣ Movies with Odd ID

### 🔹 Pattern: Filtering + ORDER BY

```
SELECT *
FROM Cinema
WHERE id % 2 = 1
AND description <> 'boring'
ORDER BY rating DESC;
```

Oracle:

```
WHERE MOD(id, 2) = 1
```

***

## 5️⃣ Customers Not Referred by ID = 2

### 🔹 Pattern: NULL Handling

```
SELECT name
FROM Customer
WHERE referee_id <> 2
OR referee_id IS NULL;
```

#### 🧠 Important

* `IS NULL`
* `<>` = not equal

***

## 6️⃣&#x20;

```
```

***

## 7️⃣ Customer with Most Orders

### 🔹 Pattern: GROUP BY + ORDER BY + LIMIT

```
SELECT customer_number
FROM Orders
GROUP BY customer_number
ORDER BY COUNT(*) DESC
LIMIT 1;
```

Oracle:

```
FETCH FIRST 1 ROWS ONLY;
```

***

## 8️⃣ Classes with ≥ 5 Students

### 🔹 Pattern: GROUP BY + HAVING

```
SELECT class
FROM Courses
GROUP BY class
HAVING COUNT(*) >= 5;
```

#### 🧠 Rule

* WHERE → row filter
* HAVING → group filter

***

## 9️⃣ Monthly Transactions Report

### 🔹 Pattern: Conditional Aggregation

```
SELECT 
    DATE_FORMAT(trans_date, '%Y-%m') AS month,
    country,
    COUNT(*) AS trans_count,
    SUM(amount) AS total_amount,
    SUM(CASE WHEN state = 'approved' THEN 1 ELSE 0 END) AS approved_count,
    SUM(CASE WHEN state = 'approved' THEN amount ELSE 0 END) AS approved_amount
FROM Transactions
GROUP BY month, country;
```

#### 🧠 Golden Pattern

```
SUM(CASE WHEN condition THEN value ELSE 0 END)
```

***

## 🔟 Daily Active Users (DAU)

### 🔹 Pattern: Date Filter + DISTINCT COUNT

```
SELECT 
    activity_date AS day,
    COUNT(DISTINCT user_id) AS active_users
FROM Activity
WHERE activity_date BETWEEN '2019-06-28' AND '2019-07-27'
GROUP BY activity_date;
```

#### 🧠 Important

* Duplicate avoid → DISTINCT
* Analytics pattern

***

## 📌 Master SQL Patterns List

| Pattern               | Use Case                  |
| --------------------- | ------------------------- |
| LEFT JOIN             | Keep all left rows        |
| SELF JOIN             | Compare within same table |
| GROUP BY              | Aggregation               |
| HAVING                | Filter aggregated data    |
| COUNT(DISTINCT)       | Unique count              |
| ORDER BY DESC LIMIT 1 | Top value                 |
| CASE WHEN             | Conditional aggregation   |
