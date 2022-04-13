// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118786/offering/1381209?leftPanelTab=1

Node *addTwoLinkedList(Node *head1, Node *head2)
{
    Node *prev = NULL;
    int carry = 0;

    while (head1 != NULL || head2 != NULL)
    {
        int sum = carry + head1->data;
        if (head2 != NULL)
        {
            sum += head2->data;
        }

        if (sum > 9)
        {
            sum -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }

        head1->data = sum;
        Node *temp = head1->next;
        head1->next = prev;
        prev = head1;
        head1 = temp;

        if (head2 != NULL)
        {
            head2 = head2->next;
        }
    }

    if (carry == 1)
    {
        head1 = new Node(1);
        head1->next = prev;
    }
    else
    {
        head1 = prev;
    }

    return head1;
}

Node* addFirstAndReversedSecondHalf(Node* head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *prev = NULL;

    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;

        Node *temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }

    if (fast != NULL)
    {
        Node *temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }

    // Now slow will point to the head for second list.
    Node *head1 = prev;
    Node *sumHead = addTwoLinkedList(head1, slow);

    while (sumHead != NULL && sumHead->data == 0)
    {
        sumHead = sumHead->next;
    }

    // If all digits in the sum string are zero, return only "0".
    if (sumHead == NULL)
    {
        return new Node(0);
    }

    return sumHead;
}
