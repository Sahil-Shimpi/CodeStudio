// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118786/offering/1381244?leftPanelTab=2

/*
    Time Complexity: O(N + M)
    Space Complexity: O(K)

    Where 'N' and 'M' are the number of nodes in both lists respectively.
    Where 'K' = max('N', 'M').
*/

// Function to reverse the list.
Node<int> *reverseList(Node<int> *head) 
{
    Node<int> *prev = NULL, *curr = head, *nextNode;

    while (curr != NULL) 
	{
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

Node<int> *addTwoLists(Node<int> *first, Node<int> *second) 
{
    // Reverse both lists for simplicity.
    first = reverseList(first);
    second = reverseList(second);

    int carry = 0;

    // Creating a dummy list which will store the answer list.
    Node<int> *dummy = new Node<int>(-1);
    Node<int> *curr = dummy;

    // Create addition nodes in the answer list till one of the lists reaches end.
    while (first != NULL && second != NULL) 
	{
        int sum = (first->data + second->data + carry);
        Node<int> *digit = new Node<int>(sum % 10);
        carry = sum / 10;
        curr->next = digit;
        curr = curr->next;
        first = first->next;
        second = second->next;
    }

    // If the first list had not reached end, append its nodes to the answer list by keeping in mind the carry left.
    while (first != NULL) 
	{
        int sum = (first->data + carry);
        Node<int> *digit = new Node<int>(sum % 10);
        carry = sum / 10;
        curr->next = digit;
        curr = curr->next;
        first = first->next;
    }

    // If the second list had not reached end, append its nodes to the answer list by keeping in mind the carry left.
    while (second != NULL) 
	{
        int sum = (second->data + carry);
        Node<int> *digit = new Node<int>(sum % 10);
        carry = sum / 10;

        curr->next = digit;
        curr = curr->next;
        second = second->next;
    }

    // If some carry is left, append it at last.
    if (carry) 
	{
        Node<int> *digit = new Node<int>(carry);
        curr->next = digit;
    }

    // Reverse the list to get the final number.
    dummy = reverseList(dummy->next);

    // Return the answer list obtained after adding two lists.
    return dummy;
}
