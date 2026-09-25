# 📘 LeetCode 134 Gas Station

## 🔥 Problem

দুইটা array দেওয়া আছে:

```
gas[i]  → ith station এ কত gas আছে
cost[i] → i → i+1 যেতে কত gas লাগবে
```

তোমাকে এমন একটা **starting index** বের করতে হবে যেখান থেকে পুরো circle ঘুরে আসা সম্ভব।

না পারলে:

```
return -1
```

***

## 🧠 Key Idea (🔥 Most Important)

#### Step 1: Total check

```
if total gas < total cost → impossible
```

***

#### Step 2: Greedy

```
tank track করো
```

যখন

```
tank < 0
```

👉 ওই starting point invalid\
👉 next index থেকে start করতে হবে

***

## 💡 Intuition

```
If you can't reach i+1 from start
→ any index between start and i also invalid
```

***

## 💻 Python Code

```
class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        if sum(gas) < sum(cost):
            return -1

        total = 0
        start = 0

        for i in range(len(gas)):
            total += gas[i] - cost[i]

            if total < 0:
                start = i + 1
                total = 0

        return start
```

***

## 🔎 Line by Line Explanation

***

### total gas check

```
if sum(gas) < sum(cost):
    return -1
```

Example

```
gas = [2,3]
cost = [3,4]
```

```
total gas = 5
total cost = 7
```

❌ impossible

***

### variables

```
total = 0
start = 0
```

***

### loop

```
for i in range(len(gas)):
```

***

### tank update

```
total += gas[i] - cost[i]
```

মানে

```
current gas balance
```

***

### reset condition

```
if total < 0:
```

👉 এখানে fail

***

```
start = i + 1
total = 0
```

👉 নতুন starting point

***

## 🪜 Dry Run

```
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]
```

***

#### i = 0

```
total = 1-3 = -2 ❌
start = 1
```

***

#### i = 1

```
total = 2-4 = -2 ❌
start = 2
```

***

#### i = 2

```
total = 3-5 = -2 ❌
start = 3
```

***

#### i = 3

```
total = 4-1 = 3
```

***

#### i = 4

```
total = 3 + (5-2) = 6
```

***

## 🎯 Answer

```
start = 3
```

***

## ⏱ Complexity

Time : O(n)\
Space : O(1)📘 LeetCode 134
