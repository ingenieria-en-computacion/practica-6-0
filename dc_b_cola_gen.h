#define DECLARE_DEQUE(TYPE) \
    typedef struct Node_##TYPE##_deque { \
        TYPE data; \
        struct Node_##TYPE##_deque* next; \
        struct Node_##TYPE##_deque* prev; \
    } Node_##TYPE##_deque; \
    \
    typedef struct { \
        Node_##TYPE##_deque* front; \
        Node_##TYPE##_deque* back; \
        size_t length; \
    } Deque_##TYPE; \
    \
    Deque_##TYPE* deque_##TYPE##_create(void); \
    void deque_##TYPE##destroy(Deque##TYPE* deque); \
    bool deque_##TYPE##push_front(Deque##TYPE* deque, TYPE data); \
    bool deque_##TYPE##push_back(Deque##TYPE* deque, TYPE data); \
    bool deque_##TYPE##pop_front(Deque##TYPE* deque); \
    bool deque_##TYPE##pop_back(Deque##TYPE* deque); \
    bool deque_##TYPE##front(const Deque##TYPE* deque, TYPE* out); \
    bool deque_##TYPE##back(const Deque##TYPE* deque, TYPE* out); \
    size_t deque_##TYPE##length(const Deque##TYPE* deque); \
    bool deque_##TYPE##is_empty(const Deque##TYPE* deque); \
    void deque_##TYPE##print(const Deque##TYPE* deque, void (*print_fn)(TYPE));
