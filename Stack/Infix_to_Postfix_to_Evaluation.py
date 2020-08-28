class Solution:
    # def __init__(self):
    #     print("Hello")
    def isOperand(self, arg_char):
        operator_list = ['+','-','/','*','(',')']
        if arg_char in operator_list:
            return False
        else:
            return True
        
    def Prec(self, arg_char):
        if arg_char == '(':
            return 1
        elif arg_char == '+' or arg_char == '-':
            return 2
        else:
            return 3
        
    def calculate(self, s: str) -> str:
        #Part 1: convert infix expression to postfix using a stack
        # initialize a list as a stack
        my_stack = []
        char_index = 0
        postfix = ""
        # while loop thru the string argument
        while char_index in range(0,len(s)):
            curr_char = s[char_index]
            # if current char is operand, then append to postfix and move to next char
            if self.isOperand(curr_char):
                postfix += curr_char
                char_index += 1
            # if current char is '(' then push to stack and move to next char
            elif curr_char == '(':
                my_stack.append(curr_char)
                char_index += 1
            # else if current char is ')' then pop and append top of stack to postfix while top is not '('
                # remove '(' from stack top and move on to next char
            elif curr_char == ')':
                while (my_stack[-1]) != '(':
                    postfix += my_stack.pop(-1)
                my_stack.pop(-1)
                char_index += 1
            # else 
                # if Prec(curr char) <= Prec(top of stack) then pop top off stack and append to postfix
                    # do not move to next char --> multiple pop and append operations possible
                # else just push the operator onto the stack and move to next char
            else:
                if len(my_stack) and self.Prec(curr_char) <= self.Prec(my_stack[-1]):
                    postfix += my_stack.pop(-1)
                else:
                    my_stack.append(curr_char)
                    char_index += 1
        while len(my_stack) != 0:
            postfix += my_stack.pop(-1)

        return postfix
                
        # Part 2: evaluate the postfix expression for solution and return that 


s = Solution()
infix = "(A+B)*(C/D)"
print(f"Infix expression is: {infix}")
print(f"Postfix expression is: {s.calculate(infix)}")
            