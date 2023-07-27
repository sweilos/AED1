#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct DoublyLinkedList
{
    struct Node* first;
    struct Node* last;
};

struct DoublyLinkedList* createList()
{

    struct DoublyLinkedList* newList = (struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));
    if (newList)
    {
        newList->first = NULL;
        newList->last = NULL;
    }
    return newList;
}

void inserir_no_inicio(struct DoublyLinkedList* list, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode)
    {
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = list->first;

        if (list->first)
        {
            list->first->prev = newNode;
        }else
        {
            // Se a lista estiver vazia, o novo nó também será o último
            list->last = newNode;
        }
        list->first = newNode;
    }
}

void inserir_no_fim(struct DoublyLinkedList* list, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode)
    {
        newNode->data = data;
        newNode->prev = list->last;
        newNode->next = NULL;

        if (list->last)
        {
            list->last->next = newNode;
        } else
        {
            list->first = newNode;
        }
        list->last = newNode;
    }
}

void excluir_do_inicio(struct DoublyLinkedList* list)
{
    if (list->first)
    {
        struct Node* firstNode = list->first;
        list->first = firstNode->next;

        if (list->first)
        {
            list->first->prev = NULL;
        }else
        {
            list->last = NULL;
        }

        free(firstNode);
    }
}

void excluir_do_fim(struct DoublyLinkedList* list)
{
    if (list->last)
    {
        struct Node* lastNode = list->last;
        list->last = lastNode->prev;

        if (list->last)
        {
            list->last->next = NULL;
        }else
        {
            list->first = NULL;
        }

        free(lastNode);
    }
}

void imprimir(struct DoublyLinkedList* list)
{
    struct Node* currentNode = list->first;
    while (currentNode)
    {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int buscar(struct DoublyLinkedList* list, int value)
{
    struct Node* currentNode = list->first;
    while (currentNode)
    {
        if (currentNode->data == value)
        {
            return 1;
        }
        currentNode = currentNode->next;
    }
    return 0;
}

void liberar_lista(struct DoublyLinkedList* list)
{
    struct Node* currentNode = list->first;
    while (currentNode)
    {
        struct Node* nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
    free(list);
}

int main()
{
    struct DoublyLinkedList* lista = createList();

    inserir_no_inicio(lista, 5);
    inserir_no_inicio(lista, 3);
    inserir_no_fim(lista, 7);
    inserir_no_fim(lista, 9);

    imprimir(lista); // Saída esperada: 3 5 7 9

    excluir_do_inicio(lista);
    excluir_do_fim(lista);

    imprimir(lista); // Saída esperada: 5 7

    if (buscar(lista, 5))
    {
        printf("Valor encontrado na lista.\n");
    }else
    {
        printf("Valor não encontrado na lista.\n");
    }

    liberar_lista(lista);

    return 0;
}
