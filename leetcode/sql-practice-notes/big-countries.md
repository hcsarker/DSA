---
description: Difficulty Easy
---

# Big Countries

## Table: World

| Column Name | Type    |
| ----------- | ------- |
| name        | varchar |
| continent   | varchar |
| area        | int     |
| population  | int     |
| gdp         | int     |

* `name` → country name
* `area` → country area
* `population` → total population

***

## Problem

Find all **big countries**.

A country is **big** if:

* `area ≥ 3,000,000`\
  **OR**
* `population ≥ 25,000,000`

Return:

* `name`
* `population`
* `area`

***

## SQL Solution (PostgreSQL)

```
SELECT name, population, area
FROM World
WHERE area >= 3000000
OR population >= 25000000;
```

***

## Explanation

#### Step 1: Select columns

We need only three columns:

```
SELECT name, population, area
```

***

#### Step 2: Apply conditions

A country is big if:

```
area >= 3000000
```

or

```
population >= 25000000
```

So we use:

```
WHERE area >= 3000000
OR population >= 25000000
```

***

## Example

#### Input

| name        | area    | population |
| ----------- | ------- | ---------- |
| Afghanistan | 652230  | 25500100   |
| Albania     | 28748   | 2831741    |
| Algeria     | 2381741 | 37100000   |

***

#### Output

| name        | population | area    |
| ----------- | ---------- | ------- |
| Afghanistan | 25500100   | 652230  |
| Algeria     | 37100000   | 2381741 |
