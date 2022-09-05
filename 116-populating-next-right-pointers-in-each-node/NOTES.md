}else{
nxt = NULL;
}
while(curr and nxt){
//1. Left child of curr to be connected with right child of curr
curr->left->next = curr->right;
//2. If there is a node existing on curr's next
if(curr->next){
curr->right->next = curr->next->left;
}
//3. Update curr
curr = curr->next;
//If curr becomes NULL means there's nothing on the next right
//Shift curr to next level and nxt to its left.
if(!curr){
curr = nxt;
nxt = curr->left;
}
}
return root;
}
```