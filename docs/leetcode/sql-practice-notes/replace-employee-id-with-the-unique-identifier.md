---
description: 1378. leetcode
---

# 📘Replace Employee ID With The Unique Identifier

### Problem Overview

আমাদের কাছে দুইটা টেবিল আছে।

#### Employees Table

| id | name     |
| -- | -------- |
| 1  | Alice    |
| 7  | Bob      |
| 11 | Meir     |
| 90 | Winston  |
| 3  | Jonathan |

* `id` = employee এর id
* `name` = employee এর নাম

***

#### EmployeeUNI Table

| id | unique\_id |
| -- | ---------- |
| 3  | 1          |
| 11 | 2          |
| 90 | 3          |

* `id` = employee id
* `unique_id` = company এর unique identifier

***

### Goal

প্রতিটি employee এর জন্য:

* যদি `unique_id` থাকে → সেটা দেখাতে হবে
* যদি না থাকে → `NULL` দেখাতে হবে

Output এ থাকবে:

| unique\_id | name |
| ---------- | ---- |

***

### Key Idea

আমাদের দুইটা টেবিল **join** করতে হবে।

কিন্তু এখানে গুরুত্বপূর্ণ বিষয়:

আমরা **সব employee দেখাতে চাই**, এমনকি যাদের `unique_id` নাই।

তাই আমাদের ব্যবহার করতে হবে:

**LEFT JOIN**

#### LEFT JOIN কী করে?

* Left table এর সব row রাখে
* Right table এ match না থাকলে `NULL` দেয়

এখানে:

Left Table = `Employees`\
Right Table = `EmployeeUNI`

***

### SQL Solution

```
SELECT 
    EmployeeUNI.unique_id,
    Employees.name
FROM Employees
LEFT JOIN EmployeeUNI
ON Employees.id = EmployeeUNI.id;
```

***

### Query Breakdown

#### 1️⃣ SELECT

```
SELECT EmployeeUNI.unique_id, Employees.name
```

আমরা চাই:

* `unique_id`
* `name`

***

#### 2️⃣ FROM

```
FROM Employees
```

আমরা Employees টেবিল থেকে শুরু করছি।

***

#### 3️⃣ LEFT JOIN

```
LEFT JOIN EmployeeUNI
```

Employees এর সাথে EmployeeUNI join করছি।

***

#### 4️⃣ Join Condition

```
ON Employees.id = EmployeeUNI.id
```

মানে:

যে employee এর id দুই টেবিলে match করবে, সেই row combine হবে।

***

### Example Execution

#### Employees

| id | name  |
| -- | ----- |
| 1  | Alice |
| 7  | Bob   |
| 11 | Meir  |

#### EmployeeUNI

| id | unique\_id |
| -- | ---------- |
| 11 | 2          |

***

#### After LEFT JOIN

| unique\_id | name  |
| ---------- | ----- |
| NULL       | Alice |
| NULL       | Bob   |
| 2          | Meir  |

কারণ:

* Alice → unique\_id নেই → NULL
* Bob → unique\_id নেই → NULL
* Meir → unique\_id = 2

***

### Final Output

| unique\_id | name  |
| ---------- | ----- |
| NULL       | Alice |
| NULL       | Bob   |
| 2          | Meir  |

***
