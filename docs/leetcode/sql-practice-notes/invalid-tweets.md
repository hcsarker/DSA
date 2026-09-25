---
description: (Easy)
---

# 📘 Invalid Tweets

#### **Problem Description**

We have a table `Tweets` with the following structure:

| Column Name | Type    | Description                                                         |
| ----------- | ------- | ------------------------------------------------------------------- |
| tweet\_id   | int     | Primary key, unique ID of each tweet                                |
| content     | varchar | Text of the tweet (contains letters, numbers, `'!'` or spaces only) |

A tweet is considered **invalid** if the number of characters in `content` is **strictly greater than 15**.

**Goal:** Find the IDs of all invalid tweets. The result can be returned in any order.

***

#### **SQL Solution**

```
SELECT tweet_id
FROM Tweets
WHERE LENGTH(content) > 15;
```

***

#### **Explanation**

1. `LENGTH(content)` counts the number of characters in each tweet.
2. `WHERE LENGTH(content) > 15` filters only the tweets that are **too long** (more than 15 characters).
3. `SELECT tweet_id` retrieves the IDs of these invalid tweets.
