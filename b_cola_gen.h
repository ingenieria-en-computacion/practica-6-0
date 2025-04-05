#define IMPLEMENT_DEQUE(TYPE) \
    Deque_##TYPE* deque_##TYPE##_create(void) { \
        Deque_##TYPE* deque = malloc(sizeof(Deque_##TYPE)); \
        if (!deque) return NULL; \
        deque->front = deque->back = NULL; \
        deque->length = 0; \
        return deque; \
    } \
    \
    void deque_##TYPE##destroy(Deque##TYPE* deque) { \
        if (!deque) return; \
        Node_##TYPE##_deque* current = deque->front; \
        while (current) { \
            Node_##TYPE##_deque* temp = current; \
            current = current->next; \
            free(temp); \
        } \
        free(deque); \
    } \
    \
    bool deque_##TYPE##push_front(Deque##TYPE* deque, TYPE data) { \
        if (!deque) return false; \
        Node_##TYPE##deque* node = malloc(sizeof(Node##TYPE##_deque)); \
        if (!node) return false; \
        node->data = data; \
        node->prev = NULL; \
        node->next = deque->front; \
        if (deque->front) deque->front->prev = node; \
        deque->front = node; \
        if (!deque->back) deque->back = node; \
        deque->length++; \
        return true; \
    } \
    \
    bool deque_##TYPE##push_back(Deque##TYPE* deque, TYPE data) { \
        if (!deque) return false; \
        Node_##TYPE##deque* node = malloc(sizeof(Node##TYPE##_deque)); \
        if (!node) return false; \
        node->data = data; \
        node->next = NULL; \
        node->prev = deque->back; \
        if (deque->back) deque->back->next = node; \
        deque->back = node; \
        if (!deque->front) deque->front = node; \
        deque->length++; \
        return true; \
    } \
    \
    bool deque_##TYPE##pop_front(Deque##TYPE* deque) { \
        if (!deque || !deque->front) return false; \
        Node_##TYPE##_deque* temp = deque->front; \
        deque->front = temp->next; \
        if (deque->front) deque->front->prev = NULL; \
        else deque->back = NULL; \
        free(temp); \
        deque->length--; \
        return true; \
    } \
    \
    bool deque_##TYPE##pop_back(Deque##TYPE* deque) { \
        if (!deque || !deque->back) return false; \
        Node_##TYPE##_deque* temp = deque->back; \
        deque->back = temp->prev; \
        if (deque->back) deque->back->next = NULL; \
        else deque->front = NULL; \
        free(temp); \
        deque->length--; \
        return true; \
    } \
    \
    bool deque_##TYPE##front(const Deque##TYPE* deque, TYPE* out) { \
        if (!deque || !deque->front || !out) return false; \
        *out = deque->front->data; \
        return true; \
    } \
    \
    bool deque_##TYPE##back(const Deque##TYPE* deque, TYPE* out) { \
        if (!deque || !deque->back || !out) return false; \
        *out = deque->back->data; \
        return true; \
    } \
    \
    size_t deque_##TYPE##length(const Deque##TYPE* deque) { \
        return deque ? deque->length : 0; \
    } \
    \
    bool deque_##TYPE##is_empty(const Deque##TYPE* deque) { \
        return deque ? deque->length == 0 : true; \
    } \
    \
    void deque_##TYPE##print(const Deque##TYPE* deque, void (*print_fn)(TYPE)) { \
        if (!deque || !print_fn) return; \
        Node_##TYPE##_deque* current = deque->front; \
        printf("["); \
        while (current) { \
            print_fn(current->data); \
            if (current->next) printf(", "); \
            current = current->next; \
        } \
        printf("]\n"); \
    }
