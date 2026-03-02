---
description: – LeetCode Patterns
---

# SQL Practice Notes

## 1️⃣  Students and Examinations

### 📝 Question

#### **Table: Students**

| Column Name   | Type    |
| ------------- | ------- |
| student\_id   | int     |
| student\_name | varchar |

* `student_id` is the primary key.

***

#### **Table: Subjects**

| Column Name   | Type    |
| ------------- | ------- |
| subject\_name | varchar |

* `subject_name` is the primary key.

***

#### **Table: Examinations**

| Column Name   | Type    |
| ------------- | ------- |
| student\_id   | int     |
| subject\_name | varchar |

* No primary key.
* May contain duplicates.
* Each student takes **every subject**.
* Each row means a student attended that subject exam once.

***

### 🎯 Task

Find the **number of times each student attended each exam**.

Return result ordered by:

```
student_id ASC,
subject_name ASC
```

***

## ✅ Solution

```
SELECT 
    s.student_id,
    s.student_name,
    sub.subject_name,
    COUNT(e.subject_name) AS attended_exams
FROM Students s
CROSS JOIN Subjects sub
LEFT JOIN Examinations e 
    ON s.student_id = e.student_id
    AND sub.subject_name = e.subject_name
GROUP BY 
    s.student_id, 
    s.student_name, 
    sub.subject_name
ORDER BY 
    s.student_id, 
    sub.subject_name;
```

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

## 6️⃣  Daily Active Users (Last 30 Days)

### 📝 Question

**Table: Activity**

| Column Name    | Type |
| -------------- | ---- |
| user\_id       | int  |
| session\_id    | int  |
| activity\_date | date |
| activity\_type | enum |

* This table **may contain duplicate rows**.
* `activity_type` is ENUM:
  * `'open_session'`
  * `'end_session'`
  * `'scroll_down'`
  * `'send_message'`
* Each session belongs to exactly one user.
* Any activity type counts as valid activity.

#### 🎯 Task

Find the **daily active user count** for a period of **30 days ending 2019-07-27 (inclusive)**.

A user is considered **active** on a day if they made **at least one activity** on that day.

Return the result in any order.

***

### ✅ Solution

```
SELECT 
    activity_date AS day,
    COUNT(DISTINCT user_id) AS active_users
FROM Activity
WHERE activity_date BETWEEN '2019-06-28' AND '2019-07-27'
GROUP BY activity_date;
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

### 11. Customers Who Bought All Products

### 🧠 Pattern: Relational Division

***

### 📝 Problem Statement

#### 🔹 Table: Customer

| Column Name  | Type |
| ------------ | ---- |
| customer\_id | int  |
| product\_key | int  |

* May contain duplicate rows
* `product_key` is a foreign key referencing `Product` table

***

#### 🔹 Table: Product

| Column Name  | Type |
| ------------ | ---- |
| product\_key | int  |

* `product_key` is the primary key
* Contains all available products

***

### 🎯 Objective

Find the `customer_id` who bought **all the products** available in the `Product` table.

Return result in any order.

***

### 🧠 Core Idea

If a customer bought **all products**, then:

```
Number of distinct products bought by customer
=
Total number of products in Product table
```

***

### ✅ SQL Solution

```
SELECT customer_id
FROM Customer
GROUP BY customer_id
HAVING COUNT(DISTINCT product_key) =
(SELECT COUNT(*) FROM Product);
```

## 📘11. Tree Node Classification

### 🏷 Difficulty: Medium

### 🧠 Pattern: Self Relationship / Hierarchical Classification

***

### 📝 Problem Statement

#### 🔹 Table: Tree

| Column Name | Type |
| ----------- | ---- |
| id          | int  |
| p\_id       | int  |

* `id` is unique (Primary Key)
* `p_id` = parent id
* Structure is always a valid tree

***

### 🎯 Objective

Classify each node into one of three types:

| Type  | Condition                        |
| ----- | -------------------------------- |
| Root  | `p_id IS NULL`                   |
| Leaf  | Node has no children             |
| Inner | Node has parent AND has children |

Return result in any order.

***

## 🧠 Core Logic

#### 1️⃣ Root Node

If:

```
p_id IS NULL
```

***

#### 2️⃣ Leaf Node

If:

* Node does NOT appear as any `p_id` in table

***

#### 3️⃣ Inner Node

If:

* Not Root
* AND appears as parent of someone

***

### ✅ SQL Solution

```
SELECT 
    id,
    CASE
        WHEN p_id IS NULL THEN 'Root'
        WHEN id NOT IN (SELECT DISTINCT p_id FROM Tree WHERE p_id IS NOT NULL) THEN 'Leaf'
        ELSE 'Inner'
    END AS type
FROM Tree;
```

***

### 🔍 Step-by-Step Explanation

#### 🔹 Root Check

```
p_id IS NULL
```

Root node has no parent.

***

#### 🔹 Leaf Check

```
id NOT IN (SELECT p_id FROM Tree)
```

If a node never appears as a parent → it has no children → Leaf.

***

#### 🔹 Otherwise → Inner

If it has a parent AND has children → Inner node.

***

### 📊 Example

#### Input

| id | p\_id |
| -- | ----- |
| 1  | NULL  |
| 2  | 1     |
| 3  | 1     |
| 4  | 2     |

#### Output

| id | type  |
| -- | ----- |
| 1  | Root  |
| 2  | Inner |
| 3  | Leaf  |
| 4  | Leaf  |

***

### 🎯 Interview Pattern Recognition

If question involves:

* Parent-child relationship
* Self-referencing table
* Hierarchy classification

👉 Think:

```
Self condition + Subquery check
```

***

### 🔥 Alternative (Using LEFT JOIN)

```
SELECT 
    t.id,
    CASE
        WHEN t.p_id IS NULL THEN 'Root'
        WHEN c.id IS NULL THEN 'Leaf'
        ELSE 'Inner'
    END AS type
FROM Tree t
LEFT JOIN Tree c
    ON t.id = c.p_id;
```

🧠 Here:

* If no child exists → `c.id IS NULL` → Leaf
* If parent NULL → Root

***

