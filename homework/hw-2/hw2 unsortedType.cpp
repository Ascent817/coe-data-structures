template <class ItemType>
UnsortedType<ItemType>::UnsortedType() {
  length = 0;
}

template <class ItemType>
void UnsortedType<ItemType>::MakeEmpty() {
  length = 0;
}

template <class ItemType>
bool UnsortedType<ItemType>::IsFull() const {
  return (length == MAX_ITEMS);
}

template <class ItemType>
int UnsortedType<ItemType>::LengthIs() const {
  return length;
}

template <class ItemType>
void UnsortedType<ItemType>::RetrieveItem(ItemType& item, bool& found)
// Pre: Key member(s) of item is initialized.
// Post: If found, item's key matches an element's key in the
// list and a copy of that element has been stored in item;
// otherwise, item is unchanged.
{
  bool moreToSearch;
  int location = 0;
  found = false;

  moreToSearch = (location < length);

  while (moreToSearch && !found) {
    if (item == info[location]) {
      found = true;
      item = info[location];
    } else {
      location++;
      moreToSearch = (location < length);
    }
  }
}

template <class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType item)
// Post: item is in the list.
{
  info[length] = item;
  length++;
}

template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item)
// Pre: item's key has been initialized.
// An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
  int location = 0;

  while (item != info[location])
    location++;

  info[location] = info[length - 1];
  length--;
}

template <class ItemType>
void UnsortedType<ItemType>::ResetList()
// Post: currentPos has been initialized.
{
  currentPos = 0;
}

template <class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType& item)
// Returns the next element in list.
// Pre:  Current position is defined.
// Post: item is a copy of the element at the current position.
//       After returning the current item, current position is updated
//       to the next position.
{
  item = info[currentPos];
  currentPos++;
}

template <class ItemType>
bool UnsortedType<ItemType>::AtEnd()
// Returns true if currentPos is at end of list.
// Pre:  Current position is defined.
{
  return currentPos == length;
}

template <class ItemType>
void UnsortedType<ItemType>::Print(ostream& out)
// Prints items in the list from beginning to end.
// Items are printed on a single line of output with one space between each item.
// Terminates the line with endl.
// Pre: List has been initialized.
// Post: List is unchanged.
{
  ResetList();
  ItemType item;
  for (int i = 0; i < length; i++) {
    GetNextItem(item);
    out << item << " ";
  }
  out << endl;
}

template <class ItemType>
UnsortedType<ItemType> UnsortedType<ItemType>::Merge(UnsortedType list2)
// Merges two unsorted lists (list and list2) into a third unsorted list.
// Pre: Lists have been initialized.
//      list and list2 are different lists.
//      Merged list does not exceed the maximum size for a list.
// Post: Function value = list that contains all of the items from list and list2.
//       list and list2 are unchanged.
{
  // Terminate program if list length exceeds maximum size
  if (length + list2.length > MAX_ITEMS) {
    throw "Merge exceeds maximum size limit";
    exit(1);
  }

  // Create a third list, add all elements from list and list2 to it, and return it
  UnsortedType<ItemType> mergedList;
  ItemType item;

  ResetList();
  for (int i = 0; i < length; i++) {
    GetNextItem(item);
    mergedList.InsertItem(item);
  }

  list2.ResetList();
  for (int i = 0; i < list2.length; i++) {
    list2.GetNextItem(item);
    mergedList.InsertItem(item);
  }

  return mergedList;
}

template <class ItemType>
void UnsortedType<ItemType>::Split(ItemType item, UnsortedType& list1, UnsortedType& list2)
// Divides list into two lists (list1 and list2) according to the key of item.
// Pre: List has been initialized and is not empty.
//      List, list1, and list2 are different lists.
// Post: list1 contains all of the items of list whose keys are less than or equal to item�s key.
//       These will be the only items in list1.
//       list2 contains all of the items of list whose keys are greater than item�s key.
//       These will be the only items in list2.
//       List is empty.
{
  int key = RetreiveKey(item);
  ItemType tempItem;

  ResetList();

  for (int = 0; i < length; i++) {
    GetNextItem(tempItem);
    if (i <= key) {
      list1.InsertItem(tempItem);
    } else {
      list2.InsertItem(tempItem);
    }
  }

  MakeEmpty();
  return;
}