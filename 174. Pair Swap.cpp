// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118786/offering/1381201

/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where ‘N’ is the number of nodes in the singly linked list.
*/

Node* swap(Node* prev, Node* curr)
{
    prev->next = curr->next;
    curr->next = prev;
    return curr;
}

Node* pairsSwap(Node* head)
{
    //  Make a dummy node.
    Node* dummy = new Node(-1);

    dummy->next = head;

    Node* curr = dummy;

    //  Traverse in the list until we reach the end of the list or there is only one element left.
    while (curr->next != NULL && curr->next->next != NULL)
    {

        //  Swap the link of curr and curr->next.
        curr->next = swap(curr->next, curr->next->next);

        //  Go to next pair.
        curr = curr->next->next;
    }

    return dummy->next;
}
