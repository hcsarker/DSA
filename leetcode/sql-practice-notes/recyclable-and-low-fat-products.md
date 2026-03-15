---
description: Difficulty Easy
---

# 1757. Recyclable and Low Fat Products

### Table: Products

| Column Name | Type          |
| ----------- | ------------- |
| product\_id | int           |
| low\_fats   | enum('Y','N') |
| recyclable  | enum('Y','N') |

* `product_id` → Primary Key
* `low_fats = 'Y'` → Product is **low fat**
* `recyclable = 'Y'` → Product is **recyclable**

***

## Problem

Find the **product IDs** that are:

* **Low fat**
* **Recyclable**

Return the result in **any order**.

***

## SQL Solution

```
SELECT product_id
FROM Products
WHERE low_fats = 'Y'
AND recyclable = 'Y';
```

***

## Explanation

#### Step 1: Select the column

We need only the **product\_id**.

```
SELECT product_id
```

***

#### Step 2: Filter rows

We apply two conditions:

```
low_fats = 'Y'
recyclable = 'Y'
```

Using **AND** means both conditions must be true.

```
WHERE low_fats = 'Y'
AND recyclable = 'Y'
```

***

## Example

#### Input

| product\_id | low\_fats | recyclable |
| ----------- | --------- | ---------- |
| 1           | Y         | N          |
| 2           | Y         | Y          |
| 3           | N         | Y          |
| 4           | Y         | Y          |

***

#### Output

| product\_id |
| ----------- |
| 2           |
| 4           |

Products **2 and 4** are both **low fat and recyclable**.

***
