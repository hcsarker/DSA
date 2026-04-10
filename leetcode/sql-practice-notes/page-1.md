# Page 1

## 1731. The Number of Employees Which Report to Each Employee

### Difficulty

Easy

***

## Table: Employees

| Column       | Type    |
| ------------ | ------- |
| employee\_id | int     |
| name         | varchar |
| reports\_to  | int     |
| age          | int     |

👉 `reports_to` = manager\_id

***

## 🎯 Problem

Find for each **manager**:

```
```

```
- manager id
- manager name
- number of employees (reports count)
- average age of reports
```

👉 only include managers (যাদের under এ employee আছে)

👉 sort by `employee_id`

***

## 🧠 Key Idea

👉 same table self join করতে হবে

👉 কারণ:

```
```

```
employee → reports_to → manager
```

***

## ✅ SQL Solution (PostgreSQL)

```
```

```
SELECT 
    m.employee_id,
    m.name,
    COUNT(e.employee_id) AS reports_count,
    ROUND(AVG(e.age)) AS average_age
FROM Employees e
JOIN Employees m
ON e.reports_to = m.employee_id
GROUP BY m.employee_id, m.name
ORDER BY m.employee_id;
```

***

## 🔎 Explanation

### Step 1 — Self Join

```
```

```
Employees e JOIN Employees m
```

👉

* `e` = employee
* `m` = manager

***

### Step 2 — Match employee → manager

```
```

```
e.reports_to = m.employee_id
```

***

### Step 3 — Count reports

```
```

```
COUNT(e.employee_id)
```

***

### Step 4 — Average age

```
```

```
AVG(e.age)
```

👉 reports দের age average

***

### Step 5 — Round

```
```

```
ROUND(...)
```

***

### Step 6 — Group

```
```

```
GROUP BY m.employee_id, m.name
```

***

## 📊 Example

| emp | manager | age |
| --- | ------- | --- |
| 2   | 1       | 30  |
| 3   | 1       | 40  |

***

#### Calculation

```
```

```
manager 1 → 2 reports  
average age = (30 + 40) / 2 = 35
```

***

#### Output

| id | name | reports\_count | average\_age |
| -- | ---- | -------------- | ------------ |
| 1  | ...  | 2              | 35           |
