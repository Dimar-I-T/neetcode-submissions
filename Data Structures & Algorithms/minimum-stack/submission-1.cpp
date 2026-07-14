class MinStack {
public:
    int* stack;
    int* auxStack;
    int minn = INT_MAX;
    int i = 1;
    MinStack() {
        stack = (int *)calloc(1, sizeof(int));
        auxStack = (int *)calloc(1, sizeof(int));
    }
    
    void push(int val) {
        stack = (int *)realloc(stack, (i)*sizeof(int));
        auxStack = (int *)realloc(auxStack, (i)*sizeof(int));
        stack[i - 1] = val; 
        if (i == 1){
            auxStack[i - 1] = val;
        }else{
            auxStack[i - 1] = min(auxStack[i - 2], val);
        }
        i++;
    }
    
    void pop() {
        stack = (int *)realloc(stack, (i - 2)*sizeof(int));
        auxStack = (int *)realloc(auxStack, (i - 2)*sizeof(int));
        i--;
    }
    
    int top() {
        return stack[i - 2];
    }
    
    int getMin() {
        return auxStack[i - 2];
    }
};
