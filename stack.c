struct stacknode {
    int data;
    stacknode* next;
};

struct stack {
    stacknode* top =NULL ;
};

void push(int x, stack * s) {
    stacknode* temp = (stacknode*)malloc(sizeof(stacknode));
    temp->data = x;
    temp->next = s->top;
    s->top = temp;    
}

void pop(stack *s) {
    if (s->top == NULL) return;
    stacknode* temp = s->top;
    s->top = temp->next;
    free(temp);    
}

int top(stack s) {
    return s.top->data;
}

bool empty(stack s) {
    if (s.top == NULL) return true;
    return false;
}
