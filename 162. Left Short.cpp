// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118786/offering/1381244?leftPanelTab=0

/*  
    Time Complexity : O(L)
    Space Complexity : O(1)
    
    Where 'L' is the number of nodes in the Linked-List.
*/

Node *getListAfterDeleteOperation(Node *head)
{
    if (head == NULL)
	{
        return NULL;
    }

    // Variable to keep track of the value of the last node deleted.
    int deletedValue = -1;
    Node *cur = head;

    while (cur->next != NULL)
	{

        if (cur->next->data < cur->data && deletedValue == -1)
		{
            deletedValue = cur->next->data;
            Node *temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        }

        else if (deletedValue != -1 && cur->next->data < deletedValue)
		{
            deletedValue = cur->next->data;
            Node *temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        }

        else
		{
            deletedValue = -1;
            cur = cur->next;
        }
    }
    return head;
}
