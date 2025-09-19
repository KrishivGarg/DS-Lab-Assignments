#only function : 
Node *getIntersectionNode(Node *headA, Node *headB)
{
    Node *temp1 = headA;
    Node *temp2 = headB;
    while (temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
        if (temp1 == temp2)
            return temp1;
        if (temp1 == NULL)
            temp1 = headB;
        if (temp2 == NULL)
            temp2 = headA;
    }
    return temp1;
}
