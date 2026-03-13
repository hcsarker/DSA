---
description: Difficulty Easy
---

# Article Views I

## Table: Views

| Column Name | Type |
| ----------- | ---- |
| article\_id | int  |
| author\_id  | int  |
| viewer\_id  | int  |
| view\_date  | date |

* `author_id` → article এর লেখক
* `viewer_id` → যে user article দেখেছে

***

## Problem

Find the **authors who viewed their own articles**.

Return the **author IDs**.

Column name should be:

```
id
```

Result **ascending order** এ দিতে হবে।

***

## SQL Solution (PostgreSQL)

```
SELECT DISTINCT author_id AS id
FROM Views
WHERE author_id = viewer_id
ORDER BY id;
```

***

## Explanation

### Step 1 — Condition

```
author_id = viewer_id
```

মানে:

**Author নিজেই তার article দেখেছে**

Example

| author\_id | viewer\_id |
| ---------- | ---------- |
| 1          | 3          |
| 2          | 2          |
| 3          | 3          |

Valid rows:

| author\_id | viewer\_id |
| ---------- | ---------- |
| 2          | 2          |
| 3          | 3          |

***

### Step 2 — Remove duplicates

একই author অনেকবার দেখতে পারে, তাই ব্যবহার করি:

```
DISTINCT
```

***

### Step 3 — Rename column

```
author_id AS id
```

***

## Final Output Example

| id |
| -- |
| 2  |
| 3  |
