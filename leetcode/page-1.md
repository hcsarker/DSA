---
description: '-  LeetCode Patterns'
---

# Top Interview 150 Problem

### 1️⃣ Pascal’s Triangle

**Problem:** Generate first `numRows` of Pascal’s Triangle.

**Python Code:**

```
def generate(numRows):
    triangle = []
    for i in range(numRows):
        row = [1]*(i+1)
        for j in range(1,i):
            row[j] = triangle[i-1][j-1] + triangle[i-1][j]
        triangle.append(row)
    return triangle
```

**Complexity:**

* Time: O(numRows²)
* Space: O(numRows²)

**Tip:** Each element = sum of 2 elements directly above.

***

### 2️⃣ Next Permutation

**Problem:** Find next lexicographical permutation.

**Python Code:**

```
def nextPermutation(nums):
    i = len(nums) - 2
    while i >= 0 and nums[i] >= nums[i+1]:
        i -= 1
    if i >= 0:
        j = len(nums)-1
        while nums[j] <= nums[i]:
            j -= 1
        nums[i], nums[j] = nums[j], nums[i]
    nums[i+1:] = reversed(nums[i+1:])
```

**Tip:**

* Find first decreasing element from right.
* Swap with just larger element.
* Reverse suffix.

***

### 3️⃣ Sort Colors (Dutch National Flag)

**Problem:** Sort array of 0,1,2 in-place.

**Python Code:**

```
def sortColors(nums):
    low, mid, high = 0, 0, len(nums)-1
    while mid <= high:
        if nums[mid] == 0:
            nums[low], nums[mid] = nums[mid], nums[low]
            low += 1
            mid += 1
        elif nums[mid] == 1:
            mid += 1
        else:
            nums[mid], nums[high] = nums[high], nums[mid]
            high -= 1
```

**Time:** O(n), **Space:** O(1)

***

### 4️⃣ Best Time to Buy & Sell Stock I

**Problem:** Max profit for single transaction.

```
def maxProfit(prices):
    min_price = float('inf')
    max_profit = 0
    for price in prices:
        min_price = min(min_price, price)
        max_profit = max(max_profit, price - min_price)
    return max_profit
```

* Time: O(n), Space: O(1)

**Tip:** Track min\_price and max\_profit.

***

### 5️⃣ Best Time to Buy & Sell Stock II

**Problem:** Max profit with unlimited transactions.

```
def maxProfit(prices):
    profit = 0
    for i in range(1,len(prices)):
        if prices[i] > prices[i-1]:
            profit += prices[i] - prices[i-1]
    return profit
```

* Time: O(n), Space: O(1)

**Tip:** Sum all positive adjacent differences.

***

### 6️⃣ Stock with Cooldown

**Problem:** Max profit with unlimited transactions + 1 day cooldown.

```
def maxProfit(prices):
    if not prices: return 0
    hold, sold, rest = -prices[0], 0, 0
    for price in prices[1:]:
        prev_hold, prev_sold, prev_rest = hold, sold, rest
        hold = max(prev_hold, prev_rest - price)
        sold = prev_hold + price
        rest = max(prev_rest, prev_sold)
    return max(sold, rest)
```

* Time: O(n), Space: O(1)
* States: hold, sold, rest

***

### 7️⃣ Bulb Toggle Problem

**Problem:** Toggle bulbs and return ON bulbs in ascending order.

```
def finalBulbs(bulbs):
    on_bulbs = set()
    for b in bulbs:
        if b in on_bulbs:
            on_bulbs.remove(b)
        else:
            on_bulbs.add(b)
    return sorted(on_bulbs)
```

* Time: O(n), Space: O(1) (bulbs ≤100)

**Tip:** A bulb ON at the end → appeared odd times.

***

### 8️⃣ Add Two Numbers (Linked List)

**Problem:** Add two numbers represented as reversed linked lists.

```
class Solution:
    def addTwoNumbers(self, l1, l2):
        dummy = ListNode(0)
        current, carry = dummy, 0
        while l1 or l2 or carry:
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0
            total = val1 + val2 + carry
            carry = total // 10
            current.next = ListNode(total % 10)
            current = current.next
            if l1: l1 = l1.next
            if l2: l2 = l2.next
        return dummy.next
```

* Time: O(max(n,m)), Space: O(max(n,m))

**Tip:**

* digit = total % 10
* carry = total // 10

***

### 9️⃣ Two Sum Problem

**Problem:** Return indices of two numbers adding to target.

```
def twoSum(nums, target):
    seen = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in seen:
            return [seen[complement], i]
        seen[num] = i
```

* Time: O(n), Space: O(n)

***

### 10. Duplicate Number in Array (Floyd’s Cycle Detection)

**Problem:**\
Given an array of `n + 1` integers where each integer is in range `[1, n]`. There is only **one repeated number**. Find it **without modifying the array** and using **constant extra space**.

**Example:**

```
Input: nums = [1,3,4,2,2]
Output: 2
```

**Solution:**\
Use **Floyd’s Tortoise and Hare (Cycle Detection)** algorithm.

**Python Code:**

```
def findDuplicate(nums):
    # Phase 1: Detect cycle
    slow = nums[0]
    fast = nums[0]
    while True:
        slow = nums[slow]
        fast = nums[nums[fast]]
        if slow == fast:
            break

    # Phase 2: Find entrance of cycle
    slow = nums[0]
    while slow != fast:
        slow = nums[slow]
        fast = nums[fast]

    return slow
```

**Concept:**

* Treat array as a linked list: `index → nums[index]`
* There is always a cycle because `n + 1` numbers map to `[1, n]`
* Cycle start = duplicate number

**Complexity:**

* Time: O(n)
* Space: O(1)

***

### 11. Remove Element from Array (In-Place)

**Problem:**\
Given `nums` and `val`, remove all occurrences of `val` in-place. Return `k`, the number of elements not equal to `val`. The first `k` elements should contain non-val elements.

**Example:**

```
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
```

**Solution (Two Pointer):**

```
def removeElement(nums, val):
    k = 0
    for i in range(len(nums)):
        if nums[i] != val:
            nums[k] = nums[i]
            k += 1
    return k
```

**Alternate (Order Not Important):**

```
def removeElement(nums, val):
    left = 0
    right = len(nums) - 1
    while left <= right:
        if nums[left] == val:
            nums[left] = nums[right]
            right -= 1
        else:
            left += 1
    return left
```

**Complexity:**

* Time: O(n)
* Space: O(1)

***

### 12. Coin Change Problem (Dynamic Programming)

**Problem:**\
Given `coins` of different denominations and `amount`, return the **fewest number of coins** needed to make that amount. Return -1 if impossible.

**Example:**

```
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
```

**Solution (Bottom-Up DP):**

```
def coinChange(coins, amount):
    dp = [float('inf')] * (amount + 1)
    dp[0] = 0
    
    for i in range(1, amount + 1):
        for coin in coins:
            if i - coin >= 0:
                dp[i] = min(dp[i], dp[i - coin] + 1)
    
    return dp[amount] if dp[amount] != float('inf') else -1
```

**Concept:**

* `dp[i]` = minimum coins to make amount `i`
* Formula: `dp[i] = min(dp[i], dp[i - coin] + 1)`

**Complexity:**

* Time: O(amount × number\_of\_coins)
* Space: O(amount)

***

### 13. Best Time to Buy and Sell Stock III

### 🔹 Problem Summary

তোমাকে একটি array `prices` দেওয়া আছে যেখানে:

```
prices[i] = i-th দিনের stock price
```

তুমি সর্বোচ্চ **২টা transaction (buy + sell)** করতে পারবে।

⚠️ শর্ত:

* একসাথে multiple transaction করা যাবে না
* আগে sell করতে হবে, তারপর আবার buy করা যাবে

***

### 🎯 Goal

Maximum profit বের করতে হবে।

***

## 🧠 Optimal Idea (4 State Method)

আমরা ৪টা variable ব্যবহার করবো:

| Variable | Meaning                               |
| -------- | ------------------------------------- |
| `buy1`   | প্রথমবার buy করলে minimum দাম         |
| `sell1`  | প্রথমবার sell করলে max profit         |
| `buy2`   | দ্বিতীয়বার buy করলে effective cost    |
| `sell2`  | দ্বিতীয়বার sell করলে max total profit |

***

### 🔁 Transition Logic

প্রতিটা price এর জন্য:

```
buy1  = min(buy1, price)
sell1 = max(sell1, price - buy1)

buy2  = min(buy2, price - sell1)
sell2 = max(sell2, price - buy2)
```

👉 Final Answer = `sell2`

***

## 💻 LeetCode Code

```
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        
        buy1 = float('inf')
        sell1 = 0
        buy2 = float('inf')
        sell2 = 0
        
        for price in prices:
            buy1 = min(buy1, price)
            sell1 = max(sell1, price - buy1)
            
            buy2 = min(buy2, price - sell1)
            sell2 = max(sell2, price - buy2)
        
        return sell2
```

***

## 🔎 Example

```
Input:  [3,3,5,0,0,3,1,4]
Output: 6
```

Best Strategy:

```
Buy at 0 → Sell at 3 = 3
Buy at 1 → Sell at 4 = 3
Total Profit = 6
```

***

## ⏱ Complexity

* Time Complexity → O(n)
* Space Complexity → O(1)
