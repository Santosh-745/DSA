### A Queue using two stacks 
1. making push operation costly
  - enQueue(q, x): 
    - While stack1 is not empty, push everything from stack1 to stack2.
    - Push x to stack1 (assuming size of stacks is unlimited).
    - Push everything back to stack1.
    - Here time complexity will be O(n)
  - deQueue(q): 
    - If stack1 is empty then error
    - Pop an item from stack1 and return it
    - Here time complexity will be O(1)
2. Making pop costly
- enQueue(q,  x)
  - Push x to stack1 (assuming size of stacks is unlimited).
  - Here time complexity will be O(1)
- deQueue(q)
  - If both stacks are empty then error.
  - If stack2 is empty
    - While stack1 is not empty, push everything from stack1 to stack2.
  - Pop the element from stack2 and return it.
  - Here time complexity will be O(n)
### Queue using one stack
- push using insertAtBottom
- pop normally
