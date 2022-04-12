// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118786/offering/1381207?leftPanelTab=0

/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where N is the number of nodes in the Linked List.
*/

Node<int>* deleteMiddle(Node<int>* head)
{

    // Base Cases.
    if(head == NULL || head -> next == NULL)
    {
        if(head != NULL)
        {
            delete head;
        }
        return NULL;
    }

    // Slow will end on middle node.
    Node<int>* slow = head, *fast = head -> next;

    // Pointer to previous node of slow pointer.
    Node<int>* prevSlow = NULL;

    while(fast != NULL)
    {

        // If nodes are even, break.
        if(fast -> next == NULL)
        {
            break;
        }

        prevSlow = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    // If head is the middle node.
    if(prevSlow == NULL)
    {
        Node<int>* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;

        return head;
    }

    // Delete middle node.
    prevSlow -> next = prevSlow -> next -> next;
    slow -> next = NULL;
    delete slow;

    return head;
}
