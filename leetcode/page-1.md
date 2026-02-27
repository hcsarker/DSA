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
