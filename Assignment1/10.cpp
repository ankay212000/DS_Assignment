//Start is starting node of our original DLL.
nodetype *truncate(nodetype *start,int i)
{
    int cntr = 1;
    nodetype *ptr = start;
    while (cntr < i-1)
    {
        ptr = ptr->next;
        cntr++;
    }
    nodetype *temp=ptr->next;
    ptr->next=NULL; //Ending our original linked list after i-1 index.
    //Temp is starting of our DLL that contains the elements at indices i,i+1....n
    return temp;
}