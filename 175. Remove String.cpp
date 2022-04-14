// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118786/offering/1381202

/*

    Time Complexity :  O(N * K) 
    Space Complexity : O(1) 
     
    Where 'N' is the total length of linked list.
    Where 'K' is the length of the string.

*/

Node *removeStr(Node *head, string str)
{
    // If string is empty, then the linked list is our ans just return the head of linked list.
    if (str == "")
	{
        return head;
    }

    // If head is null, just return the null pointer indicating our linkedlist is empty.
    if (head == NULL)
	{
        return NULL;
    }

    // Pass recursive call to the next pointer of linkedlist to go to the end.
    head->next = removeStr(head->next, str);

    // Backtracking part: as it is given to check from the back of linked list.
    Node *temp = head;

    // Check the corresponding string in the linked list.
    int pos = 1;

    /* 
        Condition 1: (temp!=NULL) means while checking the occurence of string in linkedlist our linkedlist not break or null.
        Condition 2: (pos<=str.length()) means search the occurence of each char of string in linkedlist using pointer approach.
        Condition 3: (str[pos-1]==temp->data ) means that the curr data in pointed linked list is equal to the char of string.
    */
    while (temp != NULL && pos <= str.length() && str[pos - 1] == temp->data)
	{
        // Increase the position of index in string by one.
        pos++;     
        // Increase the current pointer temp position to next of it and so on.        
        temp = temp->next; 
    }

    // If pos= str.size + 1, then return the current pointer temp, else return the intial head.
    return (pos == str.length() + 1) ? temp : head;
}
