#include <stdio.h>
#include <stdlib.h>


// Tek bağlı liste düğüm yapısı
struct Node {
    int data;
    struct Node* next;
};

// Yeni bir düğüm oluşturup veri ekler
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Bellek yetersiz! Dugum oluşturulamadı.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Listeye eleman ekler
void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL || data > (*head)->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL && current->next->data > data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Liste içeriğini yazdırır
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    printf("Lütfen 5 tamsayi değeri giriniz:\n");
    for (int i = 0; i < 5; i++) {
        int value;
        scanf("%d", &value);
        insert(&head, value);
    }

    printf("Sirali liste: ");
    printList(head);

    return 0;
}
