# BSTvis

Binary search tree library and visualiser. *(School project)*


## Usage

When using the program, one binary search tree can be managed and viewed.

To add a value to the tree, enter **Insert mode (i)** and type the entry or entries you want to add to the tree.

To view the tree, enter **View mode (v)**. You will be notified if you haven't added anything to the tree yet, i.e. nothing can be printed.

To quit the program, enter **Quit mode (q)**.


## Visualising the tree

When visualising the tree (View mode), it is shown in a 2-dimensional format with ASCII decorations. An example can be seen below:
```
     12
     / \
    /   \
   0    43
  / \     \
-46  4    54
```

 > **Note**
 > If a value above INT_MAX is given, the value will overflow to INT_MIN when being displayed. As a general rule, keep to numbers with less than
 > 10 digits.
