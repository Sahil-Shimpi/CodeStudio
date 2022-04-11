// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118786/offering/1381233

/*
	Time Complexity : O(N^2)
	Space Complexity : O(1)

	where 'N' is the number of nodes in the list
*/

// Function to insert an element at its correct position in sorted order.
void sortedInsert(Node **head, Node *newnode)
{

    Node *current;

    if (*head == NULL || ((*head)->data >= newnode->data))
    {
        newnode->next = *head;
        *head = newnode;
    }
    
    else
    {
        current = *head;
        while (current->next and current->next->data < newnode->data)
        {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}

Node *insertionSortLL(Node *head)
{

    // To store the final sorted list
    Node *sorted = NULL;

    // Current pointer, to iterate over the entire list
    Node *current = head;

    /* 
	This loops takes each element in the loop and calls sortedInsert function for it, 
	to insert it at its correct position in the final list
	*/
    while (current)
    {
        Node *next = current->next;
        sortedInsert(&sorted, current);
        current = next;
    }

    return sorted;
}

