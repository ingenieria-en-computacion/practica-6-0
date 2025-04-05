#define DECLARE_CIRCULAR_QUEUE(TYPE) \
    typedef struct Node_##TYPE { \
        TYPE data; \
        struct Node_##TYPE* next; \
    } Node_##TYPE; \
    \
    typedef struct { \
        Node_##TYPE* head; \
        Node_##TYPE* tail; \
        size_t length; \
    } CircularQueue_##TYPE; \
    \
    CircularQueue_##TYPE* cq_##TYPE##_create(void); \
    void cq_##TYPE##destroy(CircularQueue##TYPE* queue); \
    bool cq_##TYPE##enqueue(CircularQueue##TYPE* queue, TYPE data); \
    bool cq_##TYPE##dequeue(CircularQueue##TYPE* queue); \
    bool cq_##TYPE##front(const CircularQueue##TYPE* queue, TYPE* out); \
    size_t cq_##TYPE##length(const CircularQueue##TYPE* queue); \
    bool cq_##TYPE##is_empty(const CircularQueue##TYPE* queue); \
    void cq_##TYPE##print(const CircularQueue##TYPE* queue, void (*print_fn)(TYPE));
