// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118786/offering/1381252?leftPanelTab=0

/*
    Time Complexity - O(N)
    Space Complexity - O(1)

    where 'N' is the number of nodes in the Linked List.
*/


Node<int>* reverseList(Node<int>* head)
{
    Node<int> *prev = NULL, *curr = head, *next;

    while (curr != NULL)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

Node<int>* getMiddle(Node<int>* head)
{
    Node<int> *slow = head, *fast = head;

    while (fast != NULL && fast -> next != NULL)
    {
        fast = fast -> next -> next;
        if (fast == NULL)
        {
            break;
        }
        slow = slow -> next;
    }

    return slow;
}


Node<int>* rearrangeList(Node<int>* head)
{
    if (head == NULL || head -> next == NULL)
    {
        return head;
    }

    // Split the linked list in two halves.
    Node<int>* middle = getMiddle(head);

    Node<int>* head1 = head;
    Node<int>* head2 = middle -> next;
    middle -> next = NULL;

    // Reverse second half.
    head2 = reverseList(head2);

    Node<int>* curr = new Node<int>(-1);
    head = curr;

    while (head1 != NULL || head2 != NULL)
    {
        if (head1 != NULL)
        {
            curr -> next = head1;
            curr = curr -> next;
            head1 = head1 -> next;
        }

        if (head2 != NULL)
        {
            curr -> next = head2;
            curr = curr -> next;
            head2 = head2 -> next;
        }
    }

    // Remove dummy node.
    curr = head;
    head = head -> next;
    curr -> next = NULL;
    delete curr;

    return head;
}
