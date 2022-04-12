// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118786/offering/1381235

/*
    Time Complexity: O(N)
    Space complexity: O(1)
    
    Where N is the number of nodes in the linked list.
*/

Node *sortLL(Node *head)
{
    Node *cur = head->next, *prev = head;
    
    while (cur != NULL)
    {
        // If node has a negative value.
        if (cur->data < 0)
        {
            prev->next = cur->next;
            cur->next = head;
            head = cur;
            cur = prev;
        }
        prev = cur;
        cur = cur->next;
    }
    return head;
}
