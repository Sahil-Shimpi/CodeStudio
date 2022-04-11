// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118786/offering/1381230

/*
    Time Complexity: O(L ^ 2)
    Space complexity: O(L)
    
    Where 'L' is the number of nodes in the linked list.
*/

// Returns the last node of the list.
Node *getTail(Node *cur)
{
    while (cur != NULL && cur->next != NULL)
    {
        cur = cur->next;
    }
    return cur;
}

Node *partition(Node *head, Node *tail, Node **newHead, Node **newTail)
{
    Node *pivot = tail;
    Node *prev = NULL, *cur = head;

    while (cur != pivot)
    {

        // Keep it at its current position.
        if (cur->data < pivot->data)
        {
            if ((*newHead) == NULL)
            {
                (*newHead) = cur;
            }

            prev = cur;
            cur = cur->next;
        }

        // Move it after tail.
        else
        {
            if (prev != NULL)
            {
                prev->next = cur->next;
            }
            Node *temp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }

    if ((*newHead) == NULL)
    {
        (*newHead) = pivot;
    }

    (*newTail) = tail;

    return pivot;
}

Node *quickSortHelper(Node *head, Node *tail)
{

    // Base condition.
    if (!head || head == tail)
    {
        return head;
    }

    Node *newHead = NULL, *newTail = NULL;

    Node *pivot = partition(head, tail, &newHead, &newTail);

    // If pivot is head then we dont have left part.
    if (newHead != pivot)
    {
        Node *temp = newHead;
        while (temp->next != pivot)
        {
            temp = temp->next;
        }
        temp->next = NULL;

        newHead = quickSortHelper(newHead, temp);

        temp = getTail(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSortHelper(pivot->next, newTail);

    return newHead;
}

Node *quickSortLL(Node *head)
{
    Node *tail = getTail(head);
    head = quickSortHelper(head, tail);
    return head;
}
