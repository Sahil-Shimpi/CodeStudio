// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118786/offering/1381209

/*
    Time Complexity: O(N)
    Space Compexity: O(1)

    Where 'N' is the total nodes in Linked List.
*/

LinkedListNode<int> *removeKthNode(LinkedListNode<int> *head, int K)
{
    if (head == NULL || K == 0)
    {
        return head;
    }

    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;

    for (int i = 0; i < K; i++)
    {
        // If head is the Kth node from end of Linked List.
        if (fast->next == NULL) {
            LinkedListNode<int> *next = head->next;
            head->next = NULL;
            head = next;

            return head;
        }
        else
        {
            fast = fast->next;
        }
    }

    // Moving both slow and fast pointer with same speed.
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // Removing the Kth node from end of Linked List.
    slow->next = slow->next->next;

    return head;
}
