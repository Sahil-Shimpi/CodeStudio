// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118786/offering/1381242

/*
    Time Complexity : O(N)
    Space Complexity : O(N)

    Where ‘N’ is the number of nodes in the singly linked list.
*/

#include <unordered_set>

Node *reverseList(Node *head)
{
    Node *prev = NULL, *nextNode = NULL;
    while (head != NULL)
    {
        //  Hold the next node.
        nextNode = head->next;

        //  Point back.
        head->next = prev;

        //  Move forward.
        prev = head;

        //  Go for next node.
        head = nextNode;
    }
    return prev;
}

Node *lastAppearance(Node *head)
{
    //  Make a dummy node.
    Node *dummy = new Node(-1);
    dummy->next = head;

    //  First we need to reverse the given linked list.
    dummy->next = reverseList(dummy->next);

    //  Used to store that weather a data is already visited or not.
    unordered_set<int> visited;

    Node *currNode = dummy, *nextNode;

    //  Iterate over list
    while (currNode != NULL && currNode->next != NULL)
    {
        nextNode = currNode->next;

        //  Check if data of the next node of the current node is already visited or not.
        if (visited.count(nextNode->data) != 0)
        {
            //  Save duplicate pointer.
            Node *duplicate = nextNode;
            currNode->next = nextNode->next;

            //  Erase memory of duplicate.
            delete duplicate;
        }
        else
        {
            //  Mark as visited to data of nextNode.
            visited.insert(nextNode->data);

            //  Go for the next node.
            currNode = nextNode;
        }
    }

    //  Again reverse modified list.
    dummy->next = reverseList(dummy->next);

    return dummy->next;
}
