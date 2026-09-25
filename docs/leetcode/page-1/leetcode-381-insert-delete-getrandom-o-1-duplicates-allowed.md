# 📘 LeetCode 381 Insert Delete GetRandom O(1) (Duplicates Allowed)

## 🔥 Problem Difference (380 vs 381)

| Feature    | 380           | 381                    |
| ---------- | ------------- | ---------------------- |
| Duplicates | ❌ না          | ✅ হ্যাঁ                |
| Map        | value → index | value → set of indices |

***

## 🧠 Core Idea

আগের মতোই:

```
Array + HashMap
```

কিন্তু এখন:

```
map[val] = set of indices
```

***

## 🧩 Example

```
nums = [1,1,2]

map = {
1: {0,1}
2: {2}
}
```

***

## 💻 Complete Code

```
import random
from collections import defaultdict

class RandomizedCollection(object):

    def __init__(self):
        self.nums = []
        self.map = defaultdict(set)

    def insert(self, val):
        self.nums.append(val)
        self.map[val].add(len(self.nums) - 1)

        return len(self.map[val]) == 1

    def remove(self, val):
        if not self.map[val]:
            return False

        remove_idx = self.map[val].pop()
        last = self.nums[-1]

        # swap
        self.nums[remove_idx] = last

        # update last value index
        self.map[last].add(remove_idx)
        self.map[last].discard(len(self.nums) - 1)

        # remove last element
        self.nums.pop()

        return True

    def getRandom(self):
        return random.choice(self.nums)
```

***

## 🧠 Short Explanation (Important Points)

***

### 🔹 Data Structure

```
nums → array (values store)
map  → value → set of indices
```

Example:

```
nums = [1,1,2]

map = {
1: {0,1}
2: {2}
}
```

***

### 🔹 Insert

```
append value
index store in set
```

```
return True if first time
```

***

### 🔹 Remove (🔥 Main Trick)

```
1. index বের করো
2. last element নিয়ে swap করো
3. map update করো
4. last pop করো
```

***

### 🔹 getRandom

```
random.choice(nums)
```

***

## 🎯 Ultimate Trick

```
Duplicate handle করতে → set of indices লাগবে
```

***

## ⚡ One Line Difference

```
380 → map[val] = index
381 → map[val] = set of indices
```

***

## ⏱ Complexity

insert → O(1)\
remove → O(1)\
getRandom→ O(1)
