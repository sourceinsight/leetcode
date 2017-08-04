"""
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
"""

class Solution(object):
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        return s[::-1]

    def reverseString2(self, s):
        """
        :type s: str
        :rtype: str
        """
        str = list(s)
        left, right = 0, len(str) - 1
        while left < right:
            str[left], str[right] = str[right], str[left]
            left += 1
            right -= 1
        return "".join(str)