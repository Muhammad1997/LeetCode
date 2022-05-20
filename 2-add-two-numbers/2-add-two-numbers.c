/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* createNewNode(int value,struct ListNode* previousNode)
{
    struct ListNode * newNode = (struct ListNode *) malloc(sizeof(struct ListNode));
    previousNode->next = newNode;
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode * headNode = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode * newNode = headNode;
    int sum;
    int carry = 0;
    sum = l1->val + l2->val;
    carry = (sum > 9) ? (sum / 10): 0;
    newNode->val = sum%10;
    newNode->next = NULL;
    while(l1->next != NULL || l2->next != NULL)
    {
        if(l1->next != NULL)
        {
           l1 = l1->next; 
        }
        else
        {
            l1->val = 0;
        }
        if(l2->next != NULL)
        {
           l2 = l2->next; 
        }
        else
        {
            l2->val = 0;
        }
        sum = l1->val + l2->val + carry;
        carry = (sum > 9) ? (sum / 10): 0;
        newNode = createNewNode((sum%10),newNode);
    }
    if(carry != 0)
    {
        newNode = createNewNode(carry,newNode);
    }
    
    return headNode;
}