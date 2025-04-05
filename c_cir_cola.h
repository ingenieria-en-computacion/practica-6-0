#define IMPLEMENT_CIRCULAR_QUEUE(TYPE) \
    CircularQueue_##TYPE* cq_##TYPE##_create(void) { \
        CircularQueue_##TYPE* q = malloc(sizeof(CircularQueue_##TYPE)); \
        if (!q) return NULL; \
        q->head = q->tail = NULL; \
        q->length = 0; \
        return q; \
    } \
    \
    void cq_##TYPE##destroy(CircularQueue##TYPE* q) { \
        if (!q) return; \
        while (!cq_##TYPE##_is_empty(q)) { \
            cq_##TYPE##_dequeue(q); \
        } \
        free(q); \
    } \
    \
    bool cq_##TYPE##enqueue(CircularQueue##TYPE* q, TYPE data) { \
        if (!q) return false; \
        Node_##TYPE* new_node = malloc(sizeof(Node_##TYPE)); \
        if (!new_node) return false; \
        new_node->data = data; \
        if (cq_##TYPE##_is_empty(q)) { \
            q->head = q->tail = new_node; \
            new_node->next = new_node; /* Circularidad */ \
        } else { \
            new_node->next = q->head; \
            q->tail->next = new_node; \
            q->tail = new_node; \
        } \
        q->length++; \
        return true; \
    } \
    \
    bool cq_##TYPE##dequeue(CircularQueue##TYPE* q) { \
        if (!q || cq_##TYPE##_is_empty(q)) return false; \
        Node_##TYPE* temp = q->head; \
        if (q->head == q->tail) { \
            q->head = q->tail = NULL; \
        } else { \
            q->head = q->head->next; \
            q->tail->next = q->head; \
        } \
        free(temp); \
        q->length--; \
        return true; \
    } \
    \
    bool cq_##TYPE##front(const CircularQueue##TYPE* q, TYPE* out) { \
        if (!q || cq_##TYPE##_is_empty(q) || !out) return false; \
        *out = q->head->data; \
        return true; \
    } \
    \
    size_t cq_##TYPE##length(const CircularQueue##TYPE* q) { \
        return q ? q->length : 0; \
    } \
    \
    bool cq_##TYPE##is_empty(const CircularQueue##TYPE* q) { \
        return q ? q->length == 0 : true; \
    } \
    \
    void cq_##TYPE##print(const CircularQueue##TYPE* q, void (*print_fn)(TYPE)) { \
        if (!q || cq_##TYPE##_is_empty(q) || !print_fn) return; \
        printf("["); \
        Node_##TYPE* current = q->head; \
        for (size_t i = 0; i < q->length; ++i) { \
            print_fn(current->data); \
            if (i < q->length - 1) printf(", "); \
            current = current->next; \
        } \
        printf("]\n"); \
    }
