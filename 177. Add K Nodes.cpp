// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118786/offering/1381203

/*
    Time Complexity : O(L)
    Space Complexity : O(L / K)

    where 'L' is the number of nodes in the Linked List
    and 'K' is the given integer.
*/

Node *getListAfterAddingNodes(Node *head, int k)
{
    if (head == NULL)
	{
        return head;
    }

    Node *cur = head;
    int curSum = 0, nodesTraversed = 0;

    while (cur->next != NULL)
	{
        curSum += cur->data;
        nodesTraversed++;

        // Add a node when 'k' nodes have been traversed.
        if (nodesTraversed == k)
		{
            Node *newNodeWithSum = new Node(curSum);
            newNodeWithSum->next = cur->next;
            cur->next = newNodeWithSum;
            curSum = 0;
            nodesTraversed = 0;
            cur = cur->next;
        }
        cur = cur->next;
    }

    // Handling last node seprately.   
    curSum += cur->data;
    Node *newNodeWithSum = new Node(curSum);
    cur->next = newNodeWithSum;

    return head;
}
