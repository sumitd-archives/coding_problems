class Node:
    def __init__(self, val, array_num):
        self.array_num = array_num;
        self.val = val;

    def GetArrayNum(self):
        return self.array_num;

    def GetValue(self):
        return self.val;
