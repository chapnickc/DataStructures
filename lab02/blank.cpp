Link<E>* nextLink = new Link<E>;
Link<E>* prevLink = NULL;

moveToStart();
curr = head->next();
tail = curr;


while (nextLink != NULL){
  nextLink = curr->next;
  curr->next = prevLink;
  prevLink = curr;
  curr = nextLink;
}
head->next = prevLink;
delete nextLink;
