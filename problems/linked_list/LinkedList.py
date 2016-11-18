class Node:
    def __init__(self, val):
        self.val = val;
        self.next = None;
        
class LinkedList:
    def __init__(self):
        self.head = None;
        self.length = 0;
    
    def AddElements(self , val):
        node = Node(val);
        self.length += 1;
        if self.head is None:
            self.head = node;
            return;
        temp = self.head;
        while temp.next is not None:
            temp = temp.next;
        temp.next = node;

    def PrintElements(self):
        temp = self.head;
        while temp is not None:
            print temp.val;
            temp = temp.next;

    def FindMiddle(self):
        if self.head is None:
            return None;
        ptr1 = self.head;
        ptr2 = self.head;
        temp = self.head;
        while ptr1 is not None and ptr1.next is not None:
            temp = ptr2
            ptr2 = ptr2.next;
            ptr1 = ptr1.next.next;
        return temp, ptr2;

    def HalfReverseList(self):
        pre_middle, middle = self.FindMiddle();
        head, tail = self.Reverse(middle);
        tail.next = None;
        pre_middle.next = head;
        return pre_middle;

    def Reverse(self, node):
        if node is None:
            return None , None;
        if node.next is None:
            head = node;
            return head, node;
        head, tail = self.Reverse(node.next);
        tail.next = node;
        return head, node;

    def FirstLastPattern(self):
        if self.head is None:
            return;
        if self.head.next is None:
            print self.head.val;
            return;
        first_current_node = self.head;
        pre_middle_head = self.HalfReverseList();
        middle_head = pre_middle_head.next;
        pre_middle_head.next = None;
        #self.PrintElements();
        second_current_node = middle_head;
        while first_current_node is not None:
            first_next_node = first_current_node.next;
            second_next_node = second_current_node.next;
            first_current_node.next = second_current_node;
            if first_next_node is not None:
                second_current_node.next = first_next_node;
            #print first_current_node.next.val , ' ' , first_current_node.next.next.val 
            first_current_node = first_next_node;
            second_current_node = second_next_node;
        self.PrintElements();



