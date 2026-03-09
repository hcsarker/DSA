---
description: 🏷 Difficulty Medium
---

# 📘 Department Highest Salary

### 🧠 Interview Pattern

**Group Maximum per Category**

***

## 📝 Tables

### Employee

| Column       | Type    |
| ------------ | ------- |
| id           | int     |
| name         | varchar |
| salary       | int     |
| departmentId | int     |

* `departmentId` → FK → Department.id

***

### Department

| Column | Type    |
| ------ | ------- |
| id     | int     |
| name   | varchar |

***

## 🎯 Objective

Find employees who have the **highest salary in each department**.

Return:

\| Department | Employee | Salary |

***

## 🧠 Key Idea

For each **department**

```
```

```
Find MAX(salary)
```

Then return employees whose salary equals that maximum.

***

## ✅ PostgreSQL Solution (Subquery)

```
```

```
SELECT 
    d.name AS Department,
    e.name AS Employee,
    e.salary AS Salary
FROM Employee e
JOIN Department d
ON e.departmentId = d.id
WHERE e.salary = (
    SELECT MAX(salary)
    FROM Employee
    WHERE departmentId = e.departmentId
);
```

***

## 🔎 Step-by-Step Explanation

#### 1️⃣ Join Department

```
```

```
JOIN Department d
ON e.departmentId = d.id
```

To get department name.

***

#### 2️⃣ Find Maximum Salary Per Department

```
```

```
SELECT MAX(salary)
FROM Employee
WHERE departmentId = e.departmentId
```

Example

| departmentId | max salary |
| ------------ | ---------- |
| IT           | 90000      |
| HR           | 80000      |

***

#### 3️⃣ Filter Employees

```
```

```
e.salary = MAX(salary)
```

Return only highest paid employees.

***

## 📊 Example

#### Employee

| id | name  | salary | departmentId |
| -- | ----- | ------ | ------------ |
| 1  | Joe   | 70000  | 1            |
| 2  | Jim   | 90000  | 1            |
| 3  | Henry | 80000  | 2            |
| 4  | Sam   | 60000  | 2            |
| 5  | Max   | 90000  | 1            |

***

#### Department

| id | name  |
| -- | ----- |
| 1  | IT    |
| 2  | Sales |

***

#### Output

| Department | Employee | Salary |
| ---------- | -------- | ------ |
| IT         | Jim      | 90000  |
| IT         | Max      | 90000  |
| Sales      | Henry    | 80000  |

***

## 🚀 Alternative (Window Function – Best Practice)

PostgreSQL interview-friendly solution 👇

```
```

```
SELECT 
    d.name AS Department,
    e.name AS Employee,
    e.salary AS Salary
FROM (
    SELECT *,
           DENSE_RANK() OVER(
               PARTITION BY departmentId 
               ORDER BY salary DESC
           ) AS rnk
    FROM Employee
) e
JOIN Department d
ON e.departmentId = d.id
WHERE rnk = 1;
```

***

## 🧠 Why Window Function?

```
```

```
PARTITION BY departmentId
```

means ranking **inside each department**

Example ranking

| Employee | Salary | Rank |
| -------- | ------ | ---- |
| Jim      | 90000  | 1    |
| Max      | 90000  | 1    |
| Joe      | 70000  | 2    |

Then we keep:

```
```

WHERE rnk = 1
