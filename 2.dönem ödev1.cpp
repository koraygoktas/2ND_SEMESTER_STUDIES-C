#include <stdio.h>
#include <stdlib.h>








// Tek bağlı liste düğüm yapısı
struct Node {
    int data;
    struct Node* next;
};

// Yeni bir düğüm oluşturup veriyi ekleyen fonksiyon
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Listeyi yazdıran fonksiyon
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int num;

    printf("Tek sayilari listenin basina, cift sayilari listenin sonuna ekleyin. Cikis icin -1 girin.\n");

    while (1) {
        printf("Bir sayi girin: ");
        scanf("%d", &num);

        if (num == -1) {
            break; // -1 girildi, çıkış yapılır.
        }

        struct Node* newNode = createNode(num);

        if (num % 2 == 1) {
            newNode->next = head; // Tek sayıları listenin başına ekler
            head = newNode;
        } else {
            if (head == NULL) {
                head = newNode;
            } else {
                struct Node* current = head;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = newNode; // Çift sayıları listenin sonuna ekler
            }
        }

        printf("Guncel Liste: ");
        printList(head);
    }

    printf("Son Liste: ");
    printList(head);

    // Belleği temizle
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
