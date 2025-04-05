#define IMPLEMENT_ARRAY_DEQUE(TYPE) \
    ArrayDeque_##TYPE* deque_##TYPE##_create(size_t capacity) { \
        ArrayDeque_##TYPE* deque = malloc(sizeof(ArrayDeque_##TYPE)); \
        if (!deque) return NULL; \
        deque->data = malloc(sizeof(TYPE) * capacity); \
        if (!deque->data) { free(deque); return NULL; } \
        deque->capacity = capacity; \
        deque->front = 0; \
        deque->rear = capacity - 1; \
        deque->size = 0; \
        return deque; \
    } \
    \
    void deque_##TYPE##destroy(ArrayDeque##TYPE* deque) { \
        if (!deque) return; \
        free(deque->data); \
        free(deque); \
    } \
    \
    bool deque_##TYPE##is_empty(const ArrayDeque##TYPE* deque) { \
        return deque && deque->size == 0; \
    } \
    \
    bool deque_##TYPE##is_full(const ArrayDeque##TYPE* deque) { \
        return deque && deque->size == deque->capacity; \
    } \
    \
    bool deque_##TYPE##push_front(ArrayDeque##TYPE* deque, TYPE value) { \
        if (!deque || deque_##TYPE##_is_full(deque)) return false; \
        deque->front = (deque->front == 0) ? deque->capacity - 1 : deque->front - 1; \
        deque->data[deque->front] = value; \
        deque->size++; \
        return true; \
    } \
    \
    bool deque_##TYPE##push_back(ArrayDeque##TYPE* deque, TYPE value) { \
        if (!deque || deque_##TYPE##_is_full(deque)) return false; \
        deque->rear = (deque->rear + 1) % deque->capacity; \
        deque->data[deque->rear] = value; \
        deque->size++; \
        return true; \
    } \
    \
    bool deque_##TYPE##pop_front(ArrayDeque##TYPE* deque) { \
        if (!deque || deque_##TYPE##_is_empty(deque)) return false; \
        deque->front = (deque->front + 1) % deque->capacity; \
        deque->size--; \
        return true; \
    } \
    \
    bool deque_##TYPE##pop_back(ArrayDeque##TYPE* deque) { \
        if (!deque || deque_##TYPE##_is_empty(deque)) return false; \
        deque->rear = (deque->rear == 0) ? deque->capacity - 1 : deque->rear - 1; \
        deque->size--; \
        return true; \
    } \
    \
    bool deque_##TYPE##front(const ArrayDeque##TYPE* deque, TYPE* out) { \
        if (!deque || deque_##TYPE##_is_empty(deque) || !out) return false; \
        *out = deque->data[deque->front]; \
        return true; \
    } \
    \
    bool deque_##TYPE##back(const ArrayDeque##TYPE* deque, TYPE* out) { \
        if (!deque || deque_##TYPE##_is_empty(deque) || !out) return false; \
        *out = deque->data[deque->rear]; \
        return true; \
    } \
    \
    void deque_##TYPE##print(const ArrayDeque##TYPE* deque, void (*print_fn)(TYPE)) { \
        if (!deque || !print_fn || deque_##TYPE##_is_empty(deque)) return; \
        printf("["); \
        for (size_t i = 0; i < deque->size; ++i) { \
            size_t idx = (deque->front + i) % deque->capacity; \
            print_fn(deque->data[idx]); \
            if (i < deque->size - 1) printf(", "); \
        } \
        printf("]\n"); \
    }
