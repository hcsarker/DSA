# 📘 LeetCode 42 Trapping Rain Water

## 🔥 Problem

একটা array `height` দেওয়া আছে।

```
প্রতিটা element = একটা bar এর height
```

👉 বৃষ্টির পর কত পানি জমবে সেটা calculate করতে হবে।

***

## 🧠 Key Idea (🔥 Most Important)

প্রতিটা index এ পানি নির্ভর করে:

```
left_max এবং right_max
```

***

## 💡 Formula

```
water[i] = min(left_max, right_max) - height[i]
```

***

## 🧩 Example

```
height = [0,1,0,2,1,0,1,3,2,1,2,1]
```

👉 total water = **6**

***

## 🚀 Best Approach (Two Pointer 🔥)

***

## 💻 Python Code

```
class Solution(object):
    def trap(self, height):
        left, right = 0, len(height) - 1
        left_max = right_max = 0
        water = 0

        while left < right:
            if height[left] < height[right]:
                if height[left] >= left_max:
                    left_max = height[left]
                else:
                    water += left_max - height[left]
                left += 1
            else:
                if height[right] >= right_max:
                    right_max = height[right]
                else:
                    water += right_max - height[right]
                right -= 1

        return water
```

***

## 🔎 Step by Step Explanation

***

## 1️⃣ Initialize

```
left = 0
right = n-1
```

```
left_max = 0
right_max = 0
water = 0
```

***

## 2️⃣ Loop

```
while left < right:
```

***

## 3️⃣ Decision

```
if height[left] < height[right]:
```

👉 ছোট side আগে process করবো

***

## 4️⃣ Left side logic

```
if height[left] >= left_max:
    left_max = height[left]
```

👉 নতুন max

***

```
else:
    water += left_max - height[left]
```

👉 পানি জমবে

***

## 5️⃣ Right side logic

একই logic reverse দিকে।

***

## 🪜 Dry Run (Short)

```
height = [4,2,0,3,2,5]
```

👉 answer = **9**

***

## 🧠 Intuition (Simple)

```
পানি জমে দুই পাশের wall এর মধ্যে
```

👉 ছোট wall decide করে পানি কত জমবে

***

## ⏱ Complexity

Time : O(n)\
Space : O(1)
