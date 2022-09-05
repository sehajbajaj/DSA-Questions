BFS -> Will need a queue
1. We'll need extra time to process NULL
2. The root is connected to null. Push both in the queue initially.
3. Till the current node is not null (queue's front) keep connecting the next ptr to Q's front. Push it left and right child in the queue as well.
4. Make sure to oush a NULL after 1 level is traversed.
​
```
Node* connect(Node* root) {
if(root == NULL){
return NULL;
}
queue<Node*> q;
q.push(root);
q.push(NULL);
while(!q.empty()){
Node* curr = q.front();
q.pop();
//Connect the next pointer till curr node is not null
while(curr!=NULL){
curr->next = q.front();
q.pop();
//Push current nodes' children
if(curr->left){
q.push(curr->left);
}
if(curr->right){
q.push(curr->right);
}
//Update curr
curr = curr->next;
}
//Push NULL after every level
if(!q.empty()){
q.push(NULL);
}
}
return root;
}