# Binary-Search-Tree-BST-
Binary Search Tree is a node-based binary tree data structure which has the following properties: The left subtree of a node contains only nodes with keys lesser than the node's key. The right subtree of a node contains only nodes with keys greater than the node's key.

# BST ADT

Data Items
The data items in a binary search tree are of generic type DT. Each data item has a key (of
generic type KF) that uniquely identifies the data item. Data items usually include additional
data. Objects of type KF must support the six basic relational operators. Objects of type DT must
provide a functional getKey() that returns a data item’s key.
Structure
The data items form a binary tree. For each data item D in the tree, all the data items in D’s left
subtree have keys that are less than D’s key and all the data items in D’s right subtree have keys
that are greater than D’s key.
Operations

## BSTree ()
Requirements:
None
Results:
Constructor. Creates an empty binary search tree..

## ~BSTree ()
Requirements:
None
Results:
Destructor. Deallocates (frees) the memory used to store a binary search tree.

## void insert ( const DT &newDataItem )
Requirements:
Binary search tree is not full.
Results:
Inserts newDataItem into a binary search tree. If a data item with the same key as newDataItem
already exists in the tree, then updates that data item’s nonkey fields with newDataItem’s nonkey
fields.

## bool retrieve ( KF searchKey, DT &searchDataItem )
Requirements:
None
Results:
Searches a binary search tree for the data item with key searchKey. If this data item is found,
then copies the data item to searchDataItem and returns true. Otherwise, returns false with
searchDataItem undefined.

## bool remove ( KF deleteKey )
Requirements:
None
Results:
Deletes the data item with key deleteKey from a binary search tree. If this data item is found,
then deletes it from the tree and returns true. Otherwise, returns false.

## bool isEmpty ()
Requirements:
None
Results:
Returns true if a binary search tree is empty. Otherwise, returns false.

## int getHeight()
Requirements:
Not Empty
Results:
If BST is not empty returns height of a binary search tree, otherwise return -1.
