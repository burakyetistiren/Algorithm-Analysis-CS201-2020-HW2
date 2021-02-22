# Algorithm-Analysis-CS201-2020-HW2
Algorithm Analysis

In this homework, two sorted integer arrays are merged. That is, given two sorted integer arrays arr1 and arr2 of size N, the problem is to create and return a third sorted array arr3 with the items of arr1 and arr2. Third array has size 2N.
Two alternative algorithms that solve this problem are given below in lay terms. Each algorithm has a different time complexity. The goal of this homework is to evaluate the growth rates of both algorithms using different inputs.

Algorithm 1: Append all items in arr1 in the same order to arr3. Then, for all items in arr2 starting from the beginning, find the right place to insert in arr3 by shifting the items in arr3 if needed.
Algorithm 2: Compare pairs of numbers across arr1 and arr2 and insert the smallest to arr3. In this algorithm you are allowed to visit every item only once.
