// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118786/offering/1381238

/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    Where N is number of nodes in the linked list.
*/

Node* sortList(Node *head)
{
    Node *ptr = head;
    int cnt[3] = {};

    // Iterate while ptr is not empty
    while(ptr)
    {
        cnt[ptr->data]++;
        ptr = ptr->next;
    }

    ptr = head;
    int i=0;

    // Updating data.
    while(ptr)
    {
        while(cnt[i] == 0)
        {
            i++;
        }

        ptr->data = i;
        cnt[i]--;
        ptr = ptr->next;
    }

    // Return head
    return head;
}
