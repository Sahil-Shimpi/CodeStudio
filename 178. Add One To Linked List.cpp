// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118786/offering/1381204

/*
    Time Complexity : O(N)
    Space complexity: O(1)
    
    Where 'N' is the number of nodes in the list.

*/

Node *reverse(Node *head)
{

    // If the list is empty or has just one node, return head.
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // Pointer to the previous node of the current node.
    Node *prev = NULL;

    // Pointer to the current node.
    Node *curr = head;

    while (curr != NULL)
    {

        // Pointer to the next node of the current node.
        Node *ahead = curr->next;

        // Inverting the links
        curr->next = prev;
        prev = curr;
        curr = ahead;
    }

    return prev;
}

Node *addOne(Node *head)
{

    // Removing leading zeroes.
    while (head != NULL && head->data == 0)
    {
        head = head->next;
    }

    // Reverse the list.
    head = reverse(head);

    Node *temp = head;

    // Initialize a variable to store carry.
    int carry = 1;

    // Initialize a pointer to store previous node.
    Node *prev = head;

    // Adding 1 to the reversed linked list
    while (head != NULL)
    {
        int sum = carry + head->data;
        carry = sum / 10;
        sum = sum % 10;
        head->data = sum;
        prev = head;
        head = head->next;
    }

    // If there is carry after processing all nodes, add a new node at the end of the linked list.
    if (carry != 0)
    {

        Node *newNode = new Node(0);
        newNode->data = carry;

        // Appending the newNode at the end of the resultant list.
        if (prev != NULL)
        {
            prev->next = newNode;
        }

        else
        {
            // If the resultant list is empty
            return newNode;
        }
    }

    // Reverse the resultant list.
    Node *ans = reverse(temp);

    return ans;
}

