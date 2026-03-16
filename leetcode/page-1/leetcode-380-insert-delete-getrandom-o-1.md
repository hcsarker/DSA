---
description: medium
---

# 📘 LeetCode 380 – Insert Delete GetRandom O(1)

### 💡 Idea

এই problem-এ তিনটা operation করতে হবে **O(1)** time এ:

1️⃣ insert\
2️⃣ remove\
3️⃣ getRandom

এজন্য আমরা ব্যবহার করি:

```
List + Dictionary
```

| Structure  | কাজ                  |
| ---------- | -------------------- |
| List       | Random element নেওয়া |
| Dictionary | O(1) search          |

***

## 💻 Complete Code

```
import random

class RandomizedSet(object):

    def __init__(self):
        self.nums = []
        self.map = {}

    def insert(self, val):
        if val in self.map:
            return False
        
        self.map[val] = len(self.nums)
        self.nums.append(val)
        return True

    def remove(self, val):
        if val not in self.map:
            return False
        
        idx = self.map[val]
        last = self.nums[-1]

        self.nums[idx] = last
        self.map[last] = idx

        self.nums.pop()
        del self.map[val]

        return True

    def getRandom(self):
        return random.choice(self.nums)
```

***

## 🔍 Step by Step Explanation

### 1️⃣ Constructor

```
self.nums = []
self.map = {}
```

Example

```
nums = [ ]
map = { }
```

***

## 2️⃣ Insert

```
if val in self.map:
    return False
```

আগে থেকেই থাকলে insert করা যাবে না।

***

```
self.map[val] = len(self.nums)
```

value এর index store করা।

Example

```
nums = [10,20]

insert 30

map[30] = 2
```

```
self.nums.append(val)
```

array তে value add করা।

Example

```
nums = [10,20,30]
```

***

## 3️⃣ Remove

ধরি

```
nums = [10,20,30]
map = {10:0,20:1,30:2}
```

আমরা remove করবো **20**

***

#### index বের করা

```
idx = self.map[val]
```

```
idx = 1
```

***

#### last element বের করা

```
last = self.nums[-1]
```

```
last = 30
```

***

#### swap

```
self.nums[idx] = last
```

```
[10,30,30]
```

***

#### hashmap update

```
self.map[last] = idx
```

```
map[30] = 1
```

***

#### last remove

```
self.nums.pop()
```

```
[10,30]
```

***

#### hashmap থেকে delete

```
del self.map[val]
```

```
map = {10:0 , 30:1}
```

***

## 4️⃣ getRandom

```
random.choice(self.nums)
```

Example

```
nums = [10,30]
```

Output হতে পারে

```
10
or
30
```

***

## ⏱ Time Complexity

| Operation | Complexity |
| --------- | ---------- |
| insert    | O(1)       |
| remove    | O(1)       |
| getRandom | O(1)       |
