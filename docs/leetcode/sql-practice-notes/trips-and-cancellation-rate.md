---
description: '🏷 Difficulty: Hard'
---

# 📘 Trips and Cancellation Rate

### 🧠 Pattern: Conditional Aggregation + Multiple Join Filtering

***

### 📝 Problem Statement

#### 🔹 Table: Trips

| Column Name | Type    |
| ----------- | ------- |
| id          | int     |
| client\_id  | int     |
| driver\_id  | int     |
| city\_id    | int     |
| status      | enum    |
| request\_at | varchar |

* `status` ∈ ('completed', 'cancelled\_by\_driver', 'cancelled\_by\_client')
* `client_id`, `driver_id` → reference `Users.users_id`

***

#### 🔹 Table: Users

| Column Name | Type |
| ----------- | ---- |
| users\_id   | int  |
| banned      | enum |
| role        | enum |

* `banned` ∈ ('Yes', 'No')
* `role` ∈ ('client', 'driver', 'partner')

***

## 🎯 Objective

For each day between:

```
2013-10-01 → 2013-10-03
```

Calculate:

```
Cancellation Rate
=
Cancelled Trips (by client or driver)
--------------------------------------
Total Trips
```

⚠ Only include trips where:

* Client is NOT banned
* Driver is NOT banned

Round result to **2 decimal places**

***

## 🧠 Core Logic

#### 1️⃣ Filter Date Range

```
request_at BETWEEN '2013-10-01' AND '2013-10-03'
```

***

#### 2️⃣ Join Users Twice

Because:

* One user is client
* One user is driver

So we need:

```
JOIN Users c ON t.client_id = c.users_id
JOIN Users d ON t.driver_id = d.users_id
```

***

#### 3️⃣ Filter Unbanned Users

```
c.banned = 'No'
AND d.banned = 'No'
```

***

#### 4️⃣ Count Cancelled Trips

Cancelled means:

```
status IN ('cancelled_by_client', 'cancelled_by_driver')
```

***

## ✅ Final SQL Solution

```
SELECT 
    t.request_at AS Day,
    ROUND(
        SUM(CASE 
                WHEN t.status IN ('cancelled_by_client', 'cancelled_by_driver') 
                THEN 1 ELSE 0 
            END) 
        / COUNT(*), 
    2) AS "Cancellation Rate"
FROM Trips t
JOIN Users c 
    ON t.client_id = c.users_id
JOIN Users d 
    ON t.driver_id = d.users_id
WHERE t.request_at BETWEEN '2013-10-01' AND '2013-10-03'
AND c.banned = 'No'
AND d.banned = 'No'
GROUP BY t.request_at;
```

***

## 🔍 Step-by-Step Thinking (Interview Style)

#### ✅ Step 1: Only Valid Trips

Filter by:

* Date range
* Both users unbanned

***

#### ✅ Step 2: Count Total Trips Per Day

```
COUNT(*)
```

***

#### ✅ Step 3: Count Cancelled Trips Per Day

```
SUM(CASE WHEN status IN (...) THEN 1 ELSE 0 END)
```

***

#### ✅ Step 4: Divide and Round

```
ROUND(cancelled / total, 2)
```

***

## 🎯 Interview Pattern Recognition

If question says:

* “Rate”
* “Percentage”
* “Conditional count”
* “Multiple roles”
* “Both sides must satisfy condition”

👉 Think:

```
JOIN table multiple times
+ Conditional SUM
+ GROUP BY date
+ ROUND()
```

***

## 📌 Concepts Used

* Multiple JOIN
* Conditional Aggregation (`CASE WHEN`)
* GROUP BY
* Date Filtering
* ROUND()
* ENUM filtering
