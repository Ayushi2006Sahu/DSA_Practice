# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middle(self, head: Optional[ListNode])->ListNode:
        first = head
        sec = head
        while sec is not None and sec.next is not None:
            first = first.next
            sec = sec.next.next
        return first

    def reverse(self, head: Optional[ListNode])->ListNode:
        prev = None
        temp = head
        while temp is not None:
            neXt = temp.next
            temp.next = prev
            prev = temp
            temp = neXt
        return prev

    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if head is None or head.next is None:return
        mid = self.middle(head)
        sec = self.reverse(mid.next)
        first = head
        mid.next = None

        while sec is not None:
            t1 = first.next
            t2 = sec.next
            first.next=sec
            sec.next = t1
            first = t1
            sec = t2
    
        