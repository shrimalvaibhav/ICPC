struct qnode {
    int data;
    qnode* next;
};

struct queue {
    qnode* front = NULL, *rear = NULL;
};

void push(queue* q, int x) {
    qnode* temp = (qnode*)malloc(sizeof(qnode));
    temp->data = x;
    temp->next = NULL;
    if ((*q).rear == NULL) {
        (*q).front = temp;
        (*q).rear = temp;
        return;
    }
    (*q).rear->next = temp;
    (*q).rear = temp;
}

void pop(queue* q) {
    if ((*q).front == NULL) return;
    qnode* temp = (*q).front;
    (*q).front = temp->next;
    if ((*q).front == NULL) (*q).rear = NULL;
    free(temp);
}

int front(queue q) {
    return q.front->data;
}

bool empty(queue q) {
    if (q.front == NULL) return true;
    return false;
}
