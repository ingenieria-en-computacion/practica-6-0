#define IMPLEMENT_CIRCULAR_DEQUE(TYPE) \
    CircularDeque_##TYPE* deque_##TYPE##_create(size_t capacity) { \
        CircularDeque_##TYPE* deque = malloc(sizeof(CircularDeque_##TYPE)); \
        if (!deque) return NULL; \
        deque->buffer = malloc(sizeof(TYPE) * capacity); \
        if (!deque->buffer) { free(deque); return NULL; } \
        deque->capacity = capacity; \
        deque->front = 0; \
        deque->rear = capacity - 1; \
        deque->size = 0; \
        return deque; \
    } \
    \
    void deque_##TYPE##destroy(CircularDeque##TYPE* deque) { \
        if (!deque) return; \
        free(deque->buffer); \
        free(deque); \
    } \
    \
    bool deque_##TYPE##is_empty(const CircularDeque##TYPE* deque) { \
        return deque && deque->size == 0; \
    } \
    \
    bool deque_##TYPE##is_full(const CircularDeque##TYPE* deque) { \
        return deque && deque->size == deque->capacity; \
    } \
    \
    bool deque_##TYPE##push_front(CircularDeque##TYPE* deque, TYPE value) { \
        if (!deque || deque_##TYPE##_is_full(deque)) return false; \
        deque->front = (deque->front == 0) ? deque->capacity - 1 : deque->front - 1; \
        deque->buffer[deque->front] = value; \
        deque->size++; \
        return true; \
    } \
    \
    bool deque_##TYPE##push_back(CircularDeque##TYPE* deque, TYPE value) { \
        if (!deque || deque_##TYPE##_is_full(deque)) return false; \
        deque->rear = (deque->rear + 1) % deque->capacity; \
        deque->buffer[deque->rear] = value; \
        deque->size++; \
        return true; \
    } \
    \
    bool deque_##TYPE##pop_front(CircularDeque##TYPE* deque) { \
        if (!deque || deque_##TYPE##_is_empty(deque)) return false; \
        deque->front = (deque->front + 1) % deque->capacity; \
        deque->size--; \
        return true; \
    } \
    \
    bool deque_##TYPE##pop_back(CircularDeque##TYPE* deque) { \
        if (!deque || deque_##TYPE##_is_empty(deque)) return false; \
        deque->rear = (deque->rear == 0) ? deque->capacity - 1 : deque->rear - 1; \
        deque->size--; \
        return true; \
    } \
    \
    bool deque_##TYPE##front(const CircularDeque##TYPE* deque, TYPE* out) { \
        if (!deque || deque_##TYPE##_is_empty(deque) || !out) return false; \
        *out = deque->buffer[deque->front]; \
        return true; \
    } \
    \
    bool deque_##TYPE##back(const CircularDeque##TYPE* deque, TYPE* out) { \
        if (!deque || deque_##TYPE##_is_empty(deque) || !out) return false; \
        *out = deque->buffer[deque->rear]; \
        return true; \
    } \
    \
    void deque_##TYPE##print(const CircularDeque##TYPE* deque, void (*print_fn)(TYPE)) { \
        if (!deque || deque_##TYPE##_is_empty(deque)) return; \
        printf("["); \
        for (size_t i = 0; i < deque->size; ++i) { \
            size_t idx = (deque->front + i) % deque->capacity; \
            print_fn(deque->buffer[idx]); \
            if (i < deque->size - 1) printf(", "); \
        } \
        printf("]\n"); \
    }
